################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVER/src/LCD.c \
../DRIVER/src/adc.c \
../DRIVER/src/gpio.c \
../DRIVER/src/interupt.c 

OBJS += \
./DRIVER/src/LCD.o \
./DRIVER/src/adc.o \
./DRIVER/src/gpio.o \
./DRIVER/src/interupt.o 

C_DEPS += \
./DRIVER/src/LCD.d \
./DRIVER/src/adc.d \
./DRIVER/src/gpio.d \
./DRIVER/src/interupt.d 


# Each subdirectory must supply rules for building sources it contributes
DRIVER/src/%.o: ../DRIVER/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F401xC -I"D:/SBME 3rd year/secomd term/embeded/Labs/ADC/ADC/Core/Inc" -I"D:/SBME 3rd year/secomd term/embeded/Labs/ADC/ADC/DRIVER/include" -I"D:/SBME 3rd year/secomd term/embeded/Labs/ADC/ADC/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/SBME 3rd year/secomd term/embeded/Labs/ADC/ADC/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


