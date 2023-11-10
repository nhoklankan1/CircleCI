################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ASW/DE/Src/Action.cpp \
../ASW/DE/Src/BUTTON_Proxy.cpp \
../ASW/DE/Src/BUTTON_Singleton_Sample.cpp \
../ASW/DE/Src/GraspingManipulator.cpp \
../ASW/DE/Src/LED_Proxy.cpp \
../ASW/DE/Src/LED_Singleton_Sample.cpp \
../ASW/DE/Src/RobotArmManager.cpp \
../ASW/DE/Src/RotatingArmJoint.cpp \
../ASW/DE/Src/SlidingArmJoint.cpp 

OBJS += \
./ASW/DE/Src/Action.o \
./ASW/DE/Src/BUTTON_Proxy.o \
./ASW/DE/Src/BUTTON_Singleton_Sample.o \
./ASW/DE/Src/GraspingManipulator.o \
./ASW/DE/Src/LED_Proxy.o \
./ASW/DE/Src/LED_Singleton_Sample.o \
./ASW/DE/Src/RobotArmManager.o \
./ASW/DE/Src/RotatingArmJoint.o \
./ASW/DE/Src/SlidingArmJoint.o 

CPP_DEPS += \
./ASW/DE/Src/Action.d \
./ASW/DE/Src/BUTTON_Proxy.d \
./ASW/DE/Src/BUTTON_Singleton_Sample.d \
./ASW/DE/Src/GraspingManipulator.d \
./ASW/DE/Src/LED_Proxy.d \
./ASW/DE/Src/LED_Singleton_Sample.d \
./ASW/DE/Src/RobotArmManager.d \
./ASW/DE/Src/RotatingArmJoint.d \
./ASW/DE/Src/SlidingArmJoint.d 


# Each subdirectory must supply rules for building sources it contributes
ASW/DE/Src/%.o ASW/DE/Src/%.su ASW/DE/Src/%.cyclo: ../ASW/DE/Src/%.cpp ASW/DE/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"E:/ontap/stm32mcu/DIO_Abstraction/ASW/APPs/Inc" -I"E:/ontap/stm32mcu/DIO_Abstraction/RTE/Inc" -I"E:/ontap/stm32mcu/DIO_Abstraction/BSW/Inc" -I../Core/Inc -I"E:/ontap/stm32mcu/DIO_Abstraction/ASW/DE/Inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ASW-2f-DE-2f-Src

clean-ASW-2f-DE-2f-Src:
	-$(RM) ./ASW/DE/Src/Action.cyclo ./ASW/DE/Src/Action.d ./ASW/DE/Src/Action.o ./ASW/DE/Src/Action.su ./ASW/DE/Src/BUTTON_Proxy.cyclo ./ASW/DE/Src/BUTTON_Proxy.d ./ASW/DE/Src/BUTTON_Proxy.o ./ASW/DE/Src/BUTTON_Proxy.su ./ASW/DE/Src/BUTTON_Singleton_Sample.cyclo ./ASW/DE/Src/BUTTON_Singleton_Sample.d ./ASW/DE/Src/BUTTON_Singleton_Sample.o ./ASW/DE/Src/BUTTON_Singleton_Sample.su ./ASW/DE/Src/GraspingManipulator.cyclo ./ASW/DE/Src/GraspingManipulator.d ./ASW/DE/Src/GraspingManipulator.o ./ASW/DE/Src/GraspingManipulator.su ./ASW/DE/Src/LED_Proxy.cyclo ./ASW/DE/Src/LED_Proxy.d ./ASW/DE/Src/LED_Proxy.o ./ASW/DE/Src/LED_Proxy.su ./ASW/DE/Src/LED_Singleton_Sample.cyclo ./ASW/DE/Src/LED_Singleton_Sample.d ./ASW/DE/Src/LED_Singleton_Sample.o ./ASW/DE/Src/LED_Singleton_Sample.su ./ASW/DE/Src/RobotArmManager.cyclo ./ASW/DE/Src/RobotArmManager.d ./ASW/DE/Src/RobotArmManager.o ./ASW/DE/Src/RobotArmManager.su ./ASW/DE/Src/RotatingArmJoint.cyclo ./ASW/DE/Src/RotatingArmJoint.d ./ASW/DE/Src/RotatingArmJoint.o ./ASW/DE/Src/RotatingArmJoint.su ./ASW/DE/Src/SlidingArmJoint.cyclo ./ASW/DE/Src/SlidingArmJoint.d ./ASW/DE/Src/SlidingArmJoint.o ./ASW/DE/Src/SlidingArmJoint.su

.PHONY: clean-ASW-2f-DE-2f-Src

