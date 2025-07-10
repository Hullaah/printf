# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=gnu11 -I. -g
HEADER = printf.h

# Target executable
TARGET = printf

# Source files
SRCS = tests/main.c \
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

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Format code with clang-format
format:
	clang-format -i *.c *.h

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  clean    - Remove object files and executable"
	@echo "  re       - Clean and rebuild"
	@echo "  install  - Install executable to /usr/local/bin"
	@echo "  uninstall- Remove executable from /usr/local/bin"
	@echo "  test     - Run the program"
	@echo "  valgrind - Run with valgrind for memory checking"
	@echo "  format   - Format code with clang-format"
	@echo "  help     - Show this help message"

# Phony targets
.PHONY: all clean re install uninstall test valgrind format help