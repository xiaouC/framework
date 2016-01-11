#!/bin/bash
cd protocol
./gen.sh
cd ../src2.1.3/Script
./tolua.sh
