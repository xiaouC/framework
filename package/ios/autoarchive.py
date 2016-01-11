#!/usr/bin/env python
# encoding: utf-8

"""
Usage:
    autoarchive.py --project=<project> --target=<target> --version=<version> [--targeted-device-family=<device_family>] [--interactive] [--dry-run]
    autoarchive.py --workspace=<workspace> --scheme=<scheme> --version=<version> [--targeted-device-family=<device_family>] [--interactive] [--dry-run]
"""

import os
import sys
import glob
import plistlib
import subprocess
from fabric.api import prompt
from fabric.contrib.console import confirm
from docopt import docopt
from datetime import datetime

def find_identity():
    print '>>> Find valid codesign identity...'
    output = subprocess.check_output('security find-identity -p codesigning -v', shell=True)
    valid_identities = dict([(line.split()[0][0:-1], ' '.join(line.split()[2:])) for line in output.split('\n')[0:-2]])
    print output

    identity_id = prompt('CODE_SIGN_IDENTITY:')
    return valid_identities[identity_id]

def main():
    options = docopt(__doc__, help=True, options_first=False)
    if 'DRY_RUN' in os.environ:
        options['--dry-run'] = True
    # print options
    CODE_SIGN_IDENTITY = os.environ.get('CODE_SIGN_IDENTITY', None)
    if options['--interactive']:
        CODE_SIGN_IDENTITY = find_identity()
        print ' * Using CODE_SIGN_IDENTITY: {}'.format(CODE_SIGN_IDENTITY)
    else:
        print '>>> Preparing'
    project_dir = None
    build_dir = None
    target = None
    build_cmd = ['xcodebuild']
    if options['--project']:
        project_dir = os.path.dirname(options['--project'].rstrip('/'))
        target = options['--target']
        build_dir = os.path.abspath(os.path.join(project_dir, 'build'))
        build_cmd.extend(['-project', options['--project'], '-target', options['--target'], '-configuration', 'Release', 'clean', 'build', "CONFIGURATION_BUILD_DIR='{}'".format(build_dir)])
    elif options['--workspace']:
        project_dir = os.path.dirname(options['--workspace'].rstrip('/'))
        target = options['--scheme']
        build_dir = os.path.abspath(os.path.join(project_dir, 'build'))
        build_cmd.extend(['-workspace', options['--workspace'], '-scheme', options['--scheme'], '-configuration', 'Release', 'clean', 'build', "CONFIGURATION_BUILD_DIR='{}'".format(build_dir)])

    # {{{ 不允许连接设备打包
    try:
        # output = subprocess.check_output('idevice_id -l', shell=True)
        output = subprocess.check_output("system_profiler SPUSBDataType | sed -n -e '/iPhone/p;/iPad/p;/iPod/p'", shell=True)
        devices = output.split()
        if 'DRY_RUN' not in os.environ and len(devices) > 0:
            os.system('say --interactive=bold/red -v Vicki "Please disconnect any iOS devices"')
            exit(1)
    except subprocess.CalledProcessError:
        print ">>> Use `brew install libimobiledevice'"
        exit(1)
    # }}}

    # TARGETED_DEVICE_FAMILY
    # 1: iPhone/iPod touch.
    # 2: iPad.
    if options['--targeted-device-family']:
        build_cmd.append('TARGETED_DEVICE_FAMILY={}'.format(options['--targeted-device-family']))

    info_plist = os.path.join(project_dir, target, 'Resources', 'Info.plist')
    info = plistlib.readPlist(info_plist)

    # info['CFBundleVersion'] = info['CFBundleShortVersionString'] = options['--version']
    short_version = int(round(float(info['CFBundleShortVersionString']) * 100000))
    build_version = int(round(float(info['CFBundleVersion']) * 100000))
    version = int(round(float(options['--version']) * 100000))
    if build_version < short_version or short_version < version:
        info['CFBundleVersion'] = info['CFBundleShortVersionString'] = options['--version']
    else:
        info['CFBundleShortVersionString'] = options['--version']
        info['CFBundleVersion'] = str((int(round(float(options['--version']) * 100000)) + 1) / 100000.0)
    print ' * \033[01;33mCFBundleVersion\033[00m: {}'.format(info['CFBundleVersion'])
    print ' * \033[01;33mCFBundleShortVersionString\033[00m: {}'.format(info['CFBundleShortVersionString'])

    if os.environ.get('GAME_ENV', 'production') not in ('production',):
        info['GAME_ENV'] = os.environ['GAME_ENV']
    plistlib.writePlist(info, info_plist)
    print " * Write version info into Info.plist"
    output_dir = os.path.abspath(os.path.expanduser('~/ios_package/'))
    output_dir = os.environ.get('ARCHIVE_DIR', output_dir)
    output_dir = os.path.join(output_dir, options['--version'])
    if 'ARCHIVE_SUB_DIR' in os.environ:
        output_dir = os.path.join(output_dir, os.environ['ARCHIVE_SUB_DIR'])
    if CODE_SIGN_IDENTITY:
        output_dir = os.path.join(output_dir, CODE_SIGN_IDENTITY.strip('"'))
    output_name = '{}-封神小鲜肉_v{}.ipa'.format(os.environ['OUTPUT_SDK_NAME'], options['--version'])
    output_name = os.environ.get('ARCHIVE_FILENAME', output_name)
    print " * \033[01;33mOutput dir\033[00m: `{}'".format(output_dir)
    print ' * Output filename: {}'.format(output_name)

    # build assets
    print '\n>>> Build assets'
    cmd = 'python copyassets.py {}'.format(project_dir)
    print " * Run `{}'".format(cmd)
    os.system(cmd)

    # build
    print '\n>>> Build'
    if CODE_SIGN_IDENTITY:
        build_cmd.append('CODE_SIGN_IDENTITY="{}"'.format(CODE_SIGN_IDENTITY.replace('"', '')))
    cmd = ' '.join(build_cmd)
    print " * Run `{}'".format(cmd)
    if not options['--dry-run']:
        assert os.system(cmd) == 0

    # package
    print '\n>>> Package'
    if not os.path.isdir(output_dir):
        os.makedirs(output_dir)
    app_filename = os.path.join(build_dir, '{}.app'.format(target))
    cmd = "/usr/bin/xcrun -sdk iphoneos PackageApplication -v {} -o '{}'".format(app_filename, os.path.join(output_dir, output_name))
    print " * Run `{}'".format(cmd)
    if not options['--dry-run']:
        assert os.system(cmd) == 0

if __name__ == '__main__':
    main()
