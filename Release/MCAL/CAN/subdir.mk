################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/CAN/CAN_program.c 

OBJS += \
./MCAL/CAN/CAN_program.o 

C_DEPS += \
./MCAL/CAN/CAN_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/CAN/CAN_program.o: ../MCAL/CAN/CAN_program.c MCAL/CAN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/CAN/CAN_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

