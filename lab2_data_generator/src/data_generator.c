#include "../include/data_generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void initialize_data_generator() {
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
}

void format_data_as_csv(const GeneratedData* data, char* buffer, size_t buffer_size) {
    if (data == NULL || buffer == NULL) return;

    snprintf(buffer, buffer_size, "%s,%d,%d,%.1f", 
             data->timestamp, data->heart_rate, data->spo2, data->temperature);
}