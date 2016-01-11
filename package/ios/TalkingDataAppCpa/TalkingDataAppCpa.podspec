Pod::Spec.new do |s|
  s.platform = :ios, '4.3'
  s.name     = 'TalkingDataAppCpa'
  s.version  = '2.2.38'
  s.summary  = 'TalkingDataAppCpa'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  # s.source   = { :git => 'git@192.168.0.252:ratazzi/TalkingDataAppCpa.git', :tag => 'v1.0.14' }
  s.homepage     = "http://www.talkinggame.com"
  s.license = { :type => 'CC', :text => 'Copyright http://www.talkinggame.com'}
  s.public_header_files = '*.h'
  s.framework = 'Security', 'SystemConfiguration', 'CoreGraphics'
  s.weak_framework = 'CoreTelephony', 'AdSupport'
  s.libraries = 'z'
  s.preserve_paths = '**/*'
  s.vendored_libraries = 'libTalkingDataAppCpa.a'

  s.requires_arc = false
end

# vim: set ft=ruby:
