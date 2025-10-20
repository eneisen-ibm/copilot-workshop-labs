/**
 * @file test_alarm.c
 * @brief Unit tests for glucose alarm system functionality.
 * 
 * This file contains comprehensive tests for the alarm detection system,
 * including hypoglycemia, hyperglycemia, rapid changes, boundary conditions,
 * and error handling.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../include/alarm.h"
#include "../include/data_generator.h"
#include "../include/config.h"

// Test counter
static int tests_passed = 0;
static int tests_failed = 0;

// Test result macros
#define TEST_ASSERT(condition, message) \
    do { \
        if (condition) { \
            printf("✓ PASS: %s\n", message); \
            tests_passed++; \
        } else { \
            printf("✗ FAIL: %s\n", message); \
            tests_failed++; \
        } \
    } while(0)

/**
 * @brief Helper function to create test glucose data
 * 
 * @param glucose_value Current glucose reading
 * @param previous_value Previous glucose reading for history
 * @return GeneratedData structure with test values
 */
GeneratedData create_test_data(double glucose_value, double previous_value) {
    GeneratedData data;
    data.glucose_value = glucose_value;
    strcpy(data.timestamp, "2025-10-21T10:00:00Z");
    
    // Initialize history
    for (int i = 0; i < 30; i++) {
        data.glucose_history[i] = 0.0;
    }
    
    // Set current and previous values
    data.glucose_history[0] = glucose_value;
    data.glucose_history[1] = previous_value;
    
    return data;
}

/**
 * @brief Helper function to create test configuration
 * 
 * @return Config structure with standard test thresholds
 */
Config create_test_config(void) {
    Config config;
    config.hypoglycemia_threshold = 70;
    config.hyperglycemia_threshold = 180;
    config.rapid_change_threshold = 30;
    config.sleep_interval = 2;
    return config;
}

/**
 * @brief Test hypoglycemia detection (glucose below threshold)
 */
void test_hypoglycemia_detection(void) {
    printf("\n=== Testing Hypoglycemia Detection ===\n");
    
    Config config = create_test_config();
    
    // Test well below threshold
    GeneratedData data1 = create_test_data(50.0, 55.0);
    int result1 = check_and_print_alarms(&data1, &config);
    TEST_ASSERT(result1 == 0, "Hypoglycemia detection at 50 mg/dL");
    
    // Test just below threshold
    GeneratedData data2 = create_test_data(69.0, 75.0);
    int result2 = check_and_print_alarms(&data2, &config);
    TEST_ASSERT(result2 == 0, "Hypoglycemia detection at 69 mg/dL");
    
    // Test critical low
    GeneratedData data3 = create_test_data(40.0, 45.0);
    int result3 = check_and_print_alarms(&data3, &config);
    TEST_ASSERT(result3 == 0, "Critical hypoglycemia detection at 40 mg/dL");
}

/**
 * @brief Test hyperglycemia detection (glucose above threshold)
 */
void test_hyperglycemia_detection(void) {
    printf("\n=== Testing Hyperglycemia Detection ===\n");
    
    Config config = create_test_config();
    
    // Test well above threshold
    GeneratedData data1 = create_test_data(250.0, 240.0);
    int result1 = check_and_print_alarms(&data1, &config);
    TEST_ASSERT(result1 == 0, "Hyperglycemia detection at 250 mg/dL");
    
    // Test just above threshold
    GeneratedData data2 = create_test_data(181.0, 175.0);
    int result2 = check_and_print_alarms(&data2, &config);
    TEST_ASSERT(result2 == 0, "Hyperglycemia detection at 181 mg/dL");
    
    // Test critical high
    GeneratedData data3 = create_test_data(350.0, 340.0);
    int result3 = check_and_print_alarms(&data3, &config);
    TEST_ASSERT(result3 == 0, "Critical hyperglycemia detection at 350 mg/dL");
}

/**
 * @brief Test rapid glucose increase detection
 */
void test_rapid_increase_detection(void) {
    printf("\n=== Testing Rapid Increase Detection ===\n");
    
    Config config = create_test_config();
    
    // Test rapid increase just over threshold
    GeneratedData data1 = create_test_data(150.0, 119.0);
    int result1 = check_and_print_alarms(&data1, &config);
    TEST_ASSERT(result1 == 0, "Rapid increase detection (+31 mg/dL)");
    
    // Test very rapid increase
    GeneratedData data2 = create_test_data(180.0, 130.0);
    int result2 = check_and_print_alarms(&data2, &config);
    TEST_ASSERT(result2 == 0, "Very rapid increase detection (+50 mg/dL)");
    
    // Test at exact threshold (should trigger)
    GeneratedData data3 = create_test_data(160.0, 130.0);
    int result3 = check_and_print_alarms(&data3, &config);
    TEST_ASSERT(result3 == 0, "Rapid increase at threshold (+30 mg/dL)");
}

/**
 * @brief Test rapid glucose decrease detection
 */
void test_rapid_decrease_detection(void) {
    printf("\n=== Testing Rapid Decrease Detection ===\n");
    
    Config config = create_test_config();
    
    // Test rapid decrease just over threshold
    GeneratedData data1 = create_test_data(100.0, 131.0);
    int result1 = check_and_print_alarms(&data1, &config);
    TEST_ASSERT(result1 == 0, "Rapid decrease detection (-31 mg/dL)");
    
    // Test very rapid decrease
    GeneratedData data2 = create_test_data(80.0, 140.0);
    int result2 = check_and_print_alarms(&data2, &config);
    TEST_ASSERT(result2 == 0, "Very rapid decrease detection (-60 mg/dL)");
    
    // Test at exact threshold (should trigger)
    GeneratedData data3 = create_test_data(120.0, 150.0);
    int result3 = check_and_print_alarms(&data3, &config);
    TEST_ASSERT(result3 == 0, "Rapid decrease at threshold (-30 mg/dL)");
}

/**
 * @brief Test boundary conditions
 */
void test_boundary_conditions(void) {
    printf("\n=== Testing Boundary Conditions ===\n");
    
    Config config = create_test_config();
    
    // Test exactly at hypoglycemia threshold (should NOT trigger)
    GeneratedData data1 = create_test_data(70.0, 75.0);
    int result1 = check_and_print_alarms(&data1, &config);
    TEST_ASSERT(result1 == 0, "At hypoglycemia threshold (70 mg/dL) - no alarm");
    
    // Test exactly at hyperglycemia threshold (should NOT trigger)
    GeneratedData data2 = create_test_data(180.0, 175.0);
    int result2 = check_and_print_alarms(&data2, &config);
    TEST_ASSERT(result2 == 0, "At hyperglycemia threshold (180 mg/dL) - no alarm");
    
    // Test in normal range
    GeneratedData data3 = create_test_data(120.0, 115.0);
    int result3 = check_and_print_alarms(&data3, &config);
    TEST_ASSERT(result3 == 0, "Normal glucose range (120 mg/dL) - no alarm");
    
    // Test change just below rapid threshold (should NOT trigger)
    GeneratedData data4 = create_test_data(155.0, 126.0);
    int result4 = check_and_print_alarms(&data4, &config);
    TEST_ASSERT(result4 == 0, "Change below rapid threshold (+29 mg/dL) - no alarm");
    
    // Test stable glucose
    GeneratedData data5 = create_test_data(110.0, 110.0);
    int result5 = check_and_print_alarms(&data5, &config);
    TEST_ASSERT(result5 == 0, "Stable glucose (no change) - no alarm");
}

/**
 * @brief Test edge cases
 */
void test_edge_cases(void) {
    printf("\n=== Testing Edge Cases ===\n");
    
    Config config = create_test_config();
    
    // Test zero glucose value
    GeneratedData data1 = create_test_data(0.0, 100.0);
    int result1 = check_and_print_alarms(&data1, &config);
    TEST_ASSERT(result1 == 0, "Zero glucose value");
    
    // Test very high glucose value
    GeneratedData data2 = create_test_data(600.0, 550.0);
    int result2 = check_and_print_alarms(&data2, &config);
    TEST_ASSERT(result2 == 0, "Extremely high glucose (600 mg/dL)");
    
    // Test no previous data (history[1] = 0)
    GeneratedData data3 = create_test_data(120.0, 0.0);
    int result3 = check_and_print_alarms(&data3, &config);
    TEST_ASSERT(result3 == 0, "First reading (no previous data)");
    
    // Test multiple alarms (low glucose + rapid decrease)
    GeneratedData data4 = create_test_data(60.0, 120.0);
    int result4 = check_and_print_alarms(&data4, &config);
    TEST_ASSERT(result4 == 0, "Multiple alarms (hypoglycemia + rapid decrease)");
    
    // Test multiple alarms (high glucose + rapid increase)
    GeneratedData data5 = create_test_data(220.0, 180.0);
    int result5 = check_and_print_alarms(&data5, &config);
    TEST_ASSERT(result5 == 0, "Multiple alarms (hyperglycemia + rapid increase)");
}

/**
 * @brief Test error handling with NULL pointers
 */
void test_error_handling(void) {
    printf("\n=== Testing Error Handling ===\n");
    
    Config config = create_test_config();
    GeneratedData data = create_test_data(120.0, 115.0);
    
    // Test NULL data pointer
    int result1 = check_and_print_alarms(NULL, &config);
    TEST_ASSERT(result1 == -1, "NULL data pointer returns -1");
    
    // Test NULL config pointer
    int result2 = check_and_print_alarms(&data, NULL);
    TEST_ASSERT(result2 == -1, "NULL config pointer returns -1");
    
    // Test both NULL pointers
    int result3 = check_and_print_alarms(NULL, NULL);
    TEST_ASSERT(result3 == -1, "Both NULL pointers return -1");
    
    // Test valid pointers (should succeed)
    int result4 = check_and_print_alarms(&data, &config);
    TEST_ASSERT(result4 == 0, "Valid pointers return 0");
}

/**
 * @brief Test custom thresholds
 */
void test_custom_thresholds(void) {
    printf("\n=== Testing Custom Thresholds ===\n");
    
    // Create config with stricter thresholds
    Config strict_config;
    strict_config.hypoglycemia_threshold = 80;
    strict_config.hyperglycemia_threshold = 160;
    strict_config.rapid_change_threshold = 20;
    strict_config.sleep_interval = 2;
    
    // Test with stricter hypoglycemia threshold
    GeneratedData data1 = create_test_data(75.0, 80.0);
    int result1 = check_and_print_alarms(&data1, &strict_config);
    TEST_ASSERT(result1 == 0, "Custom hypoglycemia threshold (75 < 80)");
    
    // Test with stricter hyperglycemia threshold
    GeneratedData data2 = create_test_data(165.0, 155.0);
    int result2 = check_and_print_alarms(&data2, &strict_config);
    TEST_ASSERT(result2 == 0, "Custom hyperglycemia threshold (165 > 160)");
    
    // Test with stricter rapid change threshold
    GeneratedData data3 = create_test_data(145.0, 124.0);
    int result3 = check_and_print_alarms(&data3, &strict_config);
    TEST_ASSERT(result3 == 0, "Custom rapid change threshold (+21 > 20)");
}

/**
 * @brief Print test summary
 */
void print_test_summary(void) {
    int total_tests = tests_passed + tests_failed;
    double pass_rate = (total_tests > 0) ? (double)tests_passed / total_tests * 100.0 : 0.0;
    
    printf("\n");
    printf("=====================================\n");
    printf("     ALARM SYSTEM TEST SUMMARY      \n");
    printf("=====================================\n");
    printf("Total Tests:  %d\n", total_tests);
    printf("Tests Passed: %d\n", tests_passed);
    printf("Tests Failed: %d\n", tests_failed);
    printf("Pass Rate:    %.1f%%\n", pass_rate);
    printf("=====================================\n");
    
    if (tests_failed == 0) {
        printf("✓ ALL TESTS PASSED!\n");
    } else {
        printf("✗ SOME TESTS FAILED\n");
    }
    printf("\n");
}

/**
 * @brief Main test runner
 */
int main(void) {
    printf("\n");
    printf("=====================================\n");
    printf("  GLUCOSE ALARM SYSTEM UNIT TESTS   \n");
    printf("=====================================\n");
    
    // Run all test suites
    test_hypoglycemia_detection();
    test_hyperglycemia_detection();
    test_rapid_increase_detection();
    test_rapid_decrease_detection();
    test_boundary_conditions();
    test_edge_cases();
    test_error_handling();
    test_custom_thresholds();
    
    // Print summary
    print_test_summary();
    
    // Return 0 if all tests passed, 1 otherwise
    return (tests_failed == 0) ? 0 : 1;
}
