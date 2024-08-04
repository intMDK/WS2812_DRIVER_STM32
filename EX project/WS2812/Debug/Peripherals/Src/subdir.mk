################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripherals/Src/WS2812_Hardware.c \
../Peripherals/Src/WS2812_middle.c \
../Peripherals/Src/gpio.c \
../Peripherals/Src/rcc.c 

OBJS += \
./Peripherals/Src/WS2812_Hardware.o \
./Peripherals/Src/WS2812_middle.o \
./Peripherals/Src/gpio.o \
./Peripherals/Src/rcc.o 

C_DEPS += \
./Peripherals/Src/WS2812_Hardware.d \
./Peripherals/Src/WS2812_middle.d \
./Peripherals/Src/gpio.d \
./Peripherals/Src/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
Peripherals/Src/%.o Peripherals/Src/%.su: ../Peripherals/Src/%.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/temporary workspace/STM32CUBEIDE/Summer 2024/WS2812/Peripherals/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Peripherals-2f-Src

clean-Peripherals-2f-Src:
	-$(RM) ./Peripherals/Src/WS2812_Hardware.d ./Peripherals/Src/WS2812_Hardware.o ./Peripherals/Src/WS2812_Hardware.su ./Peripherals/Src/WS2812_middle.d ./Peripherals/Src/WS2812_middle.o ./Peripherals/Src/WS2812_middle.su ./Peripherals/Src/gpio.d ./Peripherals/Src/gpio.o ./Peripherals/Src/gpio.su ./Peripherals/Src/rcc.d ./Peripherals/Src/rcc.o ./Peripherals/Src/rcc.su

.PHONY: clean-Peripherals-2f-Src

