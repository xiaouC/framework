#!/usr/bin/python
# coding: utf-8
import os
import shutil
import files_pb2
from xml.dom.minidom import parse

import sys
sys.path.insert(0, '../../script')
import xxtea
XXTEA_KEY = '+/yUt6mb9FCtnC2C+F'
XXTEA_SIGN = 'YYLUA'

boot_assets = set([
    'mc/frames.index',
    'mc/anim.index',

    'config/hzb(2500).ini',

    'config/poem.pb',
    'config/config.pb',

    'main.lua',
    'utils/protobuf.lua',
    'utils/common.lua',
    'utils/userconfig.lua',

    'win/boot.lua',
    'config/GameSettings.lua',
    'utils/enums.lua',
    'utils/curlcodes.lua',
    'ui/controls.lua',
    'ui/floattext.lua',

    'win/error.lua',
    'utils/errcode.lua',

    'mc/login.anim',
    'mc/60058.anim',
    'mc/gameUI.anim',

    'images/default.png.pkm',
    'images/b6.png',
    'mc/loding.png.pkm',
    'mc/60058.png.pkm',

    'mc/gameUI_1.png',
    'mc/login_2.png',
])

cg_assets = set([
    'mc/story_6.png.pkm',
    'mc/story_5.png.pkm',
    'mc/story_4.png.pkm',
    'mc/story_3.png.pkm',
    'mc/story_2.png.pkm',
    'mc/story_1.png.pkm',
    'mc/story.anim',
    'music/sjcg.mp3',
])

DB_PATH = 'filelist'

mini_version = True

def get_version():
    doc = parse(open('AndroidManifest.xml'))
    nd = doc.getElementsByTagName('manifest')[0]
    return int(nd.getAttribute('android:versionCode'))

def get_platform():
    doc = parse(open('AndroidManifest.xml'))
    nd = doc.getElementsByTagName('manifest')[0]
    pkg = nd.getAttribute('package')
    return pkg[pkg.rfind('.')+1:]

def file_md5_size(f):
    import md5
    c = open(f, 'rb').read()
    return md5.md5(c).hexdigest(), len(c)

def md5_to_path(md5, url):
    ext = os.path.splitext(url)[1]
    return os.path.join(md5[:2], md5[2:]) + ext

def copyto(f, target):
    d = os.path.dirname(target)
    if not os.path.exists(d):
        os.makedirs(d)

    shutil.copyfile(f, target)

def is_valid_dir(r, platform=None):
    if '.svn' in r:
        return False
    if r.startswith('script'):
        return False
    if r.startswith('res'):
        return False
    if r.startswith('fla'):
        return False
    if r.startswith('fonts'):
        return False
    return True

def is_valid_file(f, r, platform):
    if f.endswith('.plist'):

        return False
	if f.endswith('.DS_Store'):
		return False
    if f.endswith('.dll'):
        return False
    if f.endswith('.exe'):
        return False
    if f.endswith('.a'):
        return False


    if f.endswith('.fla'):
        return False
    if f.endswith('.animxml'):
        return False
    if f.startswith('Thumbs.db'):
        return False
    if f.startswith('callgrind'):
        return False
    if f.startswith('gmon.out'):
        return False
    if f=='UserDefault.xml':
        return False
    if f=='main':
        return False
    if f.endswith('.swp'):
        return False
    if f.endswith('.orig'):
        return False
    if f.endswith('.pkm'):
        return False
    if f.endswith('.p8'):
        return False
    #if f.lower().endswith('.png') and os.path.exists(os.path.join(root, r, f+'.pkm')):
    #    return False
    if f.lower().endswith('.png') and os.path.exists(os.path.join(root, r, f+'.lh')):
        return False
    if mini_version and os.path.join(r, f) not in boot_assets:
        return False
    if platform=='mm2' and os.path.join(r, f) in cg_assets:
        return False
    return True

def version_name(ver):
    return str(ver/100000.0)

def replace_game_settings(s):
    return s

def build_assets(root, odir, version, platform):
   
    flist.version = version
    flist.platform = platform
    flist.version_name = version_name(version)
    for r, dirs, files in os.walk(root, followlinks=True):
        r = os.path.relpath(r, root)
        if r=='.':
            r = ''
        if not is_valid_dir(r, platform):
            continue
        for f in files:
            url = os.path.join(r, f)
            if not is_valid_file(f, r, platform):
                continue

            url = url.replace('\\', '/')
            ipath = os.path.join(root, url)

            signed = XXTEA_SIGN + xxtea.encrypt(open(ipath, 'rb').read(), XXTEA_KEY)
            ipath = '/tmp/temp_compiled.lua'
            f = open(ipath, 'wb')
            f.write(signed)
            f.close()

            md5, size = file_md5_size(ipath)
            opath = os.path.join(odir, md5_to_path(md5, url))

            copyto(ipath, opath)

            finfo = flist.files.add()
            finfo.url = url
            finfo.md5 = md5
            finfo.size = size
            finfo.where = files_pb2.PACKAGE
    s = flist.SerializeToString()
    open(os.path.join(odir, DB_PATH), 'wb').write(s)
    if os.name=='nt':
        os.system('mkdir %s\\fonts'%odir)
        os.system('copy %s\\fonts\\YunYueFont.ttf %s\\fonts\\'%(root, odir))
        os.system('copy %s\\fonts\\Fonts_android.png %s\\fonts\\'%(root, odir))
    else:
        os.system('mkdir %s/fonts'%odir)
        os.system('cp %s/fonts/YunYueFont.ttf %s/fonts/'%(root, odir))
        os.system('cp %s/fonts/Fonts_android.png %s/fonts/'%(root, odir))
        os.system('cp %s/filelist %s/%s_filelist' % (odir, odir, platform))

if __name__ == '__main__':
    import sys
    #if os.name=='nt':
    #    target = os.path.abspath('../../XLGame/packassets/')
    #else:
    target = os.path.abspath('./assets')
    root = '../../../client'
    print root, '===>', target
    mini_version = '--mini' in sys.argv
    build_assets(root, target, get_version(), get_platform())
