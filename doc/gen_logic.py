
import shutil;
import os;
if __name__ == '__main__':
    current_dir = ".\\"
    src_dir = "..\\..\\..\\clientdata2.1.3"
    dst_dir = current_dir + "\\logic_temp"
    lua_dir = "..\\..\\..\\tools\\lua51"

    if os.path.exists(dst_dir):
        shutil.rmtree(dst_dir)
    os.mkdir(dst_dir)
    
    print "start copy files"
    shutil.copy(src_dir + "\\main.lua", dst_dir)
    shutil.copytree(src_dir + "\\utils", dst_dir + "\\utils")
    shutil.copytree(src_dir + "\\win", dst_dir + "\\win")
    shutil.copytree(src_dir + "\\ui", dst_dir + "\\ui")
    
    print "start convert"
    list_dirs = os.walk(dst_dir) 
    for root, dirs, files in list_dirs:      
        for f in files:
            fn = os.path.join(root, f) 
            if os.path.splitext(f)[1] == ".lua":                
                os.system('%s\\UTF82ANSI.vbs "%s" "%s"' % (current_dir, fn, fn))
            else:
                os.remove(fn)
    
    print "start gen"
    os.system('%s\\lua.exe "%s\\lua\\luadoc_start.lua" -d "logic" *' % (lua_dir, lua_dir))
    
    print "remove temp files"
    if os.path.exists(dst_dir):
        shutil.rmtree(dst_dir)
        
    print "finish"
