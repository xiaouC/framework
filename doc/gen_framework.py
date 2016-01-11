
import shutil;
import os;
if __name__ == '__main__':
    current_dir = "."
    src_dir = "..\\src2.1.3"
    dst_dir = current_dir + "\\framework_temp"
    doxygen_dir = "..\\..\\..\\tools\\doxygen"

    if os.path.exists(dst_dir):
        shutil.rmtree(dst_dir)
    
    print "start copy files"
    shutil.copytree(src_dir, dst_dir)
    
    print "start convert"
    list_dirs = os.walk(dst_dir) 
    for root, dirs, files in list_dirs:      
        for f in files:
            fn = os.path.join(root, f) 
            if os.path.splitext(f)[1] == ".h":
                if fn.find("particle") >= 0:   
                    os.system('%s\\UTF82ANSI.vbs "%s" "%s"' % (current_dir, fn, fn))
            else:
                os.remove(fn)
    
    print "start gen"
    os.system('%s\\doxygen.bat' % (current_dir))
    
    print "remove temp files"
    if os.path.exists(dst_dir):
        shutil.rmtree(dst_dir)
        
    print "finish"
