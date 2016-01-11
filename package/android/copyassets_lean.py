#!/usr/bin/python
# coding: utf-8
import os, re
import shutil
import files_pb2
from xml.dom.minidom import parse
from incrementalConfig_pb2 import incrementResponse

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
    'win/confirm.lua',
    'utils/errcode.lua',

    'mc/login.anim',
    'mc/60058.anim',
    'mc/gameUI.anim',

    'images/default.png.pkm',
    'images/b6.png.pkm',
    'mc/loding.png.pkm',
    'mc/60058.png.pkm',

    'mc/gameUI_1.png',
    'mc/login_2.png',
])

cg_assets = set([
    'mc/story_6.png.lh',
    'mc/story_5.png.lh',
    'mc/story_4.png.lh',
    'mc/story_3.png.lh',
    'mc/story_2.png.lh',
    'mc/story_1.png.lh',
    'mc/story.anim',
    'music/sjcg.mp3',
])

cut_assets = [
    #u'^mc/10001',
#    u'^mc/10019',
    #u'^mc/10020',
]

DB_PATH = 'filelist'

mini_version = True

def get_version():
    doc = parse(open('AndroidManifest.xml'))
    nd = doc.getElementsByTagName('manifest')[0]
    return int(nd.getAttribute('android:versionCode'))

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
    return True

def isNonCGPlatform(platform):
    return True
    #return platform in ('mm2', 'mm3', 'egame', 'union', 'yymini')

def in_cut_assets(url):
    for u in cut_assets:
        if re.match(u, url):
            return True
    return False

ignore_file_list = ['b1_4x.png']
def is_valid_file(f, r, platform):
    url = os.path.join(r, f)
    if f in ignore_file_list:
        return False
    if f.endswith('.gitignore'):
        return False
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
    if f.endswith('.lh'):
        return False
    if f.endswith('.mp4'):  # android 的视频直接放在 res/raw/ 目录下
        return False
    if f.lower().endswith('.png') and os.path.exists(os.path.join(root, r, f+'.p8')):
        return False
    if f.lower().endswith('.hd'):
        return False
    if f.lower().endswith('.pkm'):
        return False
    if f.lower().endswith('.half'):
        return False
    #if f.lower().endswith('.jpg'):
    #    return False
    if mini_version and os.path.join(r, f) not in boot_assets:
        return False
    if isNonCGPlatform(platform) and url in cg_assets:
        return False
    if in_cut_assets(url):
        print 'ignore'
        return False
    #if r=='music':
    #    return False
    return True

def version_name(ver):
    return '%.5f'%(ver/100000.0)

def replace_game_settings(s):
    return s

def build_assets(root, odir, version, platform):
    flist = files_pb2.FileList()
    flist.version = version
    flist.platform = platform
    flist.version_name = version_name(version)
    flist.config_version = get_config_version( root )   # 存放的是增量配置的版本号
    print 'config version :', flist.config_version

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

            if f.endswith('.lua'):
                if os.name=='nt':
                    os.system('luajit -b  %s temp_compiled.lua' % ipath)
                    ipath = 'temp_compiled.lua'                    
                else:
                    os.system('luajit -b %s /tmp/temp_compiled.lua' % ipath)
                    ipath = '/tmp/temp_compiled.lua'

            if url.endswith('.p8') :
                url = url[:-3]

            # png 加密
            if url.endswith( '.png' ) :
                temp_file_name = '/tmp/temp_encrypt.png'
                copyto( ipath, temp_file_name )

                os.system('python encrypt_png.py %s'%temp_file_name)

                ipath = temp_file_name

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
    else:
        os.system('mkdir %s/fonts'%odir)
        os.system('cp %s/fonts/YunYueFont.ttf %s/fonts/'%(root, odir))
        os.system('cp %s/filelist %s/%s_filelist' % (odir, odir, platform))
        os.system('cp %s/../win32_client/icon/android/72.png %s/../res/drawable-hdpi/ic_launcher.png'%(root, odir))
        os.system('cp %s/../win32_client/icon/android/32.png %s/../res/drawable-ldpi/ic_launcher.png'%(root, odir))
        os.system('cp %s/../win32_client/icon/android/48.png %s/../res/drawable-mdpi/ic_launcher.png'%(root, odir))
        os.system('cp %s/../win32_client/icon/android/96.png %s/../res/drawable-xhdpi/ic_launcher.png'%(root, odir))

# 检查版本号
def check_manifest_version(src_version,target_version):
    print 'src_version: ', src_version 
    print 'target_version: ', target_version 
    # 修改androidmanifest.xml 版本号
    if src_version != target_version: 
        doc = parse(open('AndroidManifest.xml'))
        nd = doc.getElementsByTagName('manifest')[0]

        nd.setAttribute('android:versionCode',str(target_version))
        nd.setAttribute('android:versionName',str(version_name(int(target_version))))

        fileWriter = open('AndroidManifest.xml','w') 
        doc.writexml(fileWriter,'','','','utf-8')
        fileWriter.close()

# 恢复版本号
def restore_manifest_version():
    doc = parse(open('AndroidManifest.xml'))
    nd = doc.getElementsByTagName('manifest')[0]

    nd.setAttribute('android:versionCode','100000')
    nd.setAttribute('android:versionName','1.00000')

    fileWriter = open('AndroidManifest.xml','w') 
    doc.writexml(fileWriter)
    fileWriter.close()

if __name__ == '__main__':
    import sys

    # 编译贴图加密模块
    os.system( 'scons -C ../android' )

    target = os.path.abspath('./assets')
    root = os.getenv('CLIENT_DIRECTORY', '../../../client')
    print root, '===>', target
    mini_version = '--mini' in sys.argv

    print 'sys.argv: ', sys.argv
    if '--version' in sys.argv:
        if sys.argv[2] != None:
            print 'sys.argv[2]:', sys.argv[2]
            reload(sys) 
            sys.setdefaultencoding('utf8')
            check_manifest_version(get_version(), sys.argv[2])
        else:
            print '没有指定版本号!'
        

    build_assets(root, target, get_version(), get_platform())

