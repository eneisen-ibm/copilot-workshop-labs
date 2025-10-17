#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold generated glucose data
typedef struct {
    char timestamp[32];           // ISO timestamp of the reading
    double glucose_value;         // Current glucose value in mg/dL
    double glucose_history[24];   // Glucose values over the past 24 hours
} GeneratedData;

/**
 * @file data_generator.h
 * @brief Header file for glucose data generation functions.
 * 
 * This module provides functionality to generate realistic glucose data
 * with simulated anomalies for testing and demonstration purposes.
 */

/**
 * @brief Initializes the data generator.
 *
 * Seeds the random number generator to ensure unique data generation.
 * 
 * @return 0 on success, -1 on error.
 */
int initialize_data_generator(void);

/**
 * @brief Generates a new set of glucose data.
 *
 * This function creates a random glucose value and updates the
 * glucose history.
 *
 * @param data Pointer to the GeneratedData structure to populate.
 * @return 0 on success, -1 on error.
 */
int generate_glucose_data(GeneratedData* data);

#endif // DATA_GENERATOR_H
