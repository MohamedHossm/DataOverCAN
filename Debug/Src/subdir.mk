################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c 

OBJS += \
./Src/main.o 

C_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/Applicatoin" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/Inc" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/Inc/LIBS" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/MCAL" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/MCAL/GPIO" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/MCAL/NVIC" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/MCAL/RCC" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/MCAL/Systick" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/MCAL/UART" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/Service" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/Service/Delay" -I"C:/Users/Amm/Desktop/NTI_work_space/CommucationOverCAN/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

