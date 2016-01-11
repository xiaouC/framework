#!/usr/bin/env python
# coding=utf-8

import sys
import os
import json
import hashlib
import atexit
from ctypes import *

dll = cdll.LoadLibrary( "libtexEncrypt.dylib" )
lock_file = os.path.abspath('encrypt.lock')

checksums = dict()

def before_exit():
    with open(lock_file, 'w') as fp:
        fp.write(json.dumps(checksums))
        print '\033[01;32mUpdate\033[00m {}.'.format(lock_file)

atexit.register(before_exit)

if os.path.isfile(lock_file):
    with open(lock_file, 'r') as fp:
        checksums = json.loads(fp.read())

def md5file(filename, bufsize=1024):
    fd = open(filename, 'r')
    buf = fd.read(bufsize)
    m = hashlib.md5()
    while buf:
        m.update(buf)
        buf = fd.read(bufsize)
    return m.hexdigest()

def encrypt_file(src, dst):
    dll.encrypt_file(src, dst)

def encrypt_with_cache(src, dst):
    checksum = md5file(src)
    if checksums.get(src, '') != checksum or not os.path.isfile(dst):
        encrypt_file(src, dst)
        checksums[src] = checksum

if __name__ == '__main__':
    encrypt_with_cache(sys.argv[1], sys.argv[2])
