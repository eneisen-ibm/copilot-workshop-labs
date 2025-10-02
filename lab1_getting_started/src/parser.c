#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vitals.h"

/**
 * @brief Parse a CSV line into a Vitals structure
 * 
 * Safely parses a comma-separated line with bounds checking.
 * Expected format: timestamp,heart_rate,spo2,temp_c
 */
int parse_vitals_line(const char *line, Vitals *out) {
    if (!line || !out) {
        return -1;
    }
    
    // Create a working copy of the line for tokenization
    char line_copy[256];
    if (strlen(line) >= sizeof(line_copy)) {
        fprintf(stderr, "Error: Line too long\n");
        return -1;
    }
    strcpy(line_copy, line);
    
    // Parse timestamp
    char *token = strtok(line_copy, ",");
    if (!token) {
        fprintf(stderr, "Error: Missing timestamp\n");
        return -1;
    }
    if (strlen(token) >= sizeof(out->ts)) {
        fprintf(stderr, "Error: Timestamp too long\n");
        return -1;
    }
    strcpy(out->ts, token);
    
    // Parse heart rate
    token = strtok(NULL, ",");
    if (!token) {
        fprintf(stderr, "Error: Missing heart rate\n");
        return -1;
    }
    char *endptr;
    out->heart_rate = (int)strtol(token, &endptr, 10);
    if (*endptr != '\0' || out->heart_rate < 0) {
        fprintf(stderr, "Error: Invalid heart rate: %s\n", token);
        return -1;
    }
    
    // Parse SpO2
    token = strtok(NULL, ",");
    if (!token) {
        fprintf(stderr, "Error: Missing SpO2\n");
        return -1;
    }
    out->spo2 = (int)strtol(token, &endptr, 10);
    if (*endptr != '\0' || out->spo2 < 0 || out->spo2 > 100) {
        fprintf(stderr, "Error: Invalid SpO2: %s\n", token);
        return -1;
    }
    
    // Parse temperature
    token = strtok(NULL, ",");
    if (!token) {
        fprintf(stderr, "Error: Missing temperature\n");
        return -1;
    }
    out->temp_c = strtof(token, &endptr);
    if (*endptr != '\0' && *endptr != '\n' && *endptr != '\r') {
        fprintf(stderr, "Error: Invalid temperature: %s\n", token);
        return -1;
    }
    
    return 0;
}