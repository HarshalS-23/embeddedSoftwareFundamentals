include sources.mk

INCLUDE_FLAGS := $(foreach dir,$(INCLUDES),-I$(dir))

OBJS=$(SOURCES:.c=.o)
PREPROCESSED=$(SOURCES:.c=.i)
ASSEMBLY=$(SOURCES:.c=.s)

#GENERAL C Flags
GCFLAGS= -Wall -g -O0 -std=c99 #-Werror

#Platform overrides
PLATFORM=HOST

#Architecture Specific Flags
LINKER_FILE= -T msp432p401r.lds
CPU=cortex-m4
ARCH= thumb
SPECS= nosys.specs

#Compiler Flags and Defines
CC= gcc
LD= ld
TARGET=FinalAssessment
LDFLAGS= -Wl,-Map=$(TARGET).map 
CFLAGS= $(GCFLAGS)
CPPFLAGS= -E

COURSE1= false
VERBOSE =false

ifeq ($(VERBOSE),true)
VERFLAG=-DVERBOSE
endif

ifeq ($(COURSE1), true)
COURSEFLAG=-DCOURSE1
endif

ifeq ($(PLATFORM),HOST)
CC= gcc 
CFLAGS=  $(GCFLAGS) $(LDFLAGS)
SZ= size
endif

ifeq ($(PLATFORM),MSP432)
SOURCES += src/interrupts_msp432p401r_gcc.c\
	src/startup_msp432p401r_gcc.c\
	src/system_msp432p401r.c
PLATFORM=MSP432
CC = arm-none-eabi-gcc $(LINKER_FILE) 
CFLAGS+=$(GCFLAGS) $(LDFLAGS) -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS)\
	-Wall -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
SZ= arm-none-eabi-size
LD= arm-none-eabi-ld
endif
 

.PHONY: compile-all build clean 



build : $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) -D$(PLATFORM) $(INCLUDE_FLAGS) $^ -o $@
	$(SZ) -Atd $@

%.i: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -D$(PLATFORM) $(INCLUDE_FLAGS) $< -o $@

%.s: %.c
	$(CC) $(CFLAGS) -D$(PLATFORM) $(INCLUDE_FLAGS) -S $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -D$(PLATFORM) $(COURSEFLAG) $(VERFLAG) $(INCLUDE_FLAGS) -c $< -o $@

compile-all: $(OBJS)

clean:
	rm -f src/*.o src/*.i src/*.s *.out build $(TARGET).map 



