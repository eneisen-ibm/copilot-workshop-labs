#include "../include/data_generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void initialize_data_generator(void) {
    srand((unsigned int)time(NULL));
}

void generate_vital_data(GeneratedData* data) {
    if (data == NULL) return;

    // Generate timestamp
    time_t now = time(NULL);
    struct tm* t = gmtime(&now);
    strftime(data->timestamp, sizeof(data->timestamp), "%Y-%m-%dT%H:%M:%SZ", t);

    // Generate random heart rate (40-130 bpm)
    data->heart_rate = 40 + rand() % 91;

    // Generate random SpO2 (85-100%)
    data->spo2 = 85 + rand() % 16;

    // Generate random temperature (34.0-39.0°C)
    data->temperature = 34.0 + ((double)(rand() % 51) / 10.0);

    // Generate random blood pressure (90-140 / 60-90 mmHg)
    data->systolic_bp = 90 + rand() % 51;
    data->diastolic_bp = 60 + rand() % 31;

    // Generate random respiratory rate (12-20 breaths per minute)
    data->respiratory_rate = 12 + rand() % 9;
}

void format_data_as_csv(const GeneratedData* data, char* buffer, size_t buffer_size) {
    if (data == NULL || buffer == NULL) return;

    snprintf(buffer, buffer_size, "%s,%d,%d,%.1f,%d,%d,%d", 
             data->timestamp, data->heart_rate, data->spo2, data->temperature,
             data->systolic_bp, data->diastolic_bp, data->respiratory_rate);
}

void simulate_anomalies(GeneratedData* data) {
    if (data == NULL) return;

    // Randomly introduce high blood pressure
    if (rand() % 10 == 0) {
        data->systolic_bp += 20;
        data->diastolic_bp += 10;
    }

    // Randomly introduce low respiratory rate
    if (rand() % 15 == 0) {
        data->respiratory_rate -= 5;
    }
}
