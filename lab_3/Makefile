# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g -O2
INCLUDES = -Iinclude

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
TESTDIR = test
TESTOBJ = test_obj

# Source files (explicitly list for better dependency tracking)
SOURCES = $(SRCDIR)/main.c \
          $(SRCDIR)/controller.c \
          $(SRCDIR)/data_generator.c \
          $(SRCDIR)/analysis.c \
          $(SRCDIR)/visualization.c \
          $(SRCDIR)/alarm.c \
          $(SRCDIR)/config.c

OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Header dependencies
HEADERS = $(wildcard $(INCDIR)/*.h)

# Target executable
TARGET = data_generator

# Test files and targets
TEST_SOURCES = $(TESTDIR)/test_alarm.c
TEST_LIB_OBJECTS = $(OBJDIR)/alarm.o $(OBJDIR)/config.o $(OBJDIR)/data_generator.o
TEST_EXECUTABLE = test_alarm

# Default target
all: $(TARGET)

# Create directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TESTOBJ):
	mkdir -p $(TESTOBJ)

# Build target executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Build object files with header dependencies
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Specific dependencies for better incremental builds
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/controller.h
$(OBJDIR)/controller.o: $(SRCDIR)/controller.c $(INCDIR)/controller.h $(INCDIR)/data_generator.h $(INCDIR)/analysis.h $(INCDIR)/visualization.h $(INCDIR)/alarm.h $(INCDIR)/config.h
$(OBJDIR)/data_generator.o: $(SRCDIR)/data_generator.c $(INCDIR)/data_generator.h
$(OBJDIR)/analysis.o: $(SRCDIR)/analysis.c $(INCDIR)/analysis.h $(INCDIR)/data_generator.h
$(OBJDIR)/visualization.o: $(SRCDIR)/visualization.c $(INCDIR)/visualization.h $(INCDIR)/data_generator.h
$(OBJDIR)/alarm.o: $(SRCDIR)/alarm.c $(INCDIR)/alarm.h $(INCDIR)/data_generator.h $(INCDIR)/config.h
$(OBJDIR)/config.o: $(SRCDIR)/config.c $(INCDIR)/config.h



# Build tests
test: $(TEST_EXECUTABLE)

# Build test executable
$(TEST_EXECUTABLE): $(TEST_SOURCES) $(TEST_LIB_OBJECTS) | $(TESTOBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_SOURCES) $(TEST_LIB_OBJECTS) -o $(TEST_EXECUTABLE)

# Run tests
test-run: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TESTOBJ) $(TARGET) $(TEST_EXECUTABLE)

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Build the project (default)"
	@echo "  test       - Build the test executable"
	@echo "  test-run   - Build and run tests"
	@echo "  clean      - Remove build artifacts"
	@echo "  run        - Build and run the data generator"
	@echo "  help       - Show this help message"

# Declare phony targets
.PHONY: all test test-run clean run help