#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "data_generator.h"
#include "config.h"

/**
 * @file analysis.h
 * @brief Header file for glucose data analysis functions.
 */

// Enum to represent glucose trend direction
typedef enum {
    TREND_RISING,      // ↑ Glucose increasing
    TREND_STABLE,      // → Glucose stable
    TREND_FALLING      // ↓ Glucose decreasing
} GlucoseTrend;

// Structure to hold glucose statistics
typedef struct {
    double time_in_range; // Percentage of time in target range (configurable)
    double time_below_range; // Percentage of time below target range (configurable)
    double time_above_range; // Percentage of time above target range (configurable)
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
int initialize_glucose_statistics(GlucoseStats* stats);

/**
 * @brief Updates the glucose statistics with new data.
 *
 * This function calculates the time in range, below range, and above range,
 * updates the average glucose value, and computes glucose variability.
 *
 * @param stats Pointer to the GlucoseStats structure to update.
 * @param data Pointer to the GeneratedData structure containing new data.
 * @param config Pointer to the Config structure containing threshold values.
 * @return 0 on success, -1 on error.
 */
int update_glucose_statistics(GlucoseStats* stats, const GeneratedData* data, const Config* config);

/**
 * @brief Prints the glucose statistics to the terminal.
 *
 * This function displays the calculated glucose statistics, including time
 * in range, below range, above range, average glucose, and variability.
 *
 * @param stats Pointer to the GlucoseStats structure to print.
 * @return 0 on success, -1 on error.
 */
int print_glucose_statistics(const GlucoseStats* stats);

/**
 * @brief Calculate simple glucose trend
 * 
 * Compares current glucose value with previous reading to determine
 * if glucose is rising, falling, or stable. Uses a threshold of ±5 mg/dL
 * to determine stability.
 * 
 * @param data Pointer to glucose data with history
 * @return GlucoseTrend indicating direction (RISING, STABLE, or FALLING)
 */
GlucoseTrend calculate_glucose_trend(const GeneratedData* data);

#endif // ANALYSIS_H
