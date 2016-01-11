Pod::Spec.new do |s|
  s.platform = :ios, '6.0'
  s.name     = 'XX_SDK'
  s.version  = '2.1.0'
  s.summary  = '爱思 SDK'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  s.homepage     = "http://open.guopan.cn"
  s.license = { :type => 'CC', :text => 'Copyright http://open.guopan.cn'}
  s.public_header_files = '**/*.h'
  s.framework = 'AudioToolbox', 'AdSupport', 'CoreGraphics', 'SystemConfiguration', 'Security', 'QuartzCore', 'UIKit', 'Foundation', 'CFNetwork', 'MediaPlayer', 'AVFoundation', 'AssetsLibrary', 'CoreLocation', 'CoreTelephony', 'CoreGraphics'
  s.weak_framework = 'AdSupport'
  s.vendored_framework = 'AlipaySDK.framework'
  s.preserve_paths = '**/*'
  # s.vendored_libraries = 'libGPGameSDK.a', 'libssl.a'
  s.vendored_libraries = '*.a'
  s.source_files = '**.{h,m,mm}'
  s.libraries = 'z', 'c++'
  s.resources = 'AlipaySDK.bundle', 'ipaynow.bundle', 'walletResources.bundle', 'GPGameResource.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
