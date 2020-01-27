#!/bin/bash
chmod +x runtest.sh

gcc -o testfile main.c -lm
./testfile
rm testfile