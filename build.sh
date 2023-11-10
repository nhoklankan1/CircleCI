#/bin/bash
echo "Running Build and Save Script"
BASE_DIR=$PWD
BUILD_DIR=$BASE_DIR/DIO_Abstraction/Debug
echo $BASE_DIR
echo $BUILD_DIR

echo "install toolchains"
mkdir toolchains
cd toolchains
wget "https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2"
ls -l
tar -jxf gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
rm gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
ls -l
export PATH="~/CircleCI/toolchains/gcc-arm-none-eabi-10.3-2021.10/bin:$PATH"
arm-none-eabi-gcc --version

echo "build stm32"
cd $BUILD_DIR
make j8 all
