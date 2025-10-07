#include <stdio.h>
#include "vitals.h"
#include "vitals_constants.h"

/**
 * @brief Print alert message if vitals are abnormal
 * 
 * Prints detailed information about which vitals are out of range.
 */
int print_alert_if_needed(const Vitals *v) {
    if (!v) {
        return VITALS_ERROR_INVALID;
    }
    
    int alert_printed = 0;
    
    printf("ALERT [%s]: ", v->ts);
    
    // Check heart rate using named constants
    if (v->heart_rate < HEART_RATE_MIN_NORMAL) {
        printf("BRADYCARDIA (HR: %d bpm, normal: %d-%d) ", 
               v->heart_rate, HEART_RATE_MIN_NORMAL, HEART_RATE_MAX_NORMAL);
        alert_printed = 1;
    } else if (v->heart_rate > HEART_RATE_MAX_NORMAL) {
        printf("TACHYCARDIA (HR: %d bpm, normal: %d-%d) ", 
               v->heart_rate, HEART_RATE_MIN_NORMAL, HEART_RATE_MAX_NORMAL);
        alert_printed = 1;
    }
    
    // Check SpO2 using named constants
    if (v->spo2 < SPO2_MIN_NORMAL) {
        printf("HYPOXEMIA (SpO2: %d%%, normal: >=%d%%) ", 
               v->spo2, SPO2_MIN_NORMAL);
        alert_printed = 1;
    }
    
    // Check temperature using named constants
    if (v->temp_c < TEMP_MIN_NORMAL) {
        printf("HYPOTHERMIA (Temp: %.1f°C, normal: %.1f-%.1f°C) ", 
               v->temp_c, TEMP_MIN_NORMAL, TEMP_MAX_NORMAL);
        alert_printed = 1;
    } else if (v->temp_c > TEMP_MAX_NORMAL) {
        printf("HYPERTHERMIA (Temp: %.1f°C, normal: %.1f-%.1f°C) ", 
               v->temp_c, TEMP_MIN_NORMAL, TEMP_MAX_NORMAL);
        alert_printed = 1;
    }
    
    if (alert_printed) {
        printf("\n");
        return 1;
    }
    
    return 0;
}