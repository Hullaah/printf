# Compiler and flags
CC        := gcc
CFLAGS    := -Wall -Wextra -Werror -pedantic -std=gnu11 -O2 -Wno-format -fPIC
DEBUGFLAGS := -g -O0

# Directories
TESTDIR   := tests
INCDIR    := include

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
TEST_SRC := $(TESTDIR)/main.c
TEST_OBJ := $(TESTDIR)/main.o

TARGET    := printf

# Libraries
STATICLIB := libprintf.a
SHAREDLIB := libprintf.so

INCLUDES  := -I$(INCDIR)

# Default target builds libraries
all: library

# Library target (builds both static and shared)
library: $(STATICLIB) $(SHAREDLIB)

# Static library
$(STATICLIB): $(OBJS)
	ar rcs $@ $^

# Shared library
$(SHAREDLIB): $(OBJS)
	$(CC) -shared -o $@ $^

# Test executable links against static lib
test: library $(TEST_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_OBJ) -static -L. -lprintf -o $(TARGET)

# Produce object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Install both libraries and headers system-wide
install: library
	sudo cp $(STATICLIB) /usr/local/lib/
	sudo cp $(SHAREDLIB) /usr/local/lib/
	sudo mkdir -p /usr/local/include/printf
	sudo cp $(INCDIR)/*.h /usr/local/include/printf/
	sudo ldconfig

# Uninstall everything
uninstall:
	sudo rm -f /usr/local/lib/$(STATICLIB)
	sudo rm -f /usr/local/lib/$(SHAREDLIB)
	sudo rm -rf /usr/local/include/printf
	sudo ldconfig

# Debug mode
debug: CFLAGS := $(CFLAGS) $(DEBUGFLAGS)
debug: clean test

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TEST_OBJ) $(TARGET) $(STATICLIB) $(SHAREDLIB)

# Clean and Rebuild
re: clean all

# Format code
format:
	clang-format -i *.c include/*.h

# Help
help:
	@echo "Available targets:"
	@echo "  all        - Build static and shared libraries (default)"
	@echo "  library    - Build both static and shared libraries"
	@echo "  test       - Build test executable linked with libprintf"
	@echo "  install    - Install libraries and headers to /usr/local"
	@echo "  uninstall  - Remove installed files"
	@echo "  clean      - Remove build artifacts"
	@echo "  re         - Clean and rebuild"
	@echo "  debug      - Build with debug flags"
	@echo "  format     - Format source code"
	@echo "  help       - Show this help message"

.PHONY: all clean re format help debug install uninstall test library
