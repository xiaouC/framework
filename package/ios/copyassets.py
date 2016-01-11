#!/usr/bin/env python
# coding=utf-8

"""
Usage:
    copyassets.py <project_dir> [--hd] [--assets-dir=<assets_dir>]

Options:
    --assets-dir=<assets_dir>            Assets dir [default: ../../../client]
"""

# Make sure the source assest directory in XLGame/assets has symbol linked
# corresponding directories in totato (svn).
# All rights reserved for Yunyue Game.

import os

import shutil
import files_pb2
import plistlib
import subprocess
import uuid
import docopt
from incrementalConfig_pb2 import incrementResponse

import sys
sys.path.insert(0, '../../script')
import xxtea
XXTEA_KEY = '+/yUt6mb9FCtnC2C+F'
XXTEA_SIGN = 'YYLUA'

DB_PATH = 'filelist'

def get_version(directory):
    obj = plistlib.readPlist(open(os.environ.get('INFOPLIST_FILE', '%s/lszb/Resources/Info.plist' % directory)))
    print int(round(float(obj['CFBundleShortVersionString'])*100000))
    return int(round(float(obj['CFBundleShortVersionString'])*100000))

def get_config_version( assets_dir ):
    config_version = 1

    increment_file_name = os.path.join( assets_dir, 'config/config_inc' )
    print 'increment_file_name', increment_file_name

    try:
        with open( increment_file_name, 'rb' ) as f:
            increment_response = incrementResponse()
            increment_response.ParseFromString( f.read() )
            config_version = increment_response.config_version
    except IOError:
        config_version = 1

    return config_version

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
    if f.endswith( '.encrypted' ) :
        shutil.move( f, target )
    else:
        shutil.copyfile(f, target)

def is_valid_dir(r):
    if '.svn' in r:
        return False
    if '.git' in r:
        return False
    if r.startswith('script'):
        return False
    if r.startswith('res'):
        return False
    if r.startswith('fla'):
        return False
    if r.startswith('fonts'):
        return False
    if r.startswith('test'):
        return False
    if r.startswith('replay'):
        return False
    return True

def is_valid_file_ccz(f, r):
    if f.endswith('.plist'):
        return False
    if f.endswith('.fla'):
        return False
    if f.endswith('.animxml'):
        return False
    if f.endswith('.plist'):
        return False
    if f.startswith('Thumbs.db'):
        return False
    if f.startswith('callgrind'):
        return False
    if f.startswith('gmon.out'):
        return False
    if f.startswith('.dll'):
        return False
    if f.startswith('.exe'):
        return False
    if f.startswith('.bat'):
        return False
    if f.startswith('.dmp'):
        return False
    if f.startswith('.log'):
        return False
    if f=='UserDefault.xml':
        return False
    if f=='main':
        return False
    if f.endswith('.swp'):
        return False
    if f.endswith('.orig'):
        return False
    if f.lower().endswith('.pkm'):
        return False
    if f.lower().endswith('.lh'):
        return False
    if f.lower().endswith('.png') and os.path.exists(os.path.join(root, r, f+'.pvrtc')):
        return False
    if f.lower().endswith('.png') and os.path.exists(os.path.join(root, r, f+'.pvr.ccz')):
        return False
    if f.lower().endswith('.pvr.ccz') and os.path.exists(os.path.join(root, r, os.path.basename(f)[:-8]+'.pvrtc')):
        return False
    return True

ignore_file_list = ['b1_4x.png','LocalSettings.lua', 'config_inc']
def is_valid_file_hd(f, r):
    if f.endswith('launch.png'):
        return False
    if f.endswith('.encrypted'):
        return False
    if f in ignore_file_list :
        return False
    if f.endswith('.gitignore'):
        return False
    if f.endswith('.plist'):
        return False
    if f.endswith('.DS_Store'):
        return False
    if f.endswith('.fla'):
        return False
    if f.endswith('.animxml'):
        return False
    if f.endswith('.plist'):
        return False
    if f.startswith('Thumbs.db'):
        return False
    if f.startswith('Thumbs.db:encryptable'):
        return False
    if f.startswith('callgrind'):
        return False
    if f.startswith('gmon.out'):
        return False
    if f=='UserDefault.xml':
        return False
    if f=='main':
        return False
    if f=='config_inc':
        return False
    if f.endswith('.swp'):
        return False
    if f.endswith('.orig'):
        return False
    if f.lower().endswith('.pkm'):
        return False
    if f.lower().endswith('.lh'):
        return False
    if f.lower().endswith('.ccz'):
        return False
    if f.lower().endswith('.pvrtc'):
        return False
    if f.lower().endswith('.dll'):
        return False
    if f.lower().endswith('.exe'):
        return False
    if f.lower().endswith('.a'):
        return False
    if f.lower().endswith('.DS_Store'):
        return False
    if f.lower().endswith('.bat'):
        return False
    # if f.lower().endswith('.png') and os.path.exists(os.path.join(root, r, f+'.pvrtc')):
    #     return False
    if f.lower().endswith('.png') and os.path.exists(os.path.join(root, r, f+'.p8')):
        return False
    if f.lower().endswith('.podspec'):
        return False
    if f.lower().endswith('.crdownload'):
        return False
    if f.lower().endswith('.mdmp'):
        return False
    return True

