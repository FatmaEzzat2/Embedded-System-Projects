################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../02_HAL/LED/LED.c \
../02_HAL/LED/LED_Confg.c 

OBJS += \
./02_HAL/LED/LED.o \
./02_HAL/LED/LED_Confg.o 

C_DEPS += \
./02_HAL/LED/LED.d \
./02_HAL/LED/LED_Confg.d 


# Each subdirectory must supply rules for building sources it contributes
02_HAL/LED/%.o: ../02_HAL/LED/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


