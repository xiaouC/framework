#!/bin/sh
sed -i "s/org\/poemtest\/poem/org\/poem\/poem/g" ../Classes/platform/LoadingDialog.cpp
sed -i "s/org\.poemtest\>/org.poem/g" AndroidManifest.xml src/org/poemtest/poem.java
sed -i "s/org\.poemtest\>/org.poem/g" AndroidManifest.xml src/org/poemtest/app.java
mv src/org/poemtest src/org/poem
sed -i "s/圣将内测/圣将/g" res/values/strings.xml
