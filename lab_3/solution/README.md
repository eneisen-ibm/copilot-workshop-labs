# Lab: Glucose Monitoring System

## Overview
This program simulates a glucose monitoring device that generates synthetic glucose data in real-time and provides comprehensive analysis including statistics, visualizations, and alarm monitoring.

## Features

### 1. **Real-Time Glucose Data Generation**
   - Generates glucose readings every 2 seconds
   - Includes timestamps and glucose values in mg/dL
   - Maintains 24-hour glucose history
   - Simulates realistic anomalies (hypoglycemia and hyperglycemia)

### 2. **Statistical Analysis**
   - **Time in Range (TIR)**: Percentage of readings in target range (70-180 mg/dL)
   - **Time Below Range (TBR)**: Percentage below 70 mg/dL
   - **Time Above Range (TAR)**: Percentage above 180 mg/dL
   - **Average Glucose**: Running average of all readings
   - **Glucose Variability**: Standard deviation of glucose values

### 3. **Alarm System**
   - **Hypoglycemia Alarm**: Glucose < 70 mg/dL
   - **Hyperglycemia Alarm**: Glucose > 180 mg/dL
   - **Rapid Change Detection**: Sudden glucose fluctuations

### 4. **Modular Architecture**
   - Separate modules for data generation, analysis, visualization, and alarms
   - Configurable thresholds and parameters
   - Clean separation of concerns

## Usage

### Build the Program
```bash
make
```

### Run the Glucose Monitor
```bash
make run
```

### Clean Build Artifacts
```bash
make clean
```

## Example Output
```
Starting glucose data generation from controller...

--- Glucose Data ---
Timestamp: 2025-10-13T14:30:15Z
Glucose Value: 145.0 mg/dL
Glucose History (last 24 hours):
145.0 132.0 98.0 87.0 ...
--------------------

--- Glucose Statistics ---
Time in Range: 65.50%
Time Below Range: 20.00%
Time Above Range: 14.50%
Average Glucose: 125.30 mg/dL
Glucose Variability: 35.20
---------------------------

ALARM: Hyperglycemia detected! Glucose value: 210.5 mg/dL
```
## Project Structure
```
lab/
├── Makefile               # Build configuration
├── README.md              # Project documentation
├── include/
│   ├── data_generator.h   # Header for glucose data generation
│   ├── analysis.h         # Header for statistical analysis
│   ├── visualization.h    # Header for data visualization
│   ├── alarm.h           # Header for alarm system
│   ├── config.h          # Header for configuration management
│   └── controller.h      # Header for main controller logic
├── src/
│   ├── data_generator.c   # Glucose data generation implementation
│   ├── analysis.c         # Statistical analysis implementation
│   ├── visualization.c    # Data visualization implementation
│   ├── alarm.c           # Alarm system implementation
│   ├── config.c          # Configuration management
│   ├── controller.c      # Main controller logic
│   └── main.c            # Program entry point
└── obj/                  # Compiled object files (generated)
```

## Configuration
The system uses configurable parameters defined in `config.c`:
- **Hypoglycemia Threshold**: 70 mg/dL
- **Hyperglycemia Threshold**: 180 mg/dL
- **Rapid Change Threshold**: 30 mg/dL
- **Update Interval**: 2 seconds

## Technical Details
- **Language**: C99
- **Build System**: Make
- **Documentation**: Doxygen-style comments
- **Error Handling**: Consistent return codes (0 for success, -1 for error)
- **Memory Management**: Stack-allocated structures, no dynamic allocation

## Development Notes
This project demonstrates:
- Modular C programming with clean separation of concerns
- Real-time data simulation and processing
- Statistical analysis implementation
- Configurable alarm systems
- Professional code documentation and structure