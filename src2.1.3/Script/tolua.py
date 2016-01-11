#!/usr/bin/python
import os, sys, subprocess, re
i = sys.argv[1]
o = sys.argv[2]
options = sys.argv[3:]
d = os.path.dirname(i)
i = os.path.basename(i)
o = os.path.relpath(o, d)
p = subprocess.Popen(['tolua++'] + options + ['-o', o, i], cwd=d)
p.wait()

# replace 
replaces = [
    (r'toluafix_pushusertype_ccobject\(tolua_S,\(void\*\)tolua_ret'
    ,'''int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret'''
    ),

    (r'unsigned void\* tolua_ret = \(unsigned void\*\)  self->getTiles\(\);'
    ,'unsigned int* tolua_ret = (unsigned int*)  self->getTiles();'
    ),

    (r'ccColor3B color = \*\(\(ccColor3B\*\)  tolua_tousertype\(tolua_S,4,\(void\*\)&\(const ccColor3B\)ccBLACK\)\);'
    ,'''ccColor3B clr = ccBLACK;
  ccColor3B color = *((ccColor3B*)  tolua_tousertype(tolua_S,4,(void*)&clr));'''
    ),

    (r'"LUA_FUNCTION",0,&tolua_err'
    ,'&tolua_err'
    ),

    ( r'LUA_FUNCTION ([\w]+) = \*\(\(LUA_FUNCTION\*\)  toluafix_ref_function\(tolua_S,'
    , 'int \\1 = (toluafix_ref_function(tolua_S,'
    ),
]

path = os.path.join(d, o)
s = open(path).read()
for f, t in replaces:
    s = re.sub(f, t, s)
open(path, 'w').write(s)
