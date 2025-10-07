# Lab 1: Getting Started with GitHub Copilot

## Patient Vitals Monitoring System

Welcome to the first lab of the GitHub Copilot workshop! This project demonstrates building a simple CLI application in C that monitors patient vital signs and alerts on abnormal values.

### Project Overview

This CLI program reads a CSV file containing synthetic patient vitals data (timestamp, heart rate, SpO2, and temperature), parses each row into a structured format, validates the values against normal ranges, and prints alerts for any abnormal readings.

### Learning Objectives

- Practice C programming fundamentals (structs, file I/O, string parsing)
- Experience GitHub Copilot's assistance with:
  - Code completion and generation
  - Error handling patterns
  - Documentation and comments
  - Build system configuration

### Project Structure

```
lab1_getting_started/
├── .devcontainer/        # Dev Container configuration
│   ├── devcontainer.json # VS Code dev container settings
│   ├── Dockerfile        # Container environment setup
│   └── README.md         # Dev container instructions
├── src/
│   ├── vitals.c          # Main function and program entry point
│   ├── parser.c          # CSV parsing functionality
│   ├── validator.c       # Vitals validation logic
│   └── alerts.c          # Alert generation and printing
├── include/
│   └── vitals.h          # Header with struct and function declarations
├── data/
│   └── sample_vitals.csv # Sample patient data
├── Makefile              # Build configuration
├── validate_setup.sh     # Environment validation script
└── README.md            # This file
```

## 🐳 **Quick Start with Dev Containers (Recommended)**

**Prerequisites:** VS Code + Dev Containers extension + Docker Desktop

1. **Open in Dev Container:**
   - Open this folder in VS Code
   - Click "Reopen in Container" when prompted
   - Wait for container to build (~2-3 minutes first time)

2. **Verify setup:**
   ```bash
   gcc --version && make --version  # Check tools are available
   ```

3. **Build and run:**
   ```bash
   make && ./vitals_cli data/sample_vitals.csv
   ```

**✅ Benefits:** Identical environment for all participants, no local setup needed!

## 💻 **Alternative: Local Development**

If you prefer local development, ensure you have:
- **GCC compiler** (`gcc --version`)
- **Make** (`make --version`) 
- **VS Code** with C/C++ and GitHub Copilot extensions

### Quick Start (Local)

1. **Build the program:**
   ```bash
   make
   ```

2. **Run with sample data:**
   ```bash
   ./vitals_cli data/sample_vitals.csv
   ```

## 🏥 **Normal Ranges**

The system monitors the following vital signs:

| Vital Sign | Normal Range | Alert Conditions |
|------------|--------------|------------------|
| Heart Rate | 50-110 bpm  | <50 (Bradycardia), >110 (Tachycardia) |
| SpO2       | ≥92%         | <92% (Hypoxemia) |
| Temperature| 35.0-38.0°C  | <35.0°C (Hypothermia), >38.0°C (Hyperthermia) |

## 📋 **Expected Output**

When you run the program, you should see:
```
Processing vitals from: data/sample_vitals.csv
Monitoring for abnormal values...

ALERT [2025-09-30T08:05:00Z]: TACHYCARDIA (HR: 121 bpm, normal: 50-110) 
ALERT [2025-09-30T08:10:00Z]: HYPOXEMIA (SpO2: 89%, normal: >=92%) 
ALERT [2025-09-30T08:15:00Z]: HYPERTHERMIA (Temp: 38.6°C, normal: 35.0-38.0°C) 

--- SUMMARY ---
Total records processed: 4
   Parse errors: 0
   Alerts generated: 3
   WARNING: Abnormal vitals detected
   ```

### Available Make Targets

- `make` or `make all` - Build the executable
- `make run` - Build and run with sample data
- `make clean` - Remove build artifacts
- `make help` - Show all available targets

### Modular Architecture

The code is organized into separate modules for better maintainability and understanding:

#### **Core Modules:**

| File | Purpose | Key Functions |
|------|---------|---------------|
| `src/vitals.c` | **Main Program** | `main()` - File processing and program flow |
| `src/parser.c` | **CSV Parsing** | `parse_vitals_line()` - Parse CSV data into structs |
| `src/validator.c` | **Data Validation** | `validate_vitals()` - Check against medical thresholds |
| `src/alerts.c` | **Alert System** | `print_alert_if_needed()` - Generate medical alerts |

#### **Shared Header:**
- `include/vitals.h` - Common struct definitions and function declarations

### File Descriptions

#### `include/vitals.h`
Defines the `Vitals` struct and function prototypes shared across all modules.

#### `src/vitals.c` - Main Program
- Program entry point with `main()` function
- Command-line argument processing
- File I/O operations and line-by-line processing
- Coordinates calls to parser, validator, and alert modules
- Summary reporting and exit code handling

#### `src/parser.c` - CSV Parser Module  
- Safe CSV parsing with robust error checking
- String tokenization and data type conversion
- Buffer overflow protection
- Input validation and error reporting

#### `src/validator.c` - Medical Validation Module
- Implements medical threshold checking
- Heart rate: 50-110 bpm (bradycardia/tachycardia detection)
- SpO2: ≥92% (hypoxemia detection)  
- Temperature: 35.0-38.0°C (hypothermia/hyperthermia detection)

#### `src/alerts.c` - Alert Generation Module
- Medical alert formatting with proper terminology
- Detailed alert messages showing abnormal values and normal ranges
- Formatted output for healthcare professionals

#### `data/sample_vitals.csv`
Sample dataset with:
- 1 normal reading
- 1 tachycardia case (high heart rate)
- 1 hypoxemia case (low SpO2)
- 1 hyperthermia case (high temperature)

### Error Handling

The program includes comprehensive error handling for:
- Missing or invalid command line arguments
- File access errors
- Malformed CSV data
- Out-of-range values
- Buffer overflow protection

### Exit Codes

- `0` - Success, all vitals normal
- `1` - Invalid command line usage
- `2` - Parse errors encountered
- `3` - Abnormal vitals detected

### Workshop Tips

When working through this lab with GitHub Copilot:

1. **Code Completion**: Try typing function signatures and let Copilot suggest implementations
2. **Error Handling**: Ask Copilot to help add robust error checking
3. **Documentation**: Use Copilot to generate function comments and documentation
4. **Testing**: Ask Copilot to suggest edge cases and test scenarios

### Extensions

Try these enhancements with Copilot's help:
- Add more vital signs (blood pressure, respiratory rate)
- Implement different alert severity levels
- Add JSON output format option
- Create unit tests for parsing functions
- Add configuration file for alert thresholds

---

**Happy coding with GitHub Copilot! 🚀**