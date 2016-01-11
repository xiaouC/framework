#!/usr/bin/env python
# coding=utf-8

import sys
from ctypes import *

if __name__ == '__main__':
    dll = None
    try:
        if sys.platform=='darwin':
            dll = cdll.LoadLibrary( "../android/libtexEncrypt.dylib" )
        else:
            dll = cdll.LoadLibrary( "../android/libtexEncrypt.so" )
    except Exception,ex:
        print Exception,":",ex 
        exit(0)

    file_name = sys.argv[1]  
    dll.encrypt_file( file_name, file_name )

    #print '111111111111111111111111111111111111111111111111111'
    #dll.encrypt_file( 'Nb12.png', 'Nb21.png' )
    #print '222222222222222222222222222222222222222222222222222'
    #dll.decrypt_file( 'Nb21.png', 'Nb212.png' )
















