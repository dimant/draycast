# Define the compiler to use
CC = g++

# Define the compiler flags
CFLAGS = -g -lm

# Define the target executable
TARGET = draycast
TEST_TARGET = testme

# Define the source files
SRCS = src/canvas.cpp src/ppm.cpp src/matrix.cpp

TEST_SRCS = tests/dummy_tests.cpp tests/tuple_tests.cpp tests/canvas_tests.cpp tests/ppm_tests.cpp \
	tests/matrix_tests.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

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
