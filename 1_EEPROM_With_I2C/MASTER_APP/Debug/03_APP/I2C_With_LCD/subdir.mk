################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../03_APP/I2C_With_LCD/MASTER_APP.c 

OBJS += \
./03_APP/I2C_With_LCD/MASTER_APP.o 

C_DEPS += \
./03_APP/I2C_With_LCD/MASTER_APP.d 


# Each subdirectory must supply rules for building sources it contributes
03_APP/I2C_With_LCD/%.o: ../03_APP/I2C_With_LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


