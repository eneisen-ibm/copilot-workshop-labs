# Lab 2: Data Generator with Summary Statistics

## Overview
This program simulates a device that generates synthetic vital signs data in real-time and computes summary statistics over the generated data.

## Features
1. **Real-Time Data Generation**:
   - Generates vital signs data every 2 seconds.
   - Outputs data in CSV format:
     ```csv
     timestamp,heart_rate,spo2,temperature
     2025-10-07T12:00:00Z,78,98,36.8
     ```

2. **Summary Statistics**:
   - **Min/Max/Avg Heart Rate**
   - **Count of SpO2 readings below 92%**
   - **Count of fever episodes (temperature > 38.0°C)**

3. **Real-Time Updates**:
   - Continuously updates and displays statistics alongside generated data.

## Usage

### Build the Program
```bash
make
```

### Run the Data Generator
```bash
make run
```

### Clean Build Artifacts
```bash
make clean
```

## Example Output
```
Starting data generation...
2025-10-07T12:00:00Z,78,98,36.8

--- Summary Statistics ---
Min Heart Rate: 78 bpm
Max Heart Rate: 78 bpm
Avg Heart Rate: 78.00 bpm
SpO2 Below Threshold: 0 times
Fever Episodes: 0 times
---------------------------

2025-10-07T12:00:02Z,121,89,37.1

--- Summary Statistics ---
Min Heart Rate: 78 bpm
Max Heart Rate: 121 bpm
Avg Heart Rate: 99.50 bpm
SpO2 Below Threshold: 1 times
Fever Episodes: 0 times
---------------------------
```

## Project Structure
```
lab2_data_generator/
├── Makefile               # Build configuration
├── README.md              # Project documentation
├── include/
│   ├── data_generator.h   # Header for data generation functions
│   └── statistics.h       # Header for statistics computation
├── src/
│   ├── data_generator.c   # Implementation of data generation
│   ├── statistics.c       # Implementation of statistics computation
│   └── main.c             # Main program loop
```