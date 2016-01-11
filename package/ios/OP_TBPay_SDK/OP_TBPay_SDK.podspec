Pod::Spec.new do |s| 
  s.platform = :ios, '5.0'
  s.name     = 'OP_TBPay_SDK'
  s.version  = '2.1.4'
  s.summary  = 'Ourpalm TBPay iOS SDK'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  # s.source   = { :git => 'git@192.168.0.252:ratazzi/OP_TBPay_SDK.git', :tag => 'v2.1.4' }
  s.homepage     = "http://www.tongbu.com/"
  s.license = { :type => 'CC', :text => 'Copyright http://www.tongbu.com/'}
  s.public_header_files = '**/*.h'
  s.framework = 'CoreGraphics', 'Security', 'SystemConfiguration', 'Foundation', 'UIKit', 'QuartzCore', 'MessageUI'
  s.weak_framework = 'AdSupport'
  s.vendored_framework = 'TBPlatform/TBPlatform.framework'
  s.libraries = 'c++', 'z'
  s.preserve_paths = '**/*'
  s.vendored_libraries = 'iToolsSDK/libHXAppPlatformKitPro.a', 'libOurpalmSDK_TB.a'
  s.resources = 'Resource/ourpalm_res.bundle', 'TBPlatform/TBPlatformResource.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
