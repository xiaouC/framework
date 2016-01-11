#!/bin/sh
cd cocos2d-x-2.1.5/cocos2dx/proj.linux
scons -c
cd ../../CocosDenshion/proj.linux
make clean
cd ../../extensions/proj.linux
make clean
cd ../../scripting/lua/proj.linux
make clean
cd ../../../../
scons -c
