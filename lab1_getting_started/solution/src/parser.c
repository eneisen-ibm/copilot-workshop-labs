#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vitals.h"
#include "vitals_constants.h"
#include "string_utils.h"

/**
 * @brief Parse a CSV line into a Vitals structure
 * 
 * Safely parses a comma-separated line with bounds checking.
 * Expected format: timestamp,heart_rate,spo2,temp_c
 */
int parse_vitals_line(const char *line, Vitals *out) {
    if (!line || !out) {
        return VITALS_ERROR_INVALID;
    }
    
    // Create a working copy of the line for tokenization
    char line_copy[MAX_LINE_LENGTH];
    if (strlen(line) >= sizeof(line_copy)) {
        fprintf(stderr, "Error: Line too long (max %d chars)\n", MAX_LINE_LENGTH - 1);
        return VITALS_ERROR_OVERFLOW;
    }
    
    // Safe string copy instead of strcpy
    if (safe_string_copy(line_copy, line, sizeof(line_copy)) != VITALS_SUCCESS) {
        fprintf(stderr, "Error: Failed to copy input line\n");
        return VITALS_ERROR_OVERFLOW;
    }
    
    // Parse timestamp
    char *token = strtok(line_copy, ",");
    if (!token) {
        fprintf(stderr, "Error: Missing timestamp field\n");
        return VITALS_ERROR_PARSE;
    }
    
    // Safe timestamp copy with explicit bounds checking
    if (safe_string_copy(out->ts, token, sizeof(out->ts)) != VITALS_SUCCESS) {
        fprintf(stderr, "Error: Timestamp too long (max %d chars)\n", MAX_TIMESTAMP_LENGTH - 1);
        return VITALS_ERROR_OVERFLOW;
    }
    
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