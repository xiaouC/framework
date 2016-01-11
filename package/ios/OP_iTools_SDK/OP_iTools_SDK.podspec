Pod::Spec.new do |s| 
  s.platform = :ios, '5.0'
  s.name     = 'OP_iTools_SDK'
  s.version  = '2.0.4'
  s.summary  = 'Ourpalm iTools iOS SDK'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  # s.source   = { :git => 'git@192.168.0.252:ratazzi/OP_iTools_SDK.git', :tag => 'v2.0.4' }
  s.homepage     = "http://www.itools.cn"
  s.license = { :type => 'CC', :text => 'Copyright http://www.itools.cn'}
  s.public_header_files = '**/*.h'
  s.framework = 'CoreGraphics', 'Security', 'SystemConfiguration', 'Foundation', 'UIKit', 'MobileCoreServices', 'CFNetwork', 'QuartzCore'
  s.weak_framework = 'AdSupport'
  s.libraries = 'c++', 'z'
  s.preserve_paths = '**/*'
  s.vendored_libraries = 'iToolsSDK/libHXAppPlatformKitPro.a', 'libOurpalmSDK_iTools.a'
  s.resources = 'Resource/ourpalm_res.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
