#include <stdio.h>
#include "../include/data_generator.h"

/**
 * @file visualization.c
 * @brief Contains functions for visualizing glucose data.
 */

/**
 * @brief Prints the glucose data to the terminal.
 *
 * This function displays the current glucose data, including the timestamp,
 * glucose value, and glucose history.
 *
 * @param data Pointer to the GeneratedData structure to print.
 * @return 0 on success, -1 on error.
 */
int print_glucose_data(const GeneratedData* data) {
    if (data == NULL) return -1;

    printf("\n--- Glucose Data ---\n");
    printf("Timestamp: %s\n", data->timestamp);
    printf("Glucose Value: %.1f mg/dL\n", data->glucose_value);
    printf("Glucose History (last 24 hours):\n");
    
    for (int i = 0; i < 24; i++) {
        printf("%.1f ", data->glucose_history[i]);
    }
    
    printf("\n--------------------\n");
    
    return 0;
}
