set(PRJ_NAME STM32CubeIDE)
set(MCU_FAMILY STM32F1xx)
set(MCU_LINE STM32F103xB)
set(MCU_LINKER_SCRIPT STM32F103C8TX_FLASH.ld)
set(MCU_FAMILY $MCU_FAMILY)

cmake_minimum_required(VERSION 3.6)

project(${PRJ_NAME} C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#add_definitions(-D${MCU_LINE})
#add_definitions(-DUSE_HAL_LIBRARY)

set(STM32CUBEMX_INCLUDE_DIRECTORIES
    ${CMAKE_SOURCE_DIR}/Core/Inc
    ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/Include
    ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32F1xx/Include
    ${CMAKE_SOURCE_DIR}/Drivers/STM32F1xx_HAL_Driver/Inc
    ${CMAKE_SOURCE_DIR}/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy
)

set(PROJECT_INCLUDE_DIRECTORIES
    ${CMAKE_SOURCE_DIR}/ASW/APPs/Inc
    ${CMAKE_SOURCE_DIR}/ASW/DE/Inc
    ${CMAKE_SOURCE_DIR}/BSW/Inc
    ${CMAKE_SOURCE_DIR}/RTE/Inc)


file(GLOB CPP_SOURCES
    "${CMAKE_SOURCE_DIR}/ASW/APPs/Src/*.cpp"
    "${CMAKE_SOURCE_DIR}/ASW/DE/Src/*.cpp"
    "${CMAKE_SOURCE_DIR}/BSW/Src/*.cpp"
    "${CMAKE_SOURCE_DIR}/RTE/Src/*.cpp")

# Tìm các tệp c
file(GLOB C_SOURCES
    "${CMAKE_SOURCE_DIR}/Core/Src/*.c"
    "${CMAKE_SOURCE_DIR}/Drivers/STM32F1xx_HAL_Driver/Src/*.c")

# Tìm các tệp s (ASM)
file(GLOB ASM_SOURCES "Core/Startup/*.s")

set(SOURCE_FILES ${CPP_SOURCES} ${C_SOURCES} ${ASM_SOURCES})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_definitions(${PROJECT_NAME} PRIVATE
    #$<$<CONFIG:Debug>:DEBUG>
    ${MCU_LINE}
    USE_HAL_DRIVER)

include_directories(Include_Headers ${STM32CUBEMX_INCLUDE_DIRECTORIES} ${PROJECT_INCLUDE_DIRECTORIES})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.map")
set(HEX_FILE ${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.hex)
set(BIN_FILE ${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.bin)

#target_compile_features(my_executable PRIVATE c_std_11 cxx_std_14)

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/build
        COMMENT "Creating build directory")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE} 
Building ${BIN_FILE}")