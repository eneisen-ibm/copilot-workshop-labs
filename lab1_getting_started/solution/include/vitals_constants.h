#ifndef VITALS_CONSTANTS_H
#define VITALS_CONSTANTS_H

/**
 * @file vitals_constants.h
 * @brief Constants and thresholds for vitals monitoring system
 */

// Medical threshold constants
#define HEART_RATE_MIN_NORMAL    50
#define HEART_RATE_MAX_NORMAL    110
#define SPO2_MIN_NORMAL          92
#define SPO2_MAX_NORMAL          100
#define TEMP_MIN_NORMAL          35.0f
#define TEMP_MAX_NORMAL          38.0f

// Buffer size constants  
#define MAX_TIMESTAMP_LENGTH     25
#define MAX_LINE_LENGTH          256
#define MAX_CSV_FIELDS           4

// Return codes
#define VITALS_SUCCESS           0
#define VITALS_ERROR_INVALID     -1
#define VITALS_ERROR_PARSE       -2
#define VITALS_ERROR_OVERFLOW    -3

#endif /* VITALS_CONSTANTS_H */