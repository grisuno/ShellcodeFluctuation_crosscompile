#!/bin/bash
sudo apt install mingw-w64
x86_64-w64-mingw32-gcc main.c -lkernel32 -lntdll -s -O2 -o ShellcodeFluctuation.exe
