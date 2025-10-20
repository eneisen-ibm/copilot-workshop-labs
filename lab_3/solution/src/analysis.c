/**
 * @file analysis.c
 * @brief Contains functions for analyzing glucose data.
 */

#include "../include/analysis.h"
#include <stdio.h>
#include <math.h> 
#include <string.h>

/**
 * @brief Initializes the glucose statistics structure.
 *
 * This function sets all fields of the glucose statistics structure to their
 * initial values.
 *
 * @param stats Pointer to the GlucoseStats structure to initialize.
 * @return 0 on success, -1 on error.
 */
int initialize_glucose_statistics(GlucoseStats* stats) {
    if (stats == NULL) return -1;

    stats->time_in_range = 0;
    stats->time_below_range = 0;
    stats->time_above_range = 0;
    stats->avg_glucose = 0.0;
    stats->glucose_variability = 0.0;
    
    return 0;
}

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
int update_glucose_statistics(GlucoseStats* stats, const GeneratedData* data, const Config* config) {
    if (stats == NULL || data == NULL || config == NULL) return -1;

    // Calculate time in range, below range, and above range using config thresholds
    if (data->glucose_value < config->hypoglycemia_threshold) {
        stats->time_below_range++;
    } else if (data->glucose_value > config->hyperglycemia_threshold) {
        stats->time_above_range++;
    } else {
        stats->time_in_range++;
    }

    // Update average glucose
    int total_readings = stats->time_in_range + stats->time_below_range + stats->time_above_range;
    if (total_readings > 0) {
        stats->avg_glucose = ((stats->avg_glucose * (total_readings - 1)) + data->glucose_value) / total_readings;
        
        // Update glucose variability (standard deviation)
        double diff = data->glucose_value - stats->avg_glucose;
        stats->glucose_variability += diff * diff;
    }
    
    return 0;
}

/**
 * @brief Prints the glucose statistics to the terminal.
 *
 * This function displays the calculated glucose statistics, including time
 * in range, below range, above range, average glucose, and variability.
 *
 * @param stats Pointer to the GlucoseStats structure to print.
 * @return 0 on success, -1 on error.
 */
int print_glucose_statistics(const GlucoseStats* stats) {
    if (stats == NULL) return -1;

    int total_readings = stats->time_in_range + stats->time_below_range + stats->time_above_range;
    
    printf("\n--- Glucose Statistics ---\n");
    
    if (total_readings > 0) {
        double tir_percent = (double)stats->time_in_range / total_readings * 100.0;
        double tbr_percent = (double)stats->time_below_range / total_readings * 100.0;
        double tar_percent = (double)stats->time_above_range / total_readings * 100.0;
        double variability = sqrt(stats->glucose_variability / total_readings);
        
        printf("Time in Range: %.2f%%\n", tir_percent);
        printf("Time Below Range: %.2f%%\n", tbr_percent);
        printf("Time Above Range: %.2f%%\n", tar_percent);
        printf("Average Glucose: %.2f mg/dL\n", stats->avg_glucose);
        printf("Glucose Variability: %.2f\n", variability);
    } else {
        printf("No data available yet\n");
    }
    
    printf("---------------------------\n\n");
    
    return 0;
}

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
GlucoseTrend calculate_glucose_trend(const GeneratedData* data) {
    if (data == NULL) {
        return TREND_STABLE; // Default to stable on error
    }
    
    // Compare current value with the most recent previous value
    // glucose_history[0] is the current value, glucose_history[1] is previous
    double current_glucose = data->glucose_value;
    double previous_glucose = data->glucose_history[1];
    
    // Calculate the change
    double change = current_glucose - previous_glucose;
    
    // Define stability threshold
    const double STABILITY_THRESHOLD = 5.0; // mg/dL
    
    // Determine trend based on change
    if (change > STABILITY_THRESHOLD) {
        return TREND_RISING;
    } else if (change < -STABILITY_THRESHOLD) {
        return TREND_FALLING;
    } else {
        return TREND_STABLE;
    }
}
