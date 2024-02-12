################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART/UART_Prog.c 

OBJS += \
./MCAL/UART/UART_Prog.o 

C_DEPS += \
./MCAL/UART/UART_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/UART_Prog.o: ../MCAL/UART/UART_Prog.c MCAL/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/UART/UART_Prog.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

