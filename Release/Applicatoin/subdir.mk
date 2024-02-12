################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Applicatoin/CmmunicationOverCAN_PROG.c 

OBJS += \
./Applicatoin/CmmunicationOverCAN_PROG.o 

C_DEPS += \
./Applicatoin/CmmunicationOverCAN_PROG.d 


# Each subdirectory must supply rules for building sources it contributes
Applicatoin/CmmunicationOverCAN_PROG.o: ../Applicatoin/CmmunicationOverCAN_PROG.c Applicatoin/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Applicatoin/CmmunicationOverCAN_PROG.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

