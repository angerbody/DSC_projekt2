################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32L4xx_Nucleo_32/stm32l4xx_nucleo_32.c 

OBJS += \
./Utilities/STM32L4xx_Nucleo_32/stm32l4xx_nucleo_32.o 

C_DEPS += \
./Utilities/STM32L4xx_Nucleo_32/stm32l4xx_nucleo_32.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32L4xx_Nucleo_32/%.o: ../Utilities/STM32L4xx_Nucleo_32/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32L4 -DSTM32L432KCUx -DNUCLEO_L432KC -DDEBUG -DSTM32L432xx -DUSE_HAL_DRIVER -I"D:/226748/DSC_project2/HAL_Driver/Inc/Legacy" -I"D:/226748/DSC_project2/Utilities/STM32L4xx_Nucleo_32" -I"D:/226748/DSC_project2/inc" -I"D:/226748/DSC_project2/CMSIS/device" -I"D:/226748/DSC_project2/CMSIS/core" -I"D:/226748/DSC_project2/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


