#!/usr/sh

cmake -B ./build -G Ninja || exit
ninja -C build
./build/metal-cpp