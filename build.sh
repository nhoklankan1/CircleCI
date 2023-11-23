#/bin/bash
BASE_DIR=$PWD
BUILD_DIR=$BASE_DIR/DIO_Abstraction
echo "==== Build Test Firmware for STM32 ===="

echo "==== Version of GCC Toolchains ===="
apt install -y cmake
arm-none-eabi-gcc --version
cmake -DCMAKE_TOOLCHAIN_FILE=${CMAKE_CURRENT_SOURCE_DIR}/gcc-arm-none-eabi.cmake

echo "==== Run Build ===="
cd $BUILD_DIR
make all