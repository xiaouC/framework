Pod::Spec.new do |s|
  s.platform = :ios, '6.0'
  s.name     = 'PP_SDK_iOS'
  s.version  = '1.5.5'
  s.summary  = 'PP SDK'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  s.source   = { :git => 'git@192.168.0.252:ratazzi/PP_SDK_iOS.git', :tag => 'v1.5.3' }
  s.homepage     = "http://www.25pp.com"
  s.license = { :type => 'CC', :text => 'Copyright http://www.25pp.com'}
  # s.exclude_files = '*.{h,cc}'
  # s.source_files = '**/*.h'
  s.framework = 'CoreGraphics', 'QuartzCore', 'SystemConfiguration', 'Foundation', 'Security', 'CoreFoundation', 'CFNetwork', 'CoreText'
  s.weak_framework = 'AdSupport', 'UIKit'
  s.preserve_paths = '**/*'
  s.libraries = 'MobileGestalt'
  s.resources = 'PPAppPlatformKit.bundle'
  s.vendored_frameworks = 'PPAppPlatformKit.framework'

  s.xcconfig = {
      'CLANG_CXX_LIBRARY' => 'libstdc++',
  }
  s.requires_arc = false
  s.prepare_command = 'php -f Packer.php "iPhone Developer: kiko gao (AF44B4LFF2)"'
end

# vim: set ft=ruby:
