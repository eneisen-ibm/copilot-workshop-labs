# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g -O2
INCLUDES = -Iinclude

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
TESTDIR = test
TESTOBJDIR = test_obj

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

# Target executables
TARGET = data_generator
TEST_TARGET = test_alarm

# Test source files
TEST_SOURCES = $(TESTDIR)/test_alarm.c

# Test object files (only test_alarm.o)
TEST_OBJECTS = $(TESTOBJDIR)/test_alarm.o

# Library object files (alarm, config, data_generator - no main)
LIB_OBJECTS = $(OBJDIR)/alarm.o \
              $(OBJDIR)/config.o \
              $(OBJDIR)/data_generator.o

# Default target
all: $(TARGET)

# Create object directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TESTOBJDIR):
	mkdir -p $(TESTOBJDIR)

# Build target executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) -lm

# Build object files with header dependencies
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Specific dependencies for better incremental builds
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/controller.h
$(OBJDIR)/controller.o: $(SRCDIR)/controller.c $(INCDIR)/controller.h $(INCDIR)/data_generator.h $(INCDIR)/analysis.h $(INCDIR)/visualization.h $(INCDIR)/alarm.h $(INCDIR)/config.h
$(OBJDIR)/data_generator.o: $(SRCDIR)/data_generator.c $(INCDIR)/data_generator.h
$(OBJDIR)/analysis.o: $(SRCDIR)/analysis.c $(INCDIR)/analysis.h $(INCDIR)/data_generator.h $(INCDIR)/config.h
$(OBJDIR)/visualization.o: $(SRCDIR)/visualization.c $(INCDIR)/visualization.h $(INCDIR)/data_generator.h
$(OBJDIR)/alarm.o: $(SRCDIR)/alarm.c $(INCDIR)/alarm.h $(INCDIR)/data_generator.h $(INCDIR)/config.h
$(OBJDIR)/config.o: $(SRCDIR)/config.c $(INCDIR)/config.h

# Build test executable
$(TEST_TARGET): $(TEST_OBJECTS) $(LIB_OBJECTS)
	$(CC) $(TEST_OBJECTS) $(LIB_OBJECTS) -o $(TEST_TARGET) -lm

# Build test object files
$(TESTOBJDIR)/%.o: $(TESTDIR)/%.c $(HEADERS) | $(TESTOBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Test target - build and run tests
test: $(TEST_TARGET)
	@echo "Running alarm system unit tests..."
	./$(TEST_TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TESTOBJDIR) $(TARGET) $(TEST_TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Build the project (default)"
	@echo "  test       - Build and run unit tests"
	@echo "  clean      - Remove build artifacts"
	@echo "  run        - Build and run the data generator"
	@echo "  help       - Show this help message"

# Declare phony targets
.PHONY: all clean run test help