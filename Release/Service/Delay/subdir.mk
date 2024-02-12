################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Service/Delay/Delay.c 

OBJS += \
./Service/Delay/Delay.o 

C_DEPS += \
./Service/Delay/Delay.d 


# Each subdirectory must supply rules for building sources it contributes
Service/Delay/Delay.o: ../Service/Delay/Delay.c Service/Delay/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Service/Delay/Delay.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

