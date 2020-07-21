#!/bin/bash
chmod +x compiler.sh

function run() {

  local executableFileName="findcheese"
  local headerPath="./libs/headers"
  local funcPath="./libs/functions"

  gcc -o $executableFileName $headerPath/find_cheese.h $funcPath/find_cheese.c $headerPath/system.h $funcPath/system.c main.c
  ./$executableFileName
  rm $executableFileName
}

run
