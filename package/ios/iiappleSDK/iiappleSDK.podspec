Pod::Spec.new do |s|
  s.platform = :ios, '5.0'
  s.name     = 'iiappleSDK'
  s.version  = '1.2.9'
  s.summary  = '爱苹果'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  s.homepage     = "http://dev.i4.cn"
  s.license = { :type => 'CC', :text => 'Copyright http://dev.i4.cn'}
  s.public_header_files = '**/*.h'
  s.framework = 'CoreGraphics', 'SystemConfiguration', 'Security', 'CoreText'
  s.weak_framework = 'AdSupport', 'CoreTelephony'
  s.vendored_framework = 'AlipaySDK.framework'
  s.preserve_paths = '**/*'
  s.vendored_libraries = '*.a'
  s.source_files = '**.{h,m,mm}'
  s.libraries = 'z'
  s.resources = 'AlipaySDK.bundle', 'iiappleResource.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
