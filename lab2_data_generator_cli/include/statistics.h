#ifndef STATISTICS_H
#define STATISTICS_H

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

#endif // STATISTICS_H
