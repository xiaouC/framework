Pod::Spec.new do |s|
  s.platform = :ios, '7.0'
  s.name     = 'ZHPaySDK'
  s.version  = '1.3.8'
  s.summary  = '海马'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  s.homepage     = "http://haima.me/"
  s.license = { :type => 'CC', :text => 'Copyright http://haima.me/'}
  s.public_header_files = '**/*.h'
  s.framework = 'CoreTelephony', 'CoreGraphics', 'SystemConfiguration', 'Security', 'UIKit', 'Foundation', 'IOKit'
  s.weak_framework = 'AdSupport'
  s.vendored_framework = 'ZHPay.framework', 'ZHPayDependence/AliPay/AlipaySDK.framework'
  s.preserve_paths = '**/*'
  s.vendored_libraries = '*.a', 'ZHPayDependence/UnionPay/*.a', 'ZHPayDependence/WeChat/*.a'
  s.source_files = '*.m'
  s.libraries = 'stdc++', 'z', 'sqlite3'
  s.resources = 'ZHPayBundle.bundle', 'ZHPayDependence/AliPay/AlipaySDK.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
