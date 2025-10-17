#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "data_generator.h"

/**
 * @file analysis.h
 * @brief Header file for glucose data analysis functions.
 */

// Structure to hold glucose statistics
typedef struct {
    double time_in_range; // Percentage of time in range (70-180 mg/dL)
    double time_below_range; // Percentage of time below range (<70 mg/dL)
    double time_above_range; // Percentage of time above range (>180 mg/dL)
    double avg_glucose; // Average glucose value
    double glucose_variability; // Standard deviation of glucose values
} GlucoseStats;

/**
 * @brief Initializes the glucose statistics structure.
 *
 * This function sets all fields of the glucose statistics structure to their
 * initial values.
 *
 * @param stats Pointer to the GlucoseStats structure to initialize.
 * @return 0 on success, -1 on error.
 */
int initialize_glucose_statistics();

/**
 * @brief Updates the glucose statistics with new data.
 *
 * This function calculates the time in range, below range, and above range,
 * updates the average glucose value, and computes glucose variability.
 *
 * @param stats Pointer to the GlucoseStats structure to update.
 * @param data Pointer to the GeneratedData structure containing new data.
 * @return 0 on success, -1 on error.
 */
int update_glucose_statistics();

/**
 * @brief Prints the glucose statistics to the terminal.
 *
 * This function displays the calculated glucose statistics, including time
 * in range, below range, above range, average glucose, and variability.
 *
 * @param stats Pointer to the GlucoseStats structure to print.
 * @return 0 on success, -1 on error.
 */
int print_glucose_statistics();

#endif // ANALYSIS_H
