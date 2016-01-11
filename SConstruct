import os
import platform

pbc = SConscript( 'src2.1.3/pbc/SConscript' )


bits = platform.architecture()[0]

cpp_path = [ 'src2.1.3/pbc',
         'src2.1.3/Common/../',
         'src2.1.3/toluaAPI/lua-cjson-2.1.0',
         'protocol/src/',
         'protobuf-2.4.1/src',
         'cocos2d-x-2.1.5/cocos2dx',
         'cocos2d-x-2.1.5/cocos2dx/include',
         'cocos2d-x-2.1.5/cocos2dx/support',
         'cocos2d-x-2.1.5/cocos2dx/platform',
         'cocos2d-x-2.1.5/cocos2dx/platform/third_party/linux',
         'cocos2d-x-2.1.5/cocos2dx/platform/linux',
         'cocos2d-x-2.1.5/cocos2dx/kazmath/include',
         'cocos2d-x-2.1.5/CocosDenshion/include',
         'cocos2d-x-2.1.5/extensions',
         'cocos2d-x-2.1.5/scripting/lua/cocos2dx_support',
         'cocos2d-x-2.1.5/scripting/lua/lua',
         'cocos2d-x-2.1.5/scripting/lua/tolua',
         'cocos2d-x-2.1.5/external/chipmunk/include',
     ]

if bits == '64bit':
    cpp_path.insert( 0, 'cocos2d-x-2.1.5/cocos2dx/platform/third_party/linux/include64' )





lib_path = [ 'cocos2d-x-2.1.5/lib/linux/debug', 'cocos2d-x-2.1.5/cocos2dx/proj.linux', ]

if bits == '64bit':
    lib_path.append( 'cocos2d-x-2.1.5/cocos2dx/platform/third_party/linux/libraries/lib64' )
    lib_path.append( 'cocos2d-x-2.1.5/CocosDenshion/third_party/fmod/lib64/api/lib' )
else:
    lib_path.append( 'cocos2d-x-2.1.5/cocos2dx/platform/third_party/linux/libraries' )
    lib_path.append( 'cocos2d-x-2.1.5/CocosDenshion/third_party/fmod/api/lib' )



libs = [ 'lua',
     'cocosdenshion',
     'cocos2dx',
     'extension',
     'protobuf-lite',
     'curl',
     'glfw',
     'GLEW',
     'GL',
     'rt',
     'z',
     'freetype',
     'jpeg',
     'png',
     'fontconfig',
     'ldap',
     'rtmp',
     'idn',
     'pthread',
     'lber',
     'X11',
     'tiff',
     'webp',
     pbc,
 ]

if bits == '64bit':
    libs.append( 'fmodex64' )
else:
    libs.append( 'fmodex64' )



env = Environment(
        CCFLAGS=['-Wall', '-g3', '-pg'],
        CPPPATH = cpp_path,
        LIBPATH = lib_path,
        LIBS = libs,
    CPPDEFINES = [('COCOS2D_DEBUG', 2), 'LUA_DEBUG', 'LINUX', 'CC_UNDER_LINUX', 'RENDER_WITH_OPEN_GL', 'DEBUG', 'ENABLE_CJSON_GLOBAL'
                 #, 'PACK_RESOURCE'
                 ],
)

sources = Glob( 'src2.1.3/*.cpp' )
sources += Glob( 'src2.1.3/*/*.cpp')
sources += Glob( 'src2.1.3/*/*/*.cpp')
sources += Glob( 'protocol/src/*.cc' )
sources += Glob( 'src2.1.3/toluaAPI/*.c' )
sources += Glob( 'src2.1.3/toluaAPI/lua-cjson-2.1.0/*.c' )

env.Program( 'main', sources )
