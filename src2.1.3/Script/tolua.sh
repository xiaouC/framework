#!/bin/bash
cd ../toluaAPI/
tolua++ -L custom.lua -o luaapi.cpp api.pkg
