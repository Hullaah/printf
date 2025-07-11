# Compiler and flags
CC        := gcc
CFLAGS    := -Wall -Wextra -Werror -pedantic -std=gnu11 -O2 -Wno-format
DEBUGFLAGS := -g -O0

# Directories
SRCDIR    := src
TESTDIR   := tests
OBJDIR    := build

# Sources and Object files
SRCS      := $(wildcard $(SRCDIR)/*.c)
OBJS      := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TEST_SRC  := $(TESTDIR)/main.c
TEST_OBJ  := $(OBJDIR)/main.o
TARGET  := printf

INCLUDES  := -Iinclude

# Default target
all: $(TARGET)

# Build test executable
$(TARGET): $(OBJS) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

# Produce object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/main.o: $(TEST_SRC) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create build directory if needed
$(OBJDIR):
	mkdir -p $(OBJDIR)
clean:
	rm -rf $(OBJDIR) $(TARGET)

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
	clang-format -i src/*.c include/*.h

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
