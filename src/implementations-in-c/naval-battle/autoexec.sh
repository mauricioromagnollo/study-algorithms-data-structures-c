#!/bin/bash
chmod +x autoexec.sh

function run() {

  local srcPath="./src"
  local headersPath="$srcPath/headers"
  local functionsPath="$srcPath/functions"
  local exeFileName="navalbattle"
  local files="$headersPath/system.h $functionsPath/system.c $headersPath/naval_battle.h $functionsPath/naval_battle.c $srcPath/main.c"

  gcc -o $exeFileName $files -lm;
  ./$exeFileName
  rm $exeFileName

}

run
