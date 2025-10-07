#include "../include/vitals.h"
#include "../include/vitals_constants.h"
#include <stdio.h>

void print_alert(const VitalSigns* vitals, AlertType alert_type) {
    if (vitals == NULL) return;
    
    printf("ALERT [%s]: ", vitals->timestamp);
    
    switch (alert_type) {
        case ALERT_BRADYCARDIA:
            printf("BRADYCARDIA (HR: %d bpm, normal: %d-%d)", 
                   vitals->heart_rate, HR_MIN, HR_MAX);
            break;
        case ALERT_TACHYCARDIA:
            printf("TACHYCARDIA (HR: %d bpm, normal: %d-%d)", 
                   vitals->heart_rate, HR_MIN, HR_MAX);
            break;
        case ALERT_HYPOXEMIA:
            printf("HYPOXEMIA (SpO2: %d%%, normal: >=%d%%)", 
                   vitals->spo2, SPO2_MIN);
            break;
        case ALERT_HYPOTHERMIA:
            printf("HYPOTHERMIA (Temp: %.1f°C, normal: %.1f-%.1f°C)", 
                   vitals->temperature, TEMP_MIN, TEMP_MAX);
            break;
        case ALERT_HYPERTHERMIA:
            printf("HYPERTHERMIA (Temp: %.1f°C, normal: %.1f-%.1f°C)", 
                   vitals->temperature, TEMP_MIN, TEMP_MAX);
            break;
    }
    
    printf(" \n");
}