################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32l432xx.s 

OBJS += \
./startup/startup_stm32l432xx.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"D:/226748/DSC_project2/HAL_Driver/Inc/Legacy" -I"D:/226748/DSC_project2/Utilities/STM32L4xx_Nucleo_32" -I"D:/226748/DSC_project2/inc" -I"D:/226748/DSC_project2/CMSIS/device" -I"D:/226748/DSC_project2/CMSIS/core" -I"D:/226748/DSC_project2/HAL_Driver/Inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


