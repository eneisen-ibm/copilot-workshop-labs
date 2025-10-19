#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "data_generator.h"

// analysis.h
// Header file for glucose data analysis functions.

// Structure to hold glucose statistics
typedef struct {
    double time_in_range; // Percentage of time in range (70-180 mg/dL)
    double time_below_range; // Percentage of time below range (<70 mg/dL)
    double time_above_range; // Percentage of time above range (>180 mg/dL)
    double avg_glucose; // Average glucose value
    double glucose_variability; // Standard deviation of glucose values
} GlucoseStats;

// Initializes the glucose statistics structure.
// Sets all fields of the glucose statistics structure to their initial values.
// stats: Pointer to the GlucoseStats structure to initialize.
// Returns 0 on success, -1 on error.
int initialize_glucose_statistics();

// Updates the glucose statistics with new data.
// Calculates the time in range, below range, and above range, updates the average glucose value, and computes glucose variability.
// stats: Pointer to the GlucoseStats structure to update.
// data: Pointer to the GeneratedData structure containing new data.
// Returns 0 on success, -1 on error.
int update_glucose_statistics();

// Prints the glucose statistics to the terminal.
// Displays the calculated glucose statistics, including time in range, below range, above range, average glucose, and variability.
// stats: Pointer to the GlucoseStats structure to print.
// Returns 0 on success, -1 on error.
int print_glucose_statistics();

#endif // ANALYSIS_H
