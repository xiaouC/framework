#!/bin/sh
cd cocos2d-x-2.1.5/cocos2dx/proj.linux
scons
cd ../../CocosDenshion/proj.linux
make
cd ../../extensions/proj.linux
make
cd ../../scripting/lua/proj.linux
make
cd ../../../../
scons
