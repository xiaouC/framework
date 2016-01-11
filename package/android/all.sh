#!/bin/bash
echo "TTXM_SDKS_HOME = $TTXM_SDKS_HOME"

# 默认sdks存储路径
sdk_dir="/Users/yunyue/android_package"
if [ "$TTXM_SDKS_HOME" ]; then
    sdk_dir=$TTXM_SDKS_HOME
fi

datetime=`date +%Y%m%d%H%M`

rm -r assets

# rakefile模式
if [ "$1"=="--version" ]; then
    echo "rake mode"
    python copyassets.py --version $2
    if [ -d "extra_assets" ]; then
        cd assets
        ln -s ../extra_assets/* .
        cd -
    fi
    bash build_native.sh && ant release 

    mkdir -p "$sdk_dir/$2"
    echo "文件路径: $sdk_dir/$2/$3_v$2.apk"
    cp bin/poem-release.apk "$sdk_dir/$2/$3_v$2.apk"
    
# 安装模式
elif [ "$1"=="install" ]; then
    echo "install mode"
    python copyassets.py
    if [ -d "extra_assets" ]; then
        cd assets
        ln -s ../extra_assets/* .
        cd -
    fi
    bash build_native.sh && ant release
    adb install -r bin/poem-release.apk
# 默认编译模式
else 
    echo "normal mode"
    python copyassets.py
    if [ -d "extra_assets" ]; then
        cd assets
        ln -s ../extra_assets/* .
        cd -
    fi
    bash build_native.sh && ant release
fi


