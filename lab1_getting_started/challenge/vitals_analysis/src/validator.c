#include "../include/vitals.h"
#include "../include/vitals_constants.h"

int validate_and_alert(const VitalSigns* vitals, ProcessingStats* stats) {
    if (vitals == NULL || stats == NULL) {
        return 0;
    }
    
    int alerts_count = 0;
    
    // Check heart rate
    if (vitals->heart_rate < HR_MIN) {
        print_alert(vitals, ALERT_BRADYCARDIA);
        alerts_count++;
        stats->has_abnormal_vitals = true;
    } else if (vitals->heart_rate > HR_MAX) {
        print_alert(vitals, ALERT_TACHYCARDIA);
        alerts_count++;
        stats->has_abnormal_vitals = true;
    }
    
    // Check SpO2
    if (vitals->spo2 < SPO2_MIN) {
        print_alert(vitals, ALERT_HYPOXEMIA);
        alerts_count++;
        stats->has_abnormal_vitals = true;
    }
    
    // Check temperature
    if (vitals->temperature < TEMP_MIN) {
        print_alert(vitals, ALERT_HYPOTHERMIA);
        alerts_count++;
        stats->has_abnormal_vitals = true;
    } else if (vitals->temperature > TEMP_MAX) {
        print_alert(vitals, ALERT_HYPERTHERMIA);
        alerts_count++;
        stats->has_abnormal_vitals = true;
    }
    
    stats->alerts_generated += alerts_count;
    return alerts_count;
}