#include "vitals.h"

/**
 * @brief Validate vitals against normal ranges
 * 
 * Normal ranges:
 * - Heart rate: 50-110 bpm
 * - SpO2: >= 92%
 * - Temperature: 35.0-38.0°C
 */
int validate_vitals(const Vitals *v) {
    if (!v) {
        return -1;
    }
    
    int abnormal = 0;
    
    // Check heart rate
    if (v->heart_rate < 50 || v->heart_rate > 110) {
        abnormal = 1;
    }
    
    // Check SpO2
    if (v->spo2 < 92) {
        abnormal = 1;
    }
    
    // Check temperature
    if (v->temp_c < 35.0f || v->temp_c > 38.0f) {
        abnormal = 1;
    }
    
    return abnormal;
}