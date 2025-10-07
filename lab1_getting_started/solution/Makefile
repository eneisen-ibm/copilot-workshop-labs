# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g
INCLUDES = -Iinclude

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Target executable
TARGET = vitals_cli

# Default target
all: $(TARGET)

# Create object directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build target executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Run the program with default data
run: $(TARGET)
	./$(TARGET)

# Run with custom data file
run-file: $(TARGET)
	./$(TARGET) $(FILE)

# Validate the setup
validate:
	@echo "Checking build environment..."
	@which gcc || (echo "Error: gcc not found" && exit 1)
	@echo "Building project..."
	@make clean && make
	@echo "Running validation test..."
	@./$(TARGET) data/sample_vitals.csv
	@echo "✅ Setup validation complete!"

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Build the project (default)"
	@echo "  clean      - Remove build artifacts"
	@echo "  run        - Build and run with default data"
	@echo "  run-file   - Build and run with custom file (use FILE=path)"
	@echo "  validate   - Validate the complete setup"
	@echo "  help       - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make run"
	@echo "  make run-file FILE=data/sample_vitals.csv"

# Declare phony targets
.PHONY: all clean run run-file validate help