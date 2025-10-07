# Makefile for Vitals CLI - Patient Vitals Monitoring System
# Lab 1: Getting Started with GitHub Copilot

# Compiler and flags
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -O2 -Iinclude
TARGET = vitals_cli
SRCDIR = src
INCDIR = include
DATADIR = data

# Source files
SOURCES = $(SRCDIR)/vitals.c $(SRCDIR)/parser.c $(SRCDIR)/validator.c $(SRCDIR)/alerts.c
HEADERS = $(INCDIR)/vitals.h

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(SOURCES) $(HEADERS)
	@echo "Building $(TARGET)..."
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)
	@echo "Build complete!"

# Run the program with sample data
run: $(TARGET)
	@echo "Running $(TARGET) with sample data..."
	./$(TARGET) $(DATADIR)/sample_vitals.csv

# Run with verbose output showing normal vitals too
run-verbose: $(TARGET)
	@echo "Running $(TARGET) with sample data (verbose)..."
	@echo "Expected output: Alerts for tachycardia, hypoxemia, and hyperthermia"
	./$(TARGET) $(DATADIR)/sample_vitals.csv

# Test with a non-existent file (should fail gracefully)
test-error: $(TARGET)
	@echo "Testing error handling..."
	./$(TARGET) nonexistent.csv || echo "Error handling test passed"

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -f $(TARGET)
	@echo "Clean complete!"

# Display help
help:
	@echo "Available targets:"
	@echo "  all        - Build the vitals_cli executable (default)"
	@echo "  run        - Build and run with sample data"
	@echo "  run-verbose- Run with verbose output"
	@echo "  test-error - Test error handling"
	@echo "  clean      - Remove build artifacts"
	@echo "  help       - Show this help message"

# Check code style (if clang-format is available)
format:
	@if command -v clang-format >/dev/null 2>&1; then \
		echo "Formatting code..."; \
		clang-format -i $(SOURCES) $(HEADERS); \
		echo "Formatting complete!"; \
	else \
		echo "clang-format not found, skipping formatting"; \
	fi

# Phony targets
.PHONY: all run run-verbose test-error clean help format