# Makefile for compiling and running main.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Executable name
TARGET = main

# Source files
SRCS = BM.c

# Default target
all: $(TARGET)

# Rule for building the target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Rule for cleaning the build
clean:
	rm -f $(TARGET)
