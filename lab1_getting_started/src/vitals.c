#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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

/**
 * @brief Validate vitals against normal ranges
 * 
 * Normal ranges:
 * - Heart rate: 50-110 bpm
 * - SpO2: >= 92%
 * - Temperature: 35.0-38.0°C
 */
int validate_vitals(const Vitals *v) {
    if (!v) {
        return -1;
    }
    
    int abnormal = 0;
    
    // Check heart rate
    if (v->heart_rate < 50 || v->heart_rate > 110) {
        abnormal = 1;
    }
    
    // Check SpO2
    if (v->spo2 < 92) {
        abnormal = 1;
    }
    
    // Check temperature
    if (v->temp_c < 35.0f || v->temp_c > 38.0f) {
        abnormal = 1;
    }
    
    return abnormal;
}

/**
 * @brief Print alert message if vitals are abnormal
 * 
 * Prints detailed information about which vitals are out of range.
 */
int print_alert_if_needed(const Vitals *v) {
    if (!v) {
        return -1;
    }
    
    int alert_printed = 0;
    
    printf("ALERT [%s]: ", v->ts);
    
    // Check heart rate
    if (v->heart_rate < 50) {
        printf("BRADYCARDIA (HR: %d bpm, normal: 50-110) ", v->heart_rate);
        alert_printed = 1;
    } else if (v->heart_rate > 110) {
        printf("TACHYCARDIA (HR: %d bpm, normal: 50-110) ", v->heart_rate);
        alert_printed = 1;
    }
    
    // Check SpO2
    if (v->spo2 < 92) {
        printf("HYPOXEMIA (SpO2: %d%%, normal: >=92%%) ", v->spo2);
        alert_printed = 1;
    }
    
    // Check temperature
    if (v->temp_c < 35.0f) {
        printf("HYPOTHERMIA (Temp: %.1f°C, normal: 35.0-38.0°C) ", v->temp_c);
        alert_printed = 1;
    } else if (v->temp_c > 38.0f) {
        printf("HYPERTHERMIA (Temp: %.1f°C, normal: 35.0-38.0°C) ", v->temp_c);
        alert_printed = 1;
    }
    
    if (alert_printed) {
        printf("\n");
        return 1;
    }
    
    return 0;
}

/**
 * @brief Main function - processes CSV file and monitors vitals
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        fprintf(stderr, "Example: %s data/sample_vitals.csv\n", argv[0]);
        return 1;
    }
    
    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file '%s': %s\n", filename, strerror(errno));
        return 1;
    }
    
    printf("Processing vitals from: %s\n", filename);
    printf("Monitoring for abnormal values...\n\n");
    
    char line[256];
    int line_number = 0;
    int total_records = 0;
    int alert_count = 0;
    int parse_errors = 0;
    
    // Read file line by line
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        
        // Skip header line
        if (line_number == 1) {
            continue;
        }
        
        // Remove trailing newline
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        
        // Skip empty lines
        if (strlen(line) == 0) {
            continue;
        }
        
        Vitals vitals;
        if (parse_vitals_line(line, &vitals) != 0) {
            fprintf(stderr, "Parse error on line %d: %s\n", line_number, line);
            parse_errors++;
            continue;
        }
        
        total_records++;
        
        // Check if vitals are abnormal and print alert if needed
        if (validate_vitals(&vitals) == 1) {
            if (print_alert_if_needed(&vitals) == 1) {
                alert_count++;
            }
        }
    }
    
    fclose(file);
    
    // Print summary
    printf("\n--- SUMMARY ---\n");
    printf("Total records processed: %d\n", total_records);
    printf("Parse errors: %d\n", parse_errors);
    printf("Alerts generated: %d\n", alert_count);
    
    if (parse_errors > 0) {
        printf("WARNING: Some records could not be parsed\n");
        return 2;
    }
    
    if (alert_count > 0) {
        printf("WARNING: Abnormal vitals detected\n");
        return 3;
    }
    
    printf("All vitals within normal ranges\n");
    return 0;
}