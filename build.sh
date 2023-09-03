#!/usr/sh
rm -rf /build
cmake -B ./build -G Ninja || exit
ninja -C build
./build/sample