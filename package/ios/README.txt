# 打包

## 环境变量
  * `GAME_ENV` 用于 GameSettings.lua，主要用于开发环境
  * `ASSETS_DIR` 打包时指定资源目录

## copyassets.py

* 用于拷贝资源到项目目录，同时更新项目文件，不需要再手动用 Xcode 更新资源
* 在项目没有除资源以外的改动的情况下，不要提交项目文件，避免协作冲突

## autoarchive.py

用于打包的实际脚本，仅仅完成通用的部分，需要特殊处理的放到 `Rakefile` 中完成

  `python autoarchive.py --project lszb_pp/lszb.xcodeproj --version 1.30010 --target lszb --interactive`
  `GAME_ENV=testing python autoarchive.py --project lszb_pp/lszb.xcodeproj --version 1.30010 --target lszb --interactive`
  `ASSETS_DIR=../../../client python autoarchive.py --project lszb_pp/lszb.xcodeproj --version 1.30010 --target lszb --interactive`
  `GAME_ENV=testing ASSETS_DIR=../../../client python autoarchive.py --project lszb_pp/lszb.xcodeproj --version 1.30010 --target lszb --interactive`

* `--interactive` 交互模式，用于选择签名

## Rakefile

用于批量打正式包，每个 SDK 的特殊处理都在这里面完成，某些环境需要运行下 `gem install --user-install plist`

    rake 'build:pp[1.30010]'
    rake 'build:all[1.30010]'

<!-- vim: set ft=markdown: -->
