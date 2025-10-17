/**
 * @file alarm.c
 * @brief Contains functions for checking and handling glucose alarms.
 */

#include "../include/alarm.h"
#include "../include/config.h"
#include <stdio.h>


/**
 * @brief Checks and prints alarms based on glucose data and configuration.
 *
 * This function checks for hypoglycemia, hyperglycemia, and rapid changes
 * in glucose values using the provided configuration and prints appropriate alarms.
 *
 * @param data Pointer to the GeneratedData structure containing glucose data.
 * @param config Pointer to the Config structure containing thresholds.
 * @return 0 on success, -1 on error.
 */
int check_and_print_alarms(const GeneratedData* data, const Config* config) {
    if (data == NULL || config == NULL) return -1;

    // Check for hypoglycemia
    if (data->glucose_value < config->hypoglycemia_threshold) {
        printf("ALARM: Hypoglycemia detected! Glucose value: %.1f mg/dL\n", data->glucose_value);
    }

    // Check for hyperglycemia
    if (data->glucose_value > config->hyperglycemia_threshold) {
        printf("ALARM: Hyperglycemia detected! Glucose value: %.1f mg/dL\n", data->glucose_value);
    }

    // Check for rapid changes (only if we have previous data)
    if (data->glucose_history[1] != 0.0) {  // Ensure we have previous data
        double change = data->glucose_history[0] - data->glucose_history[1];
        
        if (change > config->rapid_change_threshold) {
            printf("ALARM: Rapid glucose increase detected!\n");
        } else if (change < -(config->rapid_change_threshold)) {
            printf("ALARM: Rapid glucose decrease detected!\n");
        }
    }
    
    return 0;
}
