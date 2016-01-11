Pod::Spec.new do |s| 
  s.platform = :ios, '6.0'
  s.name     = 'TB_SDK'
  s.version  = '4.1.0'
  s.summary  = '同步推sdk'
  s.authors  = { 'liupeng' => 'pengliu@yunyuegame.com' }
  s.homepage     = "http://www.tongbu.com/"
  s.license = { :type => 'CC', :text => 'Copyright http://www.tongbu.com/'}
  s.public_header_files = '*/*.h'
  s.framework = 'CoreLocation', 'QuartzCore', 'SystemConfiguration', 'MessageUI', 'Security', 'CoreText', 'MobileCoreServices', 'CoreData', 'CFNetwork'
  s.weak_framework = 'AdSupport'
  s.vendored_framework = 'TBPlatform.framework'
  s.libraries = 'c++', 'z', 'xml2'
  s.preserve_paths = '*'
  s.resource = 'TBPlatformResource.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
