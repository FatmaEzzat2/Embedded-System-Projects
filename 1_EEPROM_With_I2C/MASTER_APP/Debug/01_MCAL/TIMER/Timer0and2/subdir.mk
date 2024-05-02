################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../01_MCAL/TIMER/Timer0and2/TIMER.c \
../01_MCAL/TIMER/Timer0and2/TIMER_Confg.c 

OBJS += \
./01_MCAL/TIMER/Timer0and2/TIMER.o \
./01_MCAL/TIMER/Timer0and2/TIMER_Confg.o 

C_DEPS += \
./01_MCAL/TIMER/Timer0and2/TIMER.d \
./01_MCAL/TIMER/Timer0and2/TIMER_Confg.d 


# Each subdirectory must supply rules for building sources it contributes
01_MCAL/TIMER/Timer0and2/%.o: ../01_MCAL/TIMER/Timer0and2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


