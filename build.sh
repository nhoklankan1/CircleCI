#/bin/bash
echo "Running Build and Save Script"
BASE_DIR=$PWD
BUILD_DIR=$BASE_DIR/Build-STM32-With-CI-master
echo $BASE_DIR
echo $BUILD_DIR

arm-none-eabi-gcc --version

echo "build stm32"
cd $BUILD_DIR
make all
