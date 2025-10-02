#ifndef VITALS_H
#define VITALS_H

/**
 * @file vitals.h
 * @brief Header file for patient vitals monitoring system
 * 
 * This header defines the Vitals structure and related functions for
 * parsing, validating, and alerting on patient vital signs data.
 */

/**
 * @struct Vitals
 * @brief Structure to hold patient vital signs data
 */
typedef struct {
    char ts[25];        /**< Timestamp string (ISO 8601 format) */
    int heart_rate;     /**< Heart rate in beats per minute */
    int spo2;          /**< Blood oxygen saturation percentage */
    float temp_c;      /**< Body temperature in Celsius */
} Vitals;

/**
 * @brief Parse a CSV line into a Vitals structure
 * 
 * Parses a comma-separated line containing timestamp, heart rate, SpO2, and temperature.
 * 
 * @param line Input CSV line to parse
 * @param out Pointer to Vitals structure to populate
 * @return 0 on success, -1 on error
 */
int parse_vitals_line(const char *line, Vitals *out);

/**
 * @brief Validate vitals against normal ranges
 * 
 * Checks if vital signs are within normal ranges:
 * - Heart rate: 50-110 bpm
 * - SpO2: >= 92%
 * - Temperature: 35.0-38.0°C
 * 
 * @param v Pointer to Vitals structure to validate
 * @return 0 if all vitals normal, 1 if any abnormal, -1 on error
 */
int validate_vitals(const Vitals *v);

/**
 * @brief Print alert message if vitals are abnormal
 * 
 * Prints detailed alert information including timestamp and which
 * vital signs are outside normal ranges.
 * 
 * @param v Pointer to Vitals structure to check
 * @return 0 if no alert needed, 1 if alert printed, -1 on error
 */
int print_alert_if_needed(const Vitals *v);

#endif /* VITALS_H */