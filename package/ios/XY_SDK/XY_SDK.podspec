Pod::Spec.new do |s|
  s.platform = :ios, '5.0'
  s.name     = 'XY_SDK'
  s.version  = '2.1.0'
  s.summary  = 'XY iOS SDK'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  # s.source   = { :git => 'git@192.168.0.252:ratazzi/XY_SDK.git', :tag => 'v1.3.1.0' }
  s.homepage     = "http://www.xyzs.com/"
  s.license = { :type => 'CC', :text => 'Copyright http://www.xyzs.com/'}
  s.public_header_files = '**/*.h'
  s.frameworks = 'Security', 'SystemConfiguration', 'Foundation', 'QuartzCore', 'MobileCoreServices', 'CoreText', 'CoreTelephony'
  s.weak_framework = 'AdSupport'
  s.vendored_frameworks = 'XYPlatform.framework'
  s.libraries = 'c++', 'z', 'sqlite3'
  s.preserve_paths = '**/*'
  s.resources = 'XYPlatformResources.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
