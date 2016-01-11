Pod::Spec.new do |s|
  s.platform = :ios, '4.3'
  s.name     = 'OPGameSDK'
  s.version  = '3.0.3'
  s.summary  = 'OPGameSDK'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  s.homepage     = "http://www.ourpalm.com"
  s.license = { :type => 'CC', :text => 'Copyright http://www.ourpalm.com'}
  s.public_header_files = '*.h'
  s.framework = 'CoreGraphics', 'Foundation'
  s.weak_framework = 'UIKit', 'AdSupport'
  s.preserve_paths = '**/*'
  # s.libraries = 'c++'
  s.resources = 'Resource/ourpalm_res.bundle'
  s.vendored_libraries = 'libOurpalmSDK_OP.a'

  s.requires_arc = false
end

# vim: set ft=ruby:
