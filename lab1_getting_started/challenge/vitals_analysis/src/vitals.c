#include "../include/vitals.h"
#include "../include/vitals_constants.h"
#include "../include/string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_summary(const ProcessingStats* stats) {
    if (stats == NULL) return;
    
    printf("\n--- SUMMARY ---\n");
    printf("Total records processed: %d\n", stats->total_records);
    printf("   Parse errors: %d\n", stats->parse_errors);
    printf("   Alerts generated: %d\n", stats->alerts_generated);
    
    if (stats->has_abnormal_vitals) {
        printf("   WARNING: Abnormal vitals detected\n");
    } else {
        printf("   All vitals within normal ranges\n");
    }
}

int process_vitals_file(const char* filename) {
    if (filename == NULL) {
        fprintf(stderr, "Error: No filename provided\n");
        return ERROR_INVALID_FORMAT;
    }
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return ERROR_FILE_NOT_FOUND;
    }
    
    printf("Processing vitals from: %s\n", filename);
    printf("Monitoring for abnormal values...\n\n");
    
    ProcessingStats stats = {0, 0, 0, false};
    char line[MAX_LINE_LENGTH];
    bool is_header = true;
    
    while (fgets(line, sizeof(line), file)) {
        // Skip header line
        if (is_header) {
            is_header = false;
            continue;
        }
        
        // Skip empty lines
        if (strlen(trim_whitespace(line)) == 0) {
            continue;
        }
        
        VitalSigns vitals;
        if (parse_vitals_line(line, &vitals)) {
            stats.total_records++;
            validate_and_alert(&vitals, &stats);
        } else {
            stats.parse_errors++;
            fprintf(stderr, "Warning: Failed to parse line: %s", line);
        }
    }
    
    fclose(file);
    print_summary(&stats);
    
    return SUCCESS;
}

int main(int argc, char* argv[]) {
    const char* default_file = "data/sample_vitals.csv";
    const char* filename = (argc > 1) ? argv[1] : default_file;
    
    int result = process_vitals_file(filename);
    
    if (result != SUCCESS) {
        switch (result) {
            case ERROR_FILE_NOT_FOUND:
                printf("Usage: %s [csv_file]\n", argv[0]);
                printf("Default file: %s\n", default_file);
                break;
            case ERROR_INVALID_FORMAT:
                printf("Invalid file format or corrupted data\n");
                break;
            default:
                printf("Unknown error occurred\n");
                break;
        }
        return result;
    }
    
    return SUCCESS;
}