################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC/RCC_Prog.c 

OBJS += \
./MCAL/RCC/RCC_Prog.o 

C_DEPS += \
./MCAL/RCC/RCC_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/RCC/RCC_Prog.o: ../MCAL/RCC/RCC_Prog.c MCAL/RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/RCC/RCC_Prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

