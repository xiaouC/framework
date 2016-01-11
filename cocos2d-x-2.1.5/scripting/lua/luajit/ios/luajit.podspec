Pod::Spec.new do |s|
  s.name     = 'luajit'
  s.version  = '2.0.1'
  s.license  = { :type => 'MIT' }
  s.summary  = 'luagit'
  s.homepage = 'http://luajit.org'
  s.authors  = { 'ratazzi' =>'ratazzi.potts@gmail.com' }

  s.requires_arc = false
  s.vendored_libraries = 'libluajit.a'
end

# vim: set ft=ruby:
