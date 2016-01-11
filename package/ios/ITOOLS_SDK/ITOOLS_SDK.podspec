Pod::Spec.new do |s|
  s.platform = :ios, '5.0'
  s.name     = 'ITOOLS_SDK'
  s.version  = '2.5.1'
  s.summary  = 'iTools SDK'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  s.homepage     = "http://itools.cn"
  s.license = { :type => 'CC', :text => 'Copyright http://itools.cn'}
  s.public_header_files = '**/*.h'
  s.framework = 'AdSupport', 'CoreGraphics', 'SystemConfiguration', 'Security', 'QuartzCore', 'UIKit', 'Foundation', 'CFNetwork', 'CoreTelephony'
  s.weak_framework = 'AdSupport'
  s.vendored_framework = 'AlipaySDK.framework'
  s.preserve_paths = '**/*'
  s.vendored_libraries = '*.a'
  s.source_files = '**.{h,m,mm}'
  s.libraries = 'sqlite3', 'iconv', 'z'
  s.resources = 'AlipaySDK.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
