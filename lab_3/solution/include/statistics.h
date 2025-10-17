#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "data_generator.h"

// Structure to hold summary statistics
typedef struct {
    int min_heart_rate;
    int max_heart_rate;
    double avg_heart_rate;
    int total_records;
    int spo2_below_threshold_count;
    int fever_episode_count;
} SummaryStats;

/**
 * Initializes the summary statistics structure.
 * @param stats Pointer to the SummaryStats structure to initialize.
 */
void initialize_statistics(SummaryStats* stats);

/**
 * Updates the summary statistics with new vital signs data.
 * @param stats Pointer to the SummaryStats structure to update.
 * @param data Pointer to the GeneratedData structure with new data.
 */
void update_statistics(SummaryStats* stats, const GeneratedData* data);

/**
 * Prints the summary statistics.
 * @param stats Pointer to the SummaryStats structure to print.
 */
void print_statistics(const SummaryStats* stats);

// Structure to hold glucose statistics
typedef struct {
    double time_in_range; // Percentage of time in range (70-180 mg/dL)
    double time_below_range; // Percentage of time below range (<70 mg/dL)
    double time_above_range; // Percentage of time above range (>180 mg/dL)
    double avg_glucose; // Average glucose value
    double glucose_variability; // Standard deviation of glucose values
} GlucoseStats;

/**
 * Updates the glucose statistics with new glucose data.
 * @param stats Pointer to the GlucoseStats structure to update.
 * @param data Pointer to the GeneratedData structure with new data.
 */
void update_glucose_statistics(GlucoseStats* stats, const GeneratedData* data);

/**
 * Prints the glucose statistics.
 * @param stats Pointer to the GlucoseStats structure to print.
 */
void print_glucose_statistics(const GlucoseStats* stats);

/**
 * Checks glucose alarms based on the provided data.
 * @param data Pointer to the GeneratedData structure to analyze.
 */
void check_glucose_alarms(const GeneratedData* data);

#endif // ANALYSIS_H
