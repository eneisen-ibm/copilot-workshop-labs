# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g -O2
INCLUDES = -Iinclude

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj

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

# Default target
all: $(TARGET)

# Create object directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

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
$(OBJDIR)/analysis.o: $(SRCDIR)/analysis.c $(INCDIR)/analysis.h $(INCDIR)/data_generator.h
$(OBJDIR)/visualization.o: $(SRCDIR)/visualization.c $(INCDIR)/visualization.h $(INCDIR)/data_generator.h
$(OBJDIR)/alarm.o: $(SRCDIR)/alarm.c $(INCDIR)/alarm.h $(INCDIR)/data_generator.h $(INCDIR)/config.h
$(OBJDIR)/config.o: $(SRCDIR)/config.c $(INCDIR)/config.h

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Build the project (default)"
	@echo "  clean      - Remove build artifacts"
	@echo "  run        - Build and run the data generator"
	@echo "  help       - Show this help message"

# Declare phony targets
.PHONY: all clean run help