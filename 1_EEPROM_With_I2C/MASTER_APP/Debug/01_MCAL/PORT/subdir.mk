################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../01_MCAL/PORT/PORT.c \
../01_MCAL/PORT/PORT_Confg.c 

S_UPPER_SRCS += \
../01_MCAL/PORT/Assembler1.S 

OBJS += \
./01_MCAL/PORT/Assembler1.o \
./01_MCAL/PORT/PORT.o \
./01_MCAL/PORT/PORT_Confg.o 

S_UPPER_DEPS += \
./01_MCAL/PORT/Assembler1.d 

C_DEPS += \
./01_MCAL/PORT/PORT.d \
./01_MCAL/PORT/PORT_Confg.d 


# Each subdirectory must supply rules for building sources it contributes
01_MCAL/PORT/%.o: ../01_MCAL/PORT/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Assembler'
	avr-gcc -x assembler-with-cpp -g2 -gstabs -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

01_MCAL/PORT/%.o: ../01_MCAL/PORT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


