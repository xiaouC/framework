Pod::Spec.new do |s|
  s.platform = :ios, '4.3'
  s.name     = 'AppIcon'
  s.version  = '1.00003'
  s.summary  = 'AppIcon'
  s.authors  = { 'ratazzi' => 'ratazzi@yunyuegame.com' }
  s.source   = { :svn => 'http://192.168.0.249/svn/yzzh/win32_client/trunk/icon/ios/itools' }
  s.homepage = "http://www.yunyuegame.com"
  s.license = { :type => 'CC', :text => 'Copyright http://www.yunyuegame.com'}
  s.preserve_paths = '**/*'
  s.resources = ['{57,72,76,114,120,144,152}.png', 'iTunesArtwork', 'iTunesArtwork@2x']
  s.requires_arc = false
  s.prepare_command = 'mv 512.png iTunesArtwork && mv 1024.png iTunesArtwork@2x'
end

# vim: set ft=ruby:
