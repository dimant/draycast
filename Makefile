# Define the compiler to use
CC = gcc

# Define the compiler flags
CFLAGS = -g -lm

# Define the target executable
TARGET = draycast

# Define the source files
SRCS = main.c vec.c color.c ray.c util.c

# Define the object files
OBJS = $(SRCS:.c=.o)

# Default target to build the program
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the generated files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
