################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../02_HAL/LCD/LCD.c \
../02_HAL/LCD/LCD_Config.c 

OBJS += \
./02_HAL/LCD/LCD.o \
./02_HAL/LCD/LCD_Config.o 

C_DEPS += \
./02_HAL/LCD/LCD.d \
./02_HAL/LCD/LCD_Config.d 


# Each subdirectory must supply rules for building sources it contributes
02_HAL/LCD/%.o: ../02_HAL/LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


