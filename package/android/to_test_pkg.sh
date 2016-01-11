#!/bin/sh
sed -i "s/org\/poem\/poem/org\/poemtest\/poem/g" ../Classes/platform/LoadingDialog.cpp
sed -i "s/org\.poem\>/org.poemtest/g" AndroidManifest.xml src/org/poem/poem.java
sed -i "s/org\.poem\>/org.poemtest/g" AndroidManifest.xml src/org/poem/app.java
mv src/org/poem src/org/poemtest
sed -i "s/圣将/圣将内测/g" res/values/strings.xml
