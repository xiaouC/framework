Pod::Spec.new do |s|
  s.name     = 'lua'
  s.version  = '5.1.5'
  s.license  = { :type => 'MIT' }
  s.summary  = 'lua'
  s.homepage = 'http://lua.org'
  s.authors  = { 'ratazzi' =>'ratazzi.potts@gmail.com' }

  s.requires_arc = false
  s.source_files = '*.{h,c}'
end

# vim: set ft=ruby:
