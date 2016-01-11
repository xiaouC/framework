#!/usr/bin/python
import os
import shutil
import files_pb2

flist = files_pb2.FileList()
flist.ParseFromString(open('assets/filelist', 'rb').read())
print flist
