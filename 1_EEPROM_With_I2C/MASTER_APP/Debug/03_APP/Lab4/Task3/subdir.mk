################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../03_APP/Lab4/Task3/Task3.c 

OBJS += \
./03_APP/Lab4/Task3/Task3.o 

C_DEPS += \
./03_APP/Lab4/Task3/Task3.d 


# Each subdirectory must supply rules for building sources it contributes
03_APP/Lab4/Task3/%.o: ../03_APP/Lab4/Task3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


