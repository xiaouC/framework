#!/bin/sh
protoc --cpp_out=src *.proto
protoc -oframework.pb *.proto
echo '请手动把framework.pb拷贝到需要升级的项目资源'
