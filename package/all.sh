#!/bin/bash
function build() {
  cd android_$1
  mkdir -p ~/poem/sdks/$1
  ./all.sh copy ~/poem/sdks/$1/
  cd ..
}
build 91
build uc
build dl
build mi
build gfan
build yy
