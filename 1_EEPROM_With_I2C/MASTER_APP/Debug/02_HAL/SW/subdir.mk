################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../02_HAL/SW/SW.c \
../02_HAL/SW/SW_Confg.c 

OBJS += \
./02_HAL/SW/SW.o \
./02_HAL/SW/SW_Confg.o 

C_DEPS += \
./02_HAL/SW/SW.d \
./02_HAL/SW/SW_Confg.d 


# Each subdirectory must supply rules for building sources it contributes
02_HAL/SW/%.o: ../02_HAL/SW/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


