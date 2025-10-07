#include <stdio.h>
#include "vitals.h"

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