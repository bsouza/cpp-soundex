################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SoundexTest.cpp \
../TestMain.cpp 

OBJS += \
./SoundexTest.o \
./TestMain.o 

CPP_DEPS += \
./SoundexTest.d \
./TestMain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/bsouza/dev/tools/cpp_tools/libs/gmock/latest/include -I/home/bsouza/dev/tools/cpp_tools/libs/gmock/latest/gtest/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


