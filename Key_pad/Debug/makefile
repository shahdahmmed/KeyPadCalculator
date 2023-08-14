################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/KEY_PAD/subdir.mk
-include HAL/7Segment/subdir.mk
-include APP/subdir.mk
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
Key_pad.lss \

FLASH_IMAGE += \
Key_pad.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Key_pad.elf secondary-outputs

# Tool invocations
Key_pad.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Key_pad.map -mmcu=atmega32 -o "Key_pad.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Key_pad.lss: Key_pad.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Key_pad.elf  >"Key_pad.lss"
	@echo 'Finished building: $@'
	@echo ' '

Key_pad.hex: Key_pad.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Key_pad.elf  "Key_pad.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Key_pad.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Key_pad.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Key_pad.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
