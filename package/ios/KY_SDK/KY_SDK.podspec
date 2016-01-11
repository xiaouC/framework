Pod::Spec.new do |s|
  s.platform = :ios, '6.0.1'
  s.name     = 'KY_SDK'
  s.version  = '2.2.3'
  s.summary  = '快用苹果助手 SDK'
  s.authors  = { 'liupeng' => 'pengliu@yunyuegame.com' }
  s.homepage     = "http://shoulu.7659.com/index.php"
  s.license = { :type => 'CC', :text => 'Copyright http://shoulu.7659.com/'}
  s.public_header_files = '**/*.h'
  s.framework = 'CoreTelephony', 'SystemConfiguration'
  s.weak_framework = 'AdSupport'
  s.libraries = 'c++', 'z'
  s.preserve_paths = '**/*'
  s.vendored_framework = 'xsdkFramework.framework'
  # s.vendored_libraries = '*.a'
  s.source_files = '*.m'
  s.libraries = 'sqlite3.0', 'stdc++.6', 'z', 'xml2.2'
  s.resources = 'XSDKResource.bundle', 'AlipaySDK.bundle'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = false
end

# vim: set ft=ruby:
