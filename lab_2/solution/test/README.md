# Alarm System Unit Tests

## Overview
This directory contains comprehensive unit tests for the glucose alarm system. The tests verify all alarm detection functionality including hypoglycemia, hyperglycemia, rapid changes, boundary conditions, and error handling.

## Test Structure

### Test File: `test_alarm.c`
Contains all unit tests for the `check_and_print_alarms()` function from the alarm module.

## Test Coverage

### 1. Hypoglycemia Detection Tests
- Tests glucose values well below threshold (50 mg/dL)
- Tests glucose just below threshold (69 mg/dL)
- Tests critical low values (40 mg/dL)

### 2. Hyperglycemia Detection Tests
- Tests glucose values well above threshold (250 mg/dL)
- Tests glucose just above threshold (181 mg/dL)
- Tests critical high values (350 mg/dL)

### 3. Rapid Increase Detection Tests
- Tests rapid increases just over threshold (+31 mg/dL)
- Tests very rapid increases (+50 mg/dL)
- Tests exact threshold boundary (+30 mg/dL)

### 4. Rapid Decrease Detection Tests
- Tests rapid decreases just over threshold (-31 mg/dL)
- Tests very rapid decreases (-60 mg/dL)
- Tests exact threshold boundary (-30 mg/dL)

### 5. Boundary Condition Tests
- Tests exactly at hypoglycemia threshold (70 mg/dL)
- Tests exactly at hyperglycemia threshold (180 mg/dL)
- Tests normal glucose range (120 mg/dL)
- Tests changes just below rapid threshold (+29 mg/dL)
- Tests stable glucose (no change)

### 6. Edge Case Tests
- Zero glucose value
- Extremely high glucose (600 mg/dL)
- First reading with no previous data
- Multiple simultaneous alarms (low + rapid decrease)
- Multiple simultaneous alarms (high + rapid increase)

### 7. Error Handling Tests
- NULL data pointer validation
- NULL config pointer validation
- Both NULL pointers validation
- Valid pointers success verification

### 8. Custom Threshold Tests
- Tests with stricter hypoglycemia threshold (80 mg/dL)
- Tests with stricter hyperglycemia threshold (160 mg/dL)
- Tests with stricter rapid change threshold (20 mg/dL)

## Building and Running Tests

### Build Tests
```bash
make test
```

This command will:
1. Compile the test file and required library modules
2. Link them into the `test_alarm` executable
3. Automatically run all tests
4. Display test results and summary

### Clean Test Artifacts
```bash
make clean
```

Removes all test object files and executables.

## Test Output Format

### Individual Test Results
- ✓ PASS: Test description - indicates successful test
- ✗ FAIL: Test description - indicates failed test

### Test Summary
```
=====================================
     ALARM SYSTEM TEST SUMMARY      
=====================================
Total Tests:  XX
Tests Passed: XX
Tests Failed: XX
Pass Rate:    XX.X%
=====================================
✓ ALL TESTS PASSED!
```

## Understanding Test Results

### Success Criteria
- All tests should pass (100% pass rate)
- Return code 0 indicates success
- No failed tests in summary

### Failure Investigation
If tests fail:
1. Check the specific test that failed
2. Review the alarm detection logic in `src/alarm.c`
3. Verify threshold values in test configuration
4. Ensure alarm conditions match requirements

## Test Configuration

### Standard Test Thresholds
- **Hypoglycemia Threshold**: 70 mg/dL
- **Hyperglycemia Threshold**: 180 mg/dL
- **Rapid Change Threshold**: 30 mg/dL

### Custom Test Thresholds
- **Strict Hypoglycemia**: 80 mg/dL
- **Strict Hyperglycemia**: 160 mg/dL
- **Strict Rapid Change**: 20 mg/dL

## Medical Device Testing Considerations

### Safety-Critical Testing
These tests follow medical device testing best practices:
- **Comprehensive coverage** of all alarm conditions
- **Boundary testing** at exact threshold values
- **Edge case validation** for unusual scenarios
- **Error handling** for defensive programming
- **Multiple alarm scenarios** for complex situations

### Test Documentation
Each test includes:
- Clear description of what is being tested
- Expected behavior and outcomes
- Rationale for test values chosen
- Assertion of success criteria

## Extending the Tests

### Adding New Tests
To add new test scenarios:
1. Create a new test function following the naming pattern `test_*`
2. Use the `TEST_ASSERT` macro for assertions
3. Call the new test function from `main()`
4. Document the test in this README

### Test Helper Functions
- `create_test_data()` - Creates GeneratedData with specific values
- `create_test_config()` - Creates Config with standard thresholds
- `TEST_ASSERT()` - Macro for test assertions with automatic counting

## Continuous Integration

These tests are designed to be integrated into CI/CD pipelines:
- Return code 0 on success, 1 on failure
- Clear pass/fail output for parsing
- Comprehensive summary for reporting
- Fast execution time

## Troubleshooting

### Common Issues

**Issue**: Tests compile but fail to run
- **Solution**: Ensure all dependencies are built (`make all` first)

**Issue**: Segmentation fault during test execution
- **Solution**: Check for NULL pointer handling in alarm.c

**Issue**: Tests pass locally but fail in CI
- **Solution**: Verify floating-point comparison tolerances

## Best Practices

1. **Run tests frequently** during development
2. **Add tests** when fixing bugs
3. **Update tests** when requirements change
4. **Document test failures** for investigation
5. **Maintain 100% pass rate** before merging code

## References

- Alarm System Implementation: `../src/alarm.c`
- Alarm System Header: `../include/alarm.h`
- Configuration Module: `../include/config.h`
- Data Generator: `../include/data_generator.h`
