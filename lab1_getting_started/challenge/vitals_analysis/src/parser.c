#include "../include/vitals.h"
#include "../include/vitals_constants.h"
#include "../include/string_utils.h"
#include <string.h>

int parse_vitals_line(char* line, VitalSigns* vitals) {
    if (line == NULL || vitals == NULL) {
        return 0;
    }
    
    // Skip empty lines or lines starting with whitespace/comments
    char* trimmed = trim_whitespace(line);
    if (strlen(trimmed) == 0 || trimmed[0] == '#') {
        return 0;
    }
    
    // Split the CSV line
    char* fields[4];
    int field_count = split_csv_line(line, ',', fields, 4);
    
    if (field_count != 4) {
        return 0;  // Invalid number of fields
    }
    
    // Parse timestamp (just copy as string)
    strncpy(vitals->timestamp, fields[CSV_TIMESTAMP_COL], sizeof(vitals->timestamp) - 1);
    vitals->timestamp[sizeof(vitals->timestamp) - 1] = '\0';
    
    // Parse heart rate
    if (!safe_str_to_int(fields[CSV_HEART_RATE_COL], &vitals->heart_rate)) {
        return 0;
    }
    
    // Parse SpO2
    if (!safe_str_to_int(fields[CSV_SPO2_COL], &vitals->spo2)) {
        return 0;
    }
    
    // Parse temperature
    if (!safe_str_to_double(fields[CSV_TEMP_COL], &vitals->temperature)) {
        return 0;
    }
    
    return 1;  // Success
}