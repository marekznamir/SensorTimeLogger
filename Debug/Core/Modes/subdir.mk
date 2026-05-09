################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Modes/Modes.c 

OBJS += \
./Core/Modes/Modes.o 

C_DEPS += \
./Core/Modes/Modes.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Modes/%.o Core/Modes/%.su Core/Modes/%.cyclo: ../Core/Modes/%.c Core/Modes/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Modes

clean-Core-2f-Modes:
	-$(RM) ./Core/Modes/Modes.cyclo ./Core/Modes/Modes.d ./Core/Modes/Modes.o ./Core/Modes/Modes.su

.PHONY: clean-Core-2f-Modes

