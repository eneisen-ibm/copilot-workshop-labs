# Lab 1: Getting Started with GitHub Copilot

## Patient Vitals Monitoring System

Welcome to the first lab of the GitHub Copilot workshop! This project demonstrates building a simple CLI application in C that monitors patient vital signs and alerts on abnormal values.

### Project Overview

This CLI program reads a CSV file containing synthetic patient vitals data (timestamp, heart rate, SpO2, and temperature), parses each row into a structured format, validates the values against normal ranges, and prints alerts for any abnormal readings.


## 🏥 **Normal Ranges**

The system monitors the following vital signs:

| Vital Sign | Normal Range | Alert Conditions |
|------------|--------------|------------------|
| Heart Rate | 50-110 bpm  | <50 (Bradycardia), >110 (Tachycardia) |
| SpO2       | ≥92%         | <92% (Hypoxemia) |
| Temperature| 35.0-38.0°C  | <35.0°C (Hypothermia), >38.0°C (Hyperthermia) |

## � **Building and Running**

### Prerequisites
- GCC compiler
- Make build system

### Quick Start
1. **Validate Setup**: Run the validation script to ensure everything is configured correctly:
   ```bash
   ./validate_setup.sh
   ```

2. **Build and Run**: Use the Makefile to build and execute:
   ```bash
   make run
   ```

### Available Make Targets
- `make` or `make all` - Build the project
- `make clean` - Remove build artifacts
- `make run` - Build and run with default data
- `make run-file FILE=path/to/file.csv` - Run with custom CSV file
- `make validate` - Validate the complete setup
- `make help` - Show help message

### Manual Build and Execution
```bash
make
./vitals_cli [csv_file]
```

## �📋 **Expected Output**

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

## 🏗️ **Project Structure**

```
new_vitals_analysis/
├── README.md               # Project documentation
├── Makefile               # Build configuration
├── validate_setup.sh      # Setup validation script
├── vitals_cli             # Compiled executable (after build)
├── data/
│   └── sample_vitals.csv  # Sample vitals data
├── include/               # Header files
│   ├── vitals_constants.h # Constants and thresholds
│   ├── string_utils.h     # String parsing utilities
│   └── vitals.h           # Core vitals structures and functions
├── src/                   # Source files
│   ├── vitals.c           # Main program and file processing
│   ├── parser.c           # CSV parsing logic
│   ├── validator.c        # Vitals validation and alerting
│   ├── alerts.c           # Alert formatting and display
│   └── string_utils.c     # String utility implementations
└── obj/                   # Object files (created during build)
```

## 📊 **CSV File Format**

The program expects CSV files with the following format:
```csv
ts,heart_rate,spo2,temp_c
2025-09-30T08:00:00Z,78,98,36.8
2025-09-30T08:05:00Z,121,95,37.1
```

- `ts`: ISO 8601 timestamp
- `heart_rate`: Heart rate in beats per minute (integer)
- `spo2`: Oxygen saturation percentage (integer)
- `temp_c`: Temperature in Celsius (decimal)

