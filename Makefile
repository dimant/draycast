# Define the compiler to use
CC = gcc

# Define the compiler flags
CFLAGS = -g -lm

# Define the target executable
TARGET = draycast
TEST_TARGET = testme

# Define the source files
SRCS = src/tuple.c src/canvas.c

TEST_SRCS = tests/tuple_tests.c tests/canvas_tests.c

# Define the object files
OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Default target to build the program
all: $(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS) src/main.o
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) src/main.o

$(TEST_TARGET): $(OBJS) $(TEST_OBJS) tests/main.o
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(OBJS) $(TEST_OBJS) tests/main.o

# Rule to compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the generated files
clean:
	rm -f $(OBJS) $(TEST_OBJS) src/main.o tests/main.o $(TARGET) $(TEST_TARGET)

.PHONY: all clean
