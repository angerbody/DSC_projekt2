################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_Driver/Src/Legacy/stm32l4xx_hal_can.c 

OBJS += \
./HAL_Driver/Src/Legacy/stm32l4xx_hal_can.o 

C_DEPS += \
./HAL_Driver/Src/Legacy/stm32l4xx_hal_can.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_Driver/Src/Legacy/%.o: ../HAL_Driver/Src/Legacy/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32L4 -DSTM32L432KCUx -DNUCLEO_L432KC -DDEBUG -DSTM32L432xx -DUSE_HAL_DRIVER -I"C:/Users/Konrad/git/DSC_projekt2/DSC_projekt2/HAL_Driver/Inc/Legacy" -I"C:/Users/Konrad/git/DSC_projekt2/DSC_projekt2/Utilities/STM32L4xx_Nucleo_32" -I"C:/Users/Konrad/git/DSC_projekt2/DSC_projekt2/inc" -I"C:/Users/Konrad/git/DSC_projekt2/DSC_projekt2/CMSIS/device" -I"C:/Users/Konrad/git/DSC_projekt2/DSC_projekt2/CMSIS/core" -I"C:/Users/Konrad/git/DSC_projekt2/DSC_projekt2/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


