include(CMakeForceCompiler)

set(MCU_LINKER_SCRIPT STM32F103C8TX_FLASH.ld)
set(MCU_ARCH cortex-m3)
set(MCU_FLOAT_ABI soft)
set(MCU_FPU fpv4-sp-d16)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GCC)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-g++ GCC)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)

set(FLAGS
    "-mcpu=${MCU_ARCH} -mthumb -mthumb-interwork -fdata-sections -ffunction-sections --specs=nano.specs -Wl,--gc-sections")
set(CPP_FLAGS
    "-mcpu=${MCU_ARCH} -mthumb -mthumb-interwork -fno-rtti -fno-exceptions -fno-threadsafe-statics -fms-extensions -fno-use-cxa-atexit -Wswitch-default -Wswitch-enum")

if (MCU_FLOAT_ABI STREQUAL hard)
    set(FLAGS "${FLAGS} -mfpu=${MCU_FPU}")
    set(CPP_FLAGS "${CPP_FLAGS} -mfpu=${MCU_FPU}")
endif ()

set(CMAKE_CXX_FLAGS "${CPP_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${FLAGS} -std=gnu99")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-gc-sections -ffunction-sections -fdata-sections -T ${MCU_LINKER_SCRIPT}")

#set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)