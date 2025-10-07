#ifndef VITALS_CONSTANTS_H
#define VITALS_CONSTANTS_H

// Normal ranges for vital signs
#define HR_MIN 50
#define HR_MAX 110
#define SPO2_MIN 92
#define TEMP_MIN 35.0
#define TEMP_MAX 38.0

// Buffer sizes
#define MAX_LINE_LENGTH 256
#define MAX_TIMESTAMP_LENGTH 32
#define MAX_ALERT_MESSAGE_LENGTH 256

// CSV field positions
#define CSV_TIMESTAMP_COL 0
#define CSV_HEART_RATE_COL 1
#define CSV_SPO2_COL 2
#define CSV_TEMP_COL 3

// Return codes
#define SUCCESS 0
#define ERROR_FILE_NOT_FOUND 1
#define ERROR_INVALID_FORMAT 2
#define ERROR_MEMORY_ALLOCATION 3

#endif // VITALS_CONSTANTS_H