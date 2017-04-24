################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/efm8bb3/peripheralDrivers/src/spi_0.c 

OBJS += \
./lib/efm8bb3/peripheralDrivers/src/spi_0.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/efm8bb3/peripheralDrivers/src/%.OBJ: ../lib/efm8bb3/peripheralDrivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/efm8bb3/peripheralDrivers/src/spi_0.OBJ: C:/Users/Yvette\ Wang/SimplicityStudio/v4_workspace/EFM8BB3_RainbowBlinky_2\ 2/inc/config/efm8_config.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Register_Enums.h C:/Users/Yvette\ Wang/SimplicityStudio/v4_workspace/EFM8BB3_RainbowBlinky_2\ 2/lib/efm8bb3/peripheralDrivers/src/spi_0.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/EFM8BB3/inc/SI_EFM8BB3_Defs.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/8051/v4.0.3/Device/shared/si8051Base/stdbool.h


