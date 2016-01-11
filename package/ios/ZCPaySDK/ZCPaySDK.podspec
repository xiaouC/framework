Pod::Spec.new do |s|
  s.platform = :ios, '5.0'
  s.name     = 'ZCPaySDK'
  s.version  = '1.0.0'
  s.summary  = 'ZCPaySDK'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  # s.source   = { :git => 'git@192.168.0.252:ratazzi/ZCGameSDK.git', :tag => 'v1.0.0' }
  s.homepage     = "http://www.zcgames.cn"
  s.license = { :type => 'CC', :text => 'Copyright http://www.zcgames.cn'}
  s.public_header_files = '*.h'
  s.framework = 'SystemConfiguration', 'CoreGraphics', 'QuartzCore', 'CoreText'
  s.weak_framework = 'CoreTelephony', 'AdSupport'
  s.preserve_paths = '**/*'
  s.vendored_libraries = 'libZCPay.a', 'libcrypto.a', 'libssl.a'
  s.vendored_framework = 'AlipaySDK.framework'
  s.libraries = 'z'
  s.resource = 'AlipaySDK.bundle'

  s.requires_arc = false
end

# vim: set ft=ruby:
