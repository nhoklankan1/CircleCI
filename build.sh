#/bin/bash
BASE_DIR=$PWD
BUILD_DIR=$BASE_DIR/DIO_Abstraction
echo "==== Build Test Firmware for STM32 ===="

echo "==== Version of GCC Toolchains ===="
sudo apt install -y cmake
arm-none-eabi-gcc --version

echo "==== Run Build ===="
cd $BUILD_DIR
make all