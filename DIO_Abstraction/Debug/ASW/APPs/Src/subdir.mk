################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ASW/APPs/Src/main.cpp 

OBJS += \
./ASW/APPs/Src/main.o 

CPP_DEPS += \
./ASW/APPs/Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
ASW/APPs/Src/%.o ASW/APPs/Src/%.su ASW/APPs/Src/%.cyclo: ../ASW/APPs/Src/%.cpp ASW/APPs/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"E:/ontap/stm32mcu/DIO_Abstraction/ASW/APPs/Inc" -I"E:/ontap/stm32mcu/DIO_Abstraction/RTE/Inc" -I"E:/ontap/stm32mcu/DIO_Abstraction/BSW/Inc" -I../Core/Inc -I"E:/ontap/stm32mcu/DIO_Abstraction/ASW/DE/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ASW-2f-APPs-2f-Src

clean-ASW-2f-APPs-2f-Src:
	-$(RM) ./ASW/APPs/Src/main.cyclo ./ASW/APPs/Src/main.d ./ASW/APPs/Src/main.o ./ASW/APPs/Src/main.su

.PHONY: clean-ASW-2f-APPs-2f-Src

