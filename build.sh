#/bin/bash
apt-get install wget
echo "Running Build and Save Script"
BASE_DIR=$PWD
BUILD_DIR=$BASE_DIR/DIO_Abstraction/Debug
echo $BASE_DIR
echo $BUILD_DIR
echo "install toolchains"
mkdir toolchains
cd toolchains
wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2?rev=78196d3461ba4c9089a67b5f33edf82a&hash=D484B37FF37D6FC3597EBE2877FB666A41D5253B
