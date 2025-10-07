#include "vitals.h"
#include "vitals_constants.h"

/**
 * @brief Validate vitals against normal ranges
 * 
 * Normal ranges defined in vitals_constants.h:
 * - Heart rate: 50-110 bpm
 * - SpO2: >= 92%
 * - Temperature: 35.0-38.0°C
 */
int validate_vitals(const Vitals *v) {
    if (!v) {
        return VITALS_ERROR_INVALID;
    }
    
    int abnormal = 0;
    
    // Check heart rate against defined constants
    if (v->heart_rate < HEART_RATE_MIN_NORMAL || 
        v->heart_rate > HEART_RATE_MAX_NORMAL) {
        abnormal = 1;
    }
    
    // Check SpO2 against defined constants
    if (v->spo2 < SPO2_MIN_NORMAL) {
        abnormal = 1;
    }
    
    // Check temperature against defined constants
    if (v->temp_c < TEMP_MIN_NORMAL || 
        v->temp_c > TEMP_MAX_NORMAL) {
        abnormal = 1;
    }
    
    return abnormal;
}