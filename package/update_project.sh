#!/bin/sh
mkdir Ourpalm_Android_NewPay_Lib_2.2.1_UC_ToCP/src
mkdir Ourpalm_Android_NewPay_Lib_2.2.1_360_ToCP/src
android update project -t 1 -p Ourpalm_Android_NewPay_Lib_2.2.1_UC_ToCP
android update project -t 1 -p Ourpalm_Android_NewPay_Lib_2.2.1_360_ToCP



android update project -t 1 -p android_uc
android update project -t 1 -p android_360
android update project -t 1 -p android_xp
android update project -t 1 -p android_xp_p8
android update project -t 1 -p android
android update project -t 1 -p ../cocos2d-x-2.1.5/cocos2dx/platform/android/java
