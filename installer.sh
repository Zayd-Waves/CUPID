#!/bin/bash

printf "\nInstalling cuPID (by Team Syzygy)\n"

mkdir ./build 2> /dev/null
rm -rf ./build/*
cd build

printf "\nCompiling...\n" 2> /dev/null
qmake .. 2> /dev/null
make 2> /dev/null

cp ../database-schema.sql ./
printf "\nPress [Enter] to start cuPID\n"

read -n1 kbd
./cupid-d4
