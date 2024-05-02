################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 03_APP/EEPROM_With_I2C/subdir.mk
-include 03_APP/subdir.mk
-include 02_HAL/_7_SEG/subdir.mk
-include 02_HAL/SW/subdir.mk
-include 02_HAL/LED/subdir.mk
-include 02_HAL/LCD/subdir.mk
-include 02_HAL/KEYPAD/subdir.mk
-include 02_HAL/EEPROM/subdir.mk
-include 01_MCAL/TIMER/Timer1/subdir.mk
-include 01_MCAL/TIMER/Timer0and2/subdir.mk
-include 01_MCAL/PORT/subdir.mk
-include 01_MCAL/ICU/subdir.mk
-include 01_MCAL/I2C/subdir.mk
-include 01_MCAL/EXT-INT/subdir.mk
-include 01_MCAL/DIO/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.managedbuilder.core/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MASTER_APP.lss \

FLASH_IMAGE += \
MASTER_APP.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: MASTER_APP.elf secondary-outputs

# Tool invocations
MASTER_APP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MASTER_APP.map -mmcu=atmega32 -o "MASTER_APP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MASTER_APP.lss: MASTER_APP.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MASTER_APP.elf  >"MASTER_APP.lss"
	@echo 'Finished building: $@'
	@echo ' '

MASTER_APP.hex: MASTER_APP.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MASTER_APP.elf  "MASTER_APP.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MASTER_APP.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MASTER_APP.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MASTER_APP.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
