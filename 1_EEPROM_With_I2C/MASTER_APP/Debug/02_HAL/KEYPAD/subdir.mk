################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../02_HAL/KEYPAD/KeyPad.c \
../02_HAL/KEYPAD/KeyPad_confg.c 

OBJS += \
./02_HAL/KEYPAD/KeyPad.o \
./02_HAL/KEYPAD/KeyPad_confg.o 

C_DEPS += \
./02_HAL/KEYPAD/KeyPad.d \
./02_HAL/KEYPAD/KeyPad_confg.d 


# Each subdirectory must supply rules for building sources it contributes
02_HAL/KEYPAD/%.o: ../02_HAL/KEYPAD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


