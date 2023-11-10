#/bin/bash
echo "Running Build and Save Script"
BASE_DIR=$PWD
BUILD_DIR=$BASE_DIR/DIO_Abstraction/Debug
echo $BASE_DIR
echo $BUILD_DIR

echo "install toolchains"
mkdir toolchains
cd toolchains
wget "https://developer.arm.com/-/media/Files/downloads/gnu/13.2.rel1/binrel/arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz"
ls -l
tar -xf arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz
rm arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz
ls -l
export PATH="~/toolchains/arm-gnu-toolchain-13.2.rel1/bin:$PATH"
arm-none-eabi-gcc --version

echo "build stm32"
cd $BUILD_DIR
make all
