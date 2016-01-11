require 'rubygems'
require 'plist'
require 'xcodeproj'
require 'logger'
require 'fileutils'

class Hash
  def pretty_print
    max_key_length = keys.map(&:length).max
    each { |key, value| puts " * \033[01;31m#{key.to_s.ljust(max_key_length)}\033[00m => \033[01;33m#{value}\033[00m" }
  end
end

def write_info_plist(info_plist, payload, reject=[])
    info = Plist::parse_xml(info_plist)
    !ENV['GAME_ENV'].nil? and payload[:GAME_ENV] = ENV['GAME_ENV']
    payload.pretty_print
    info.update(payload)
    reject.each { |k| info.delete(k) }
    Plist::Emit.save_plist(info, info_plist)
end

def ensure_no_devices_connected
  return if ENV.include?('DRY_RUN')
  devices = `system_profiler SPUSBDataType | sed -n -e '/iPhone/p;/iPad/p;/iPod/p'`.split
  cmd = 'say --interactive=bold/red -v Vicki "Please disconnect any iOS devices"'
  system(cmd) && exit(1) if devices.size > 0
end

module Yunyue
  class Build
    def initialize
      @logger = Logger.new($stdout)
      @params = {}
      @infoplist_file = nil
      @porj_dir = nil
      @info = nil
      @build_settings = nil
      @workspace = nil
      @configuration = 'Release'
      @archive_fmt = '%{bundle_id}_v%{version}.ipa'
      @no_clean = false
    end

    def workspace(path)
      @params[:workspace] = path
      @logger.info("workspace path: `#{path}'")
      @workspace = Xcodeproj::Workspace.new_from_xcworkspace(path)
    end

    def configuration(name)
      @configuration = name
    end

    def scheme(name)
      @params[:scheme] = name
      proj_path = @workspace.schemes[name]
      @logger.info("project path: `#{proj_path}'")
      proj = Xcodeproj::Project.open(proj_path)
      native_target = proj.targets.find { |item| item.to_s == name }
      @logger.info("native target: `#{native_target}'")
      @build_settings = native_target.build_settings(@configuration)
      infoplist_file = @build_settings['INFOPLIST_FILE']
      @proj_dir = File.dirname(proj_path)
      @infoplist_file = File.absolute_path(infoplist_file.gsub('$(SRCROOT)', @proj_dir))
      @infoplist_file = File.join(@porj_dir, infoplist_file) unless infoplist_file.start_with?('$(SRCROOT)')
      ENV['INFOPLIST_FILE'] = @infoplist_file
      @logger.info("Info.plist: #{@infoplist_file}")
      @info = Plist::parse_xml(@infoplist_file)
    end

    def code_sign_identity(identity = nil)
      if !identity
        output = `security find-identity -p codesigning -v`
        valid_identities = {}
        output.split("\n")[0..-2].each do |line|
          parts = line.delete('"').split
          valid_identities[parts[0][0..-2]] = parts[2..-1].join(' ')
        end
        puts output
        3.times do
          print "CODE_SIGN_IDENTITY: "
          $stdout.flush
          idx = $stdin.gets.chomp
          identity = valid_identities.fetch(idx, nil)
          break if identity
        end
      end
      raise "No CODE_SIGN_IDENTITY specified" unless identity
      @params[:code_sign_identity] = identity.delete('"')
    end

    def version(version)
      @params[:version] = version
      @info['CFBundleVersion'] = @info['CFBundleShortVersionString'] = @params[:version]
      @logger.info("\033[01;33mCFBundleVersion\033[00m: #{@info['CFBundleVersion']}")
      @logger.info("\033[01;33mCFBundleShortVersionString\033[00m: #{@info['CFBundleShortVersionString']}")
    end

    def no_clean
      @no_clean = true
    end

    def archive_dir(dir)
      @params[:archive_dir] = File.absolute_path(dir)
    end

    def archive_name(fmt)
      @archive_fmt = fmt
    end

    def metadata(&block)
      block.call(@info)
    end

    def run
      ensure_no_devices_connected

      # write Info.plist
      Plist::Emit.save_plist(@info, @infoplist_file)
      @logger.info(@params)

      # assets
      raise "Copy assets failed" unless system("python copyassets.py #{@proj_dir.split(File::SEPARATOR).last}") unless ENV.include?('NO_COPY')

      # pod install
      Dir.chdir(@proj_dir) do
        if File.exist?(File.join(@proj_dir, 'Podfile'))
          raise "Pod install failed" unless system('pod install --no-repo-update') unless ENV.include?('NO_POD_INSTALL')
        end
      end

      # build
      build_dir = File.join(@proj_dir, 'build')
      build_cmd = ["xcodebuild -workspace #{@params[:workspace]} -scheme #{@params[:scheme]}"]
      build_cmd << "-configuration #{@configuration}"
      build_cmd << "clean" unless (@no_clean || ENV.include?('NO_CLEAN'))
      build_cmd << "build CONFIGURATION_BUILD_DIR=#{build_dir}"
      build_cmd << "CODE_SIGN_IDENTITY=\"#{@params[:code_sign_identity]}\"" if @params.include?(:code_sign_identity)

      cmd = build_cmd.join(' ')
      @logger.info("`#{cmd}'")
      raise "Build failed" unless system(cmd) unless ENV.include?('DRY_RUN')

      # archive
      archive_dir = File.join(File.absolute_path(@params.fetch(:archive_dir, "#{ENV['HOME']}/ios_package")), @params[:version])
      archive_dir = File.join(archive_dir, @params[:code_sign_identity].gsub(' ', '_')) if @params.include?(:code_sign_identity)
      FileUtils.mkdir_p(archive_dir) unless Dir.exists?(archive_dir)

      context = {bundle_id: @info['CFBundleIdentifier'], name: @info['CFBundleDisplayName']}
      context.update(@params)
      @logger.info(context)
      output_name = File.join(archive_dir, @archive_fmt % context)
      archive_cmd = ["/usr/bin/xcrun -sdk iphoneos PackageApplication"]
      archive_cmd << "-v #{build_dir}/#{@build_settings['PRODUCT_NAME']}.app -o '#{output_name}'"
      cmd = archive_cmd.join(' ')
      @logger.info("`#{cmd}'")
      raise "Archive failed" unless system(cmd) unless ENV.include?('DRY_RUN')
    end
  end

  def self.build(&block)
    b = Build.new
    b.instance_eval(&block)
    b.run
  end
end
