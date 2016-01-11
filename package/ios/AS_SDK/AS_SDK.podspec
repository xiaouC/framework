Pod::Spec.new do |s|
  s.platform = :ios, '5.0'
  s.name     = 'AS_SDK'
  s.version  = '2.1.0'
  s.summary  = '爱思 SDK'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  s.homepage     = "http://dev.i4.cn"
  s.license = { :type => 'CC', :text => 'Copyright http://dev.i4.cn'}
  s.public_header_files = '**/*.h'
  s.framework = 'AudioToolbox', 'AdSupport', 'CoreGraphics', 'SystemConfiguration', 'Security', 'QuartzCore', 'UIKit', 'Foundation', 'CFNetwork', 'MediaPlayer', 'AVFoundation'
  s.weak_framework = 'AdSupport'
  s.vendored_framework = 'AsSdkFMWK.framework'
  s.preserve_paths = '**/*'
  s.vendored_libraries = '*.a'
  s.source_files = '**.{h,m,mm}'
  s.libraries = 'MobileGestalt'
  s.resources = 'AlipaySDK.bundle', 'AsImage.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
