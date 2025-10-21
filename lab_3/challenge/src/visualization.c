#include <stdio.h>
#include "../include/data_generator.h"
#include "../include/analysis.h"

/**
 * @file visualization.c
 * @brief Contains functions for visualizing glucose data.
 */

/**
 * @brief Prints the glucose data to the terminal.
 *
 * This function displays the current glucose data, including the timestamp,
 * glucose value, trend indicator, and glucose history.
 *
 * @param data Pointer to the GeneratedData structure to print.
 * @return 0 on success, -1 on error.
 */
int print_glucose_data(const GeneratedData* data) {
    if (data == NULL) return -1;

    // Calculate trend
    GlucoseTrend trend = calculate_glucose_trend(data);
    
    // Calculate rate of change
    double current_glucose = data->glucose_value;
    double previous_glucose = data->glucose_history[0];
    double change = current_glucose - previous_glucose;
    
    // Get trend arrow and description
    const char* trend_arrow;
    const char* trend_description;
    
    switch (trend) {
        case TREND_RISING:
            trend_arrow = "↑";
            trend_description = "Rising";
            break;
        case TREND_FALLING:
            trend_arrow = "↓";
            trend_description = "Falling";
            break;
        case TREND_STABLE:
        default:
            trend_arrow = "→";
            trend_description = "Stable";
            break;
    }
    
    printf("\n--- Glucose Data ---\n");
    printf("Timestamp: %s\n", data->timestamp);
    printf("Glucose Value: %.1f mg/dL %s (%+.1f mg/dL)\n", 
           data->glucose_value, trend_arrow, change);
    printf("Trend: %s\n", trend_description);
    printf("Glucose History (last 30 entries):\n");
    
    for (int i = 0; i < 30; i++) {
        printf("%.1f ", data->glucose_history[i]);
    }
    
    printf("\n--------------------\n");
    
    return 0;
}
