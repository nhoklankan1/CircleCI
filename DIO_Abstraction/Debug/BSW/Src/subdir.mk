################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BSW/Src/BSW_DIO.cpp 

OBJS += \
./BSW/Src/BSW_DIO.o 

CPP_DEPS += \
./BSW/Src/BSW_DIO.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/Src/%.o BSW/Src/%.su BSW/Src/%.cyclo: ../BSW/Src/%.cpp BSW/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"E:/ontap/stm32mcu/DIO_Abstraction/ASW/APPs/Inc" -I"E:/ontap/stm32mcu/DIO_Abstraction/RTE/Inc" -I"E:/ontap/stm32mcu/DIO_Abstraction/BSW/Inc" -I../Core/Inc -I"E:/ontap/stm32mcu/DIO_Abstraction/ASW/DE/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-BSW-2f-Src

clean-BSW-2f-Src:
	-$(RM) ./BSW/Src/BSW_DIO.cyclo ./BSW/Src/BSW_DIO.d ./BSW/Src/BSW_DIO.o ./BSW/Src/BSW_DIO.su

.PHONY: clean-BSW-2f-Src

