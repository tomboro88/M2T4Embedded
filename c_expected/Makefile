# --- configuration ---
CC = gcc

# Flags for different configurations
CFLAGS_RELEASE = -Wall -Wextra -O2 -I./src/ -I./src/fifo -I./src/event_pool
CFLAGS_DEBUG   = -Wall -Wextra -g -O0 -I./src/ -I./src/fifo -I./src/event_pool

# Default configuration
BUILD ?= Release

ifeq ($(BUILD),Debug)
    CFLAGS = $(CFLAGS_DEBUG)
    OBJDIR = obj/debug
    BINDIR = bin/debug
else
    CFLAGS = $(CFLAGS_RELEASE)
    OBJDIR = obj/release
    BINDIR = bin/release
endif

# Find all .c files in src/ and subfolders
SRCS := $(shell find src -name '*.c')

# Replace the src paths with corresponding obj files in obj/
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

BINDIR := bin
TARGET = c_expected

# --- The main rule ---
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Compile the .o in obj/ from .c in src/
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# --- cleanup ---
clean:
	rm -rf obj bin

