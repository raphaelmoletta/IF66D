################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/pingpong_dispacher.c \
../source/ppos_core.c \
../source/queue.c \
../source/ucontext.c 

OBJS += \
./source/pingpong_dispacher.o \
./source/ppos_core.o \
./source/queue.o \
./source/ucontext.o 

C_DEPS += \
./source/pingpong_dispacher.d \
./source/ppos_core.d \
./source/queue.d \
./source/ucontext.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DCPU_MK64FN1M0VDC12 -DFSL_RTOS_BM -DCPU_MK64FN1M0VDC12_cm4 -DSDK_OS_BAREMETAL -I../CMSIS -I../board -I../drivers -I../utilities -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


