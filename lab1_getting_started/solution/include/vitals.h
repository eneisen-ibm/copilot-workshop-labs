#ifndef VITALS_H
#define VITALS_H

#include <stdio.h>
#include <stdbool.h>

// Structure to hold vital signs data
typedef struct {
    char timestamp[32];
    int heart_rate;
    int spo2;
    double temperature;
} VitalSigns;

// Structure to hold processing statistics
typedef struct {
    int total_records;
    int parse_errors;
    int alerts_generated;
    bool has_abnormal_vitals;
} ProcessingStats;

// Alert types
typedef enum {
    ALERT_BRADYCARDIA,
    ALERT_TACHYCARDIA,
    ALERT_HYPOXEMIA,
    ALERT_HYPOTHERMIA,
    ALERT_HYPERTHERMIA
} AlertType;

// Function declarations

/**
 * Parses a CSV line into VitalSigns structure
 * @param line The CSV line to parse
 * @param vitals Pointer to VitalSigns structure to fill
 * @return 1 if successful, 0 if failed
 */
int parse_vitals_line(char* line, VitalSigns* vitals);

/**
 * Validates vital signs and generates alerts if needed
 * @param vitals The vital signs to validate
 * @param stats Processing statistics to update
 * @return Number of alerts generated for this record
 */
int validate_and_alert(const VitalSigns* vitals, ProcessingStats* stats);

/**
 * Processes the entire CSV file
 * @param filename Path to the CSV file
 * @return 0 if successful, error code otherwise
 */
int process_vitals_file(const char* filename);

/**
 * Prints an alert message for abnormal vital signs
 * @param vitals The vital signs data
 * @param alert_type The type of alert to print
 */
void print_alert(const VitalSigns* vitals, AlertType alert_type);

/**
 * Prints the processing summary
 * @param stats Processing statistics
 */
void print_summary(const ProcessingStats* stats);

#endif // VITALS_H