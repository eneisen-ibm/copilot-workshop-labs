#!/bin/bash

# Validation script for GitHub Copilot C Workshop
# This script verifies that the development environment is properly set up

echo "🔍 Validating Workshop Environment..."
echo "=================================="

# Check if we're in the right directory
if [ ! -f "Makefile" ] || [ ! -f "src/vitals.c" ]; then
    echo "❌ Error: Please run this script from the lab1_getting_started directory"
    exit 1
fi

# Test 1: Check GCC compiler
echo -n "✓ Testing GCC compiler... "
if command -v gcc >/dev/null 2>&1; then
    GCC_VERSION=$(gcc --version | head -n1)
    echo "✅ Found: $GCC_VERSION"
else
    echo "❌ GCC not found!"
    exit 1
fi

# Test 2: Check Make
echo -n "✓ Testing Make... "
if command -v make >/dev/null 2>&1; then
    MAKE_VERSION=$(make --version | head -n1)
    echo "✅ Found: $MAKE_VERSION"
else
    echo "❌ Make not found!"
    exit 1
fi

# Test 3: Build the project
echo -n "✓ Testing project build... "
if make clean >/dev/null 2>&1 && make >/dev/null 2>&1; then
    echo "✅ Build successful"
else
    echo "❌ Build failed!"
    exit 1
fi

# Test 4: Check if executable was created
echo -n "✓ Testing executable creation... "
if [ -x "vitals_cli" ]; then
    echo "✅ Executable 'vitals_cli' created"
else
    echo "❌ Executable not found!"
    exit 1
fi

# Test 5: Test program execution
echo -n "✓ Testing program execution... "
OUTPUT=$(./vitals_cli data/sample_vitals.csv 2>&1)
EXIT_CODE=$?
if [ $EXIT_CODE -eq 3 ] && echo "$OUTPUT" | grep -q "ALERT"; then
    echo "✅ Program runs successfully (found alerts as expected)"
else
    echo "❌ Program execution failed! (Exit code: $EXIT_CODE)"
    exit 1
fi

# Test 6: Check for sample data
echo -n "✓ Testing sample data... "
if [ -f "data/sample_vitals.csv" ]; then
    LINES=$(wc -l < data/sample_vitals.csv)
    echo "✅ Sample CSV found ($LINES lines)"
else
    echo "❌ Sample data not found!"
    exit 1
fi

echo ""
echo "🎉 Environment Validation Complete!"
echo "=================================="
echo "✅ All tests passed - you're ready for the workshop!"
echo ""
echo "Quick commands to try:"
echo "  make            # Build the project"
echo "  make run        # Build and run with sample data"
echo "  make clean      # Clean build artifacts"
echo "  make help       # Show all available targets"
echo ""
echo "Happy coding with GitHub Copilot! 🚀"