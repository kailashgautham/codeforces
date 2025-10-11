#!/bin/bash

DIRECTORY=$1
FILE=$2

clang-format -i "$DIRECTORY/$FILE.cpp"

rm -f a.out
g++-15 -std=c++20 -Wall -isysroot "$(xcrun --show-sdk-path)" "$DIRECTORY/$FILE.cpp"
./a.out