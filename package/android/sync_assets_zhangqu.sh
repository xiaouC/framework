#!/bin/sh
rsync -rLcv --exclude "assets/filelist" --exclude "assets/fonts" assets zqtest:
