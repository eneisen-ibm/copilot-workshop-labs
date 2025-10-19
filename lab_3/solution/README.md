# Lab 3 Solution: Glucose Monitoring System with Unit Testing

## Overview
This program simulates a glucose monitoring device that generates synthetic glucose data in real-time and provides comprehensive analysis including statistics, visualizations, and alarm monitoring. This solution includes a complete unit testing framework for the alarm system.

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

### 4. **Unit Testing Framework**
   - **Comprehensive Alarm Tests**: Complete test suite for alarm functionality
   - **Boundary Condition Testing**: Tests for threshold edge cases
   - **Error Handling Validation**: Tests for NULL pointers and invalid inputs
   - **Automated Test Execution**: Make targets for running tests

### 5. **Modular Architecture**
   - Separate modules for data generation, analysis, visualization, and alarms
   - Configurable thresholds and parameters
   - Clean separation of concerns
   - Testable components with clear interfaces

## Usage

### Build the Program
```bash
make
```

### Run the Glucose Monitor
```bash
make run
```

### Build and Run Unit Tests
```bash
make test
```

### Run Tests Only (if already built)
```bash
./test_alarm
```

### Clean Build Artifacts
```bash
make clean
```

## Testing

### Unit Test Coverage
The alarm system includes comprehensive unit tests that verify:

1. **Hypoglycemia Detection**:
   - Glucose values below 70 mg/dL trigger appropriate alarms
   - Boundary condition testing (exactly 70 mg/dL)
   - Multiple consecutive low readings

2. **Hyperglycemia Detection**:
   - Glucose values above 180 mg/dL trigger appropriate alarms
   - Boundary condition testing (exactly 180 mg/dL)
   - Multiple consecutive high readings

3. **Rapid Change Detection**:
   - Sudden glucose increases beyond threshold
   - Sudden glucose decreases beyond threshold
   - Normal fluctuations that should not trigger alarms

4. **Error Handling**:
   - NULL pointer validation
   - Invalid glucose values
   - Missing configuration data
   - Empty glucose history

### Test Execution
Run the test suite to verify alarm functionality:
```bash
make test
```

Expected output:
```
Running alarm system tests...

Testing hypoglycemia detection...
✓ Test 1: Low glucose (50 mg/dL) - PASSED
✓ Test 2: Boundary condition (70 mg/dL) - PASSED
✓ Test 3: Normal glucose (100 mg/dL) - PASSED

Testing hyperglycemia detection...
✓ Test 4: High glucose (250 mg/dL) - PASSED
✓ Test 5: Boundary condition (180 mg/dL) - PASSED
✓ Test 6: Normal glucose (150 mg/dL) - PASSED

Testing rapid change detection...
✓ Test 7: Rapid increase (+50 mg/dL) - PASSED
✓ Test 8: Rapid decrease (-50 mg/dL) - PASSED
✓ Test 9: Normal change (+10 mg/dL) - PASSED

Testing error handling...
✓ Test 10: NULL data pointer - PASSED
✓ Test 11: NULL config pointer - PASSED
✓ Test 12: Invalid glucose value - PASSED

All tests passed (12/12)
Alarm system functioning correctly.
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
ALARM: Rapid glucose increase detected!
```

### Unit Test Output
When running `make test`, you'll see comprehensive test results:
```
Running alarm system tests...
✓ All hypoglycemia detection tests passed (3/3)
✓ All hyperglycemia detection tests passed (3/3)  
✓ All rapid change detection tests passed (3/3)
✓ All error handling tests passed (3/3)
Total: 12/12 tests passed
```
## Project Structure
```
lab_3/solution/
├── Makefile               # Build configuration with test targets
├── README.md              # Project documentation
├── data_generator         # Compiled main executable
├── test_alarm            # Compiled test executable
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
├── test/
│   └── test_alarm.c      # Comprehensive unit tests for alarm system
├── test_obj/             # Test object files (generated)
├── obj/                  # Main program object files (generated)
└── docs/                 # Generated documentation (if built)
```

## Configuration
The system uses configurable parameters defined in `config.c`:
- **Hypoglycemia Threshold**: 70 mg/dL (tested with boundary conditions)
- **Hyperglycemia Threshold**: 180 mg/dL (tested with boundary conditions)
- **Rapid Change Threshold**: 30 mg/dL (tested with various scenarios)
- **Update Interval**: 2 seconds

## Quality Assurance

### Testing Strategy
This solution demonstrates comprehensive testing practices for medical device software:

1. **Functional Testing**: Verifies all alarm conditions work correctly
2. **Boundary Testing**: Tests edge cases at threshold values
3. **Error Handling**: Validates graceful handling of invalid inputs
4. **Regression Testing**: Ensures changes don't break existing functionality

### Test Categories
- **Unit Tests**: Individual function testing (alarm system)
- **Integration Tests**: Component interaction testing
- **Safety Tests**: Critical medical device functionality validation

## Technical Details
- **Language**: C99
- **Build System**: Make with separate test targets
- **Testing Framework**: Custom lightweight unit testing
- **Documentation**: Doxygen-style comments with test documentation
- **Error Handling**: Comprehensive input validation and error codes
- **Memory Management**: Stack-allocated structures, no dynamic allocation
- **Safety**: Medical device-grade error handling and validation

## Development Notes
This solution demonstrates professional practices including:
- Modular C programming with clean separation of concerns
- Real-time data simulation and processing
- Statistical analysis implementation
- Configurable alarm systems with comprehensive testing
- Professional code documentation and structure
- **Unit testing for medical device software**
- **Quality assurance and validation processes**
- **Defensive programming for safety-critical applications**

## Best Practices Demonstrated
1. **Test-Driven Development**: Tests validate all alarm functionality
2. **Boundary Condition Testing**: Critical for medical device safety
3. **Error Handling**: Comprehensive validation prevents system failures
4. **Documentation**: Clear explanations for maintainability
5. **Modular Design**: Testable, maintainable code structure