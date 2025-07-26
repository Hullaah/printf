# Compiler and flags
CC        := gcc
CFLAGS    := -Wall -Wextra -Werror -pedantic -std=gnu11 -O2 -Wno-format
DEBUGFLAGS := -g -O0

# Directories
TESTDIR   := tests

# Sources and Object files
SRCS := \
    dispatcher.c \
    handle_binary.c \
    handle_char.c \
    handle_decimal.c \
    handle_hexadecimal.c \
    handle_octal.c \
    handle_percent.c \
    handle_pointer.c \
    handle_reverse.c \
    handle_rot13.c \
    handle_string.c \
    handle_unprintable.c \
    handle_unsigned.c \
    parser.c \
    printf.c \
    utils.c
OBJS := $(SRCS:.c=.o)
TEST_SRC  := $(TESTDIR)/main.c
TEST_OBJ  := $(TESTDIR)/main.o
TARGET  := printf

INCLUDES  := -Iinclude

# Default target
all: $(TARGET)

# Build test executable
$(TARGET): $(OBJS) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# Produce object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TEST_OBJ) $(TARGET)

# Debug mode: build with -g and run gdb
debug: CFLAGS := $(CFLAGS) $(DEBUGFLAGS)
debug: clean all
	@echo "Launching gdb on $(TARGET)..."
	@gdb ./$(TARGET)

run: all
	@./$(TARGET)


# Clean and Rebuild
re: clean all

# Format code with clang-format
format:
	clang-format -i *.c include/*.h

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  clean    - Remove object files and executable"
	@echo "  re       - Clean and rebuild"
	@echo "  format   - Format code with clang-format"
	@echo "  help     - Show this help message"
	@echo "  debug    - Build with debug flags and run gdb"
	@echo "  run      - Run the test executable"

# Phony targets
.PHONY: all clean re format help debug run
