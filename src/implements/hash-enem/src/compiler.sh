#!/bin/bash
chmod +x compiler.sh

function run() {
  
  local executableFileName="hashenem"
  local headerPath="./src/libs/headers"
  local funcPath="./src/libs/functions"
  
  compile $executableFileName $headerPath $funcPath

  # runExecutable $executableFileName
  # removeExecutable $executableFileName
}

function compile() {
  local executableFileName="$1"
  local headerPath="$2"
  local funcPath="$3"

  gcc -o $executableFileName $headerPath/calculadora_tempo.h $funcPath/calculadora_tempo.c $headerPath/hashenem.h $funcPath/hashenem.c ./src/main.c -lm
  ./$executableFileName
}

function runExecutable() {
  local executableFileName="$1"
  ./executableFileName
}

function removeExecutable() {
  local executableFileName="$1"
  rm $executableFileName
}

run