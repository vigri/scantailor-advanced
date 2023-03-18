#!/bin/sh

sudo apt install gcc g++ cmake libjpeg-dev libpng-dev libtiff5 libtiff5-dev libboost-test-dev qtbase5-dev libqt5svg5-dev qttools5-dev qttools5-dev-tools libqt5opengl5-dev

mkdir build; cd build
cmake -G "Unix Makefiles" --build ..
make -j `nproc`
