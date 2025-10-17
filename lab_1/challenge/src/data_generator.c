/**
 * @file data_generator.c
 * @brief Contains functions for generating glucose data and simulating anomalies.
 */

#include "../include/data_generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * @brief Initializes the data generator by seeding the random number generator.
 * 
 * @return 0 on success, -1 on error.
 */
int initialize_data_generator(void) {
    srand((unsigned int)time(NULL));
    return 0;
}

/**
 * @brief Generates a new set of glucose data and updates the glucose history.
 *
 * This function generates a random glucose value and updates the glucose
 * history array by shifting older values and adding the new value at the beginning.
 *
 * @param data Pointer to the GeneratedData structure to populate.
 * @return 0 on success, -1 on error.
 */
int generate_glucose_data(GeneratedData* data) {
    if (data == NULL) return -1;

    // Generate timestamp
    time_t now = time(NULL);
    struct tm* t = gmtime(&now);
    strftime(data->timestamp, sizeof(data->timestamp), "%Y-%m-%dT%H:%M:%SZ", t);

    // Generate glucose value with increased chance of anomalies
    int anomaly_chance = rand() % 10; // 0-9
    
    if (anomaly_chance < 3) {
        // 30% chance of hypoglycemia (glucose < 70 mg/dL)
        data->glucose_value = 40 + ((double)(rand() % 30)); // 40-69 mg/dL
    } else if (anomaly_chance < 6) {
        // 30% chance of hyperglycemia (glucose > 180 mg/dL)
        data->glucose_value = 180 + ((double)(rand() % 70)); // 180-249 mg/dL
    } else {
        // 40% chance of normal glucose (70-180 mg/dL)
        data->glucose_value = 70 + ((double)(rand() % 111)); // 70-180 mg/dL
    }

    // Add some random variation for more realistic readings
    if (rand() % 5 == 0) {
        // 20% chance of adding small random variation
        data->glucose_value += (rand() % 21) - 10; // ±10 mg/dL variation
        
        // Ensure we don't go below 30 or above 400
        if (data->glucose_value < 30) data->glucose_value = 30;
        if (data->glucose_value > 400) data->glucose_value = 400;
    }

    // Shift glucose history to make room for the new value
    for (int i = 29; i > 0; i--) {
        data->glucose_history[i] = data->glucose_history[i - 1];
    }

    // Add the new glucose value to the history
    data->glucose_history[0] = data->glucose_value;
    
    return 0;
}
