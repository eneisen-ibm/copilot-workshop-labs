#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "vitals.h"
#include "vitals_constants.h"
#include "string_utils.h"

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
    
    char line[MAX_LINE_LENGTH];
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
        
        // Remove trailing newline safely
        safe_remove_newline(line, sizeof(line));
        
        // Skip empty lines
        if (strlen(line) == 0) {
            continue;
        }
        
        Vitals vitals;
        int parse_result = parse_vitals_line(line, &vitals);
        if (parse_result != VITALS_SUCCESS) {
            fprintf(stderr, "Parse error on line %d: %s (error code: %d)\n", 
                    line_number, line, parse_result);
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