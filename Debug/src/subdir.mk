################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Being.cpp \
../src/DiceBag.cpp \
../src/Die.cpp \
../src/GameMaster.cpp \
../src/HealthPot.cpp \
../src/Hero.cpp \
../src/ManaPot.cpp 

OBJS += \
./src/Being.o \
./src/DiceBag.o \
./src/Die.o \
./src/GameMaster.o \
./src/HealthPot.o \
./src/Hero.o \
./src/ManaPot.o 

CPP_DEPS += \
./src/Being.d \
./src/DiceBag.d \
./src/Die.d \
./src/GameMaster.d \
./src/HealthPot.d \
./src/Hero.d \
./src/ManaPot.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


