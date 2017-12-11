################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RPG/Being.cpp \
../src/RPG/DiceBag.cpp \
../src/RPG/Die.cpp \
../src/RPG/GameMaster.cpp \
../src/RPG/HealthPot.cpp \
../src/RPG/Hero.cpp \
../src/RPG/Main.cpp \
../src/RPG/ManaPot.cpp 

OBJS += \
./src/RPG/Being.o \
./src/RPG/DiceBag.o \
./src/RPG/Die.o \
./src/RPG/GameMaster.o \
./src/RPG/HealthPot.o \
./src/RPG/Hero.o \
./src/RPG/Main.o \
./src/RPG/ManaPot.o 

CPP_DEPS += \
./src/RPG/Being.d \
./src/RPG/DiceBag.d \
./src/RPG/Die.d \
./src/RPG/GameMaster.d \
./src/RPG/HealthPot.d \
./src/RPG/Hero.d \
./src/RPG/Main.d \
./src/RPG/ManaPot.d 


# Each subdirectory must supply rules for building sources it contributes
src/RPG/%.o: ../src/RPG/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


