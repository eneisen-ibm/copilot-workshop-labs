#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold generated vital signs
typedef struct {
    char timestamp[32];
    int heart_rate;
    int spo2;
    double temperature;
    int systolic_bp;  // Systolic Blood Pressure
    int diastolic_bp; // Diastolic Blood Pressure
    int respiratory_rate; // Respiratory Rate
} GeneratedData;

/**
 * Initializes the data generator (e.g., seeds the random number generator).
 */
void initialize_data_generator(void);

/**
 * Generates a single set of vital signs data.
 * @param data Pointer to a GeneratedData structure to fill.
 */
void generate_vital_data(GeneratedData* data);

/**
 * Formats the generated data as a CSV line.
 * @param data Pointer to the GeneratedData structure.
 * @param buffer Buffer to store the formatted CSV line.
 * @param buffer_size Size of the buffer.
 */
void format_data_as_csv(const GeneratedData* data, char* buffer, size_t buffer_size);

/**
 * Simulates anomalies in the generated data.
 * @param data Pointer to the GeneratedData structure to modify.
 */
void simulate_anomalies(GeneratedData* data);

#endif // DATA_GENERATOR_H