def is_valid_file_lh(f, r):
    if f.endswith('.plist'):
        return False
    if f.endswith('.fla'):
        return False
    if f.endswith('.animxml'):
        return False
    if f.endswith('.plist'):
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
    if f.lower().endswith('.pkm'):
        return False
    if f.lower().endswith('.ccz'):
        return False
    if f.lower().endswith('.png') and os.path.exists(os.path.join(root, r, f+'.pvrtc')):
        return False
    if f.lower().endswith('.png') and os.path.exists(os.path.join(root, r, f+'.lh')):
        return False
    if f.lower().endswith('.lh') and os.path.exists(os.path.join(root, r, os.path.basename(f)[:-3]+'.pvrtc')):
        return False
    if f.lower().endswith('.dll'):
        return False
    if f.lower().endswith('.exe'):
        return False
    if f.lower().endswith('.a'):
        return False
    if f.lower().endswith('.DS_Store'):
        return False
    return True

def version_name(ver):
    return '%.5f'%(ver/100000.0)

def build_assets(root, odir, version, platform, is_valid_file):
    flist = files_pb2.FileList()
    flist.platform = platform
    flist.version = version
    flist.version_name = version_name(version)
    flist.config_version = get_config_version( root )   # 存放的是增量配置的版本号
    print 'config version : ', flist.config_version
    from encrypt_png import encrypt_with_cache

    for r, dirs, files in os.walk(root, followlinks=True):
        r = os.path.relpath(r, root)
        if r=='.':
            r = ''
        if not is_valid_dir(r):
            continue

        for f in files:
            if not is_valid_file(f, r):
                continue

            url = os.path.join(r, f)
            url = url.replace('\\', '/')
            ipath = os.path.join(root, url)

            if f.endswith('.lua') and 'GameSettings' not in f:
                signed = XXTEA_SIGN + xxtea.encrypt(open(ipath, 'rb').read(), XXTEA_KEY)
                ipath = '/tmp/temp_compiled.lua'
                f = open(ipath, 'wb')
                f.write(signed)
                f.close()

            if url.endswith('.png') :
                url = url + '.p8'

            #if url.endswith('.p8') :
            #    url = url[:-3]

            # png 加密
            if url.endswith( '.p8' ) :
                abs_src = os.path.abspath(ipath)
                abs_dst = abs_src + '.encrypted'
                encrypt_with_cache(abs_src, abs_dst)
                ipath = abs_dst

            md5, size = file_md5_size(ipath)
            opath = os.path.join(odir, md5_to_path(md5, url))

            # print '{} -> {}'.format(ipath, opath)
            copyto(ipath, opath)

            finfo = flist.files.add()
            finfo.url = url
            finfo.md5 = md5
            finfo.size = size
            finfo.where = files_pb2.PACKAGE

    s = flist.SerializeToString()
    open(os.path.join(odir, DB_PATH), 'wb').write(s)
    os.system('mkdir %s/fonts'%odir)
    os.system('cp %s/fonts/YunYueFont.ttf %s/fonts/'%(root, odir))
    os.system('cp %s/assets.podspec %s/'%(root, odir))
    os.system('cp %s/filelist %s/%s_filelist' % (odir, odir, platform))

gamesettingsname=''
if __name__ == '__main__':
    import sys
    options = docopt.docopt(__doc__)
    print 'Enable HD version:', options['--hd']
    target_directory = options['<project_dir>']
    if os.environ.get('GAME_ENV', 'production') not in ('production',):
        info_plist = os.environ.get('INFOPLIST_FILE', os.path.join(target_directory, 'lszb/Resources/Info.plist'))
        info = plistlib.readPlist(open(info_plist))
        info['GAME_ENV'] = os.environ['GAME_ENV']
        print "GAME_ENV: \033[01;32m`{}'\033[00m".format(info.get('GAME_ENV', 'production'))
        plistlib.writePlist(info, info_plist)
    if os.name=='nt':
        target = os.path.abspath('../../packassets/')
    else:
        target = os.path.abspath('./%s/assets/' % target_directory)
        os.system('rm -rf %s' % target)
    root = os.environ.get('ASSETS_DIR', options['--assets-dir'])
    print "\033[01;33mUse assets\033[00m: `{}'".format(os.path.abspath(root))

    # 编译贴图加密模块
    os.system( 'scons' )

    platform = os.environ.get( 'PLATFORM' )
    build_assets(root, target, get_version(target_directory), platform, is_valid_file_hd)
