#!/bin/bash

# Vitals Analysis Setup Validation Script
echo "🏥 Validating Vitals Analysis Setup..."
echo "=================================="

# Check if we're in the right directory
if [ ! -f "README.md" ] || [ ! -d "data" ]; then
    echo "❌ Error: Please run this script from the new_vitals_analysis directory"
    exit 1
fi

# Check for required tools
echo "📋 Checking build environment..."
if ! command -v gcc &> /dev/null; then
    echo "❌ Error: gcc compiler not found"
    echo "   Please install gcc to compile the C program"
    exit 1
fi
echo "✅ gcc compiler found"

# Check data file
echo "📋 Checking data files..."
if [ ! -f "data/sample_vitals.csv" ]; then
    echo "❌ Error: sample_vitals.csv not found in data directory"
    exit 1
fi
echo "✅ Sample data file found"

# Clean any previous builds
echo "📋 Cleaning previous builds..."
make clean > /dev/null 2>&1

# Build the project
echo "📋 Building project..."
if ! make > /dev/null 2>&1; then
    echo "❌ Error: Build failed"
    echo "   Run 'make' to see detailed error messages"
    exit 1
fi
echo "✅ Project built successfully"

# Check if executable was created
if [ ! -f "vitals_cli" ]; then
    echo "❌ Error: vitals_cli executable not created"
    exit 1
fi
echo "✅ Executable created"

# Test run
echo "📋 Testing program execution..."
echo "Expected output should show 3 alerts (Tachycardia, Hypoxemia, Hyperthermia):"
echo "----------------------------------------"
./vitals_cli
echo "----------------------------------------"

# Verify basic functionality
if ./vitals_cli > /dev/null 2>&1; then
    echo "✅ Program executed without errors"
else
    echo "❌ Error: Program execution failed"
    exit 1
fi

echo ""
echo "🎉 Setup validation completed successfully!"
echo "✅ All components are working correctly"
echo ""
echo "You can now:"
echo "  • Run 'make run' to execute with default data"
echo "  • Run 'make run-file FILE=path/to/file.csv' with custom data"
echo "  • Run 'make help' to see all available commands"