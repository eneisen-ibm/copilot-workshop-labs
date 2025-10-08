#include "../include/statistics.h"
#include <stdio.h>

void initialize_statistics(SummaryStats* stats) {
    if (stats == NULL) return;

    stats->min_heart_rate = 999;
    stats->max_heart_rate = 0;
    stats->avg_heart_rate = 0.0;
    stats->total_records = 0;
    stats->spo2_below_threshold_count = 0;
    stats->fever_episode_count = 0;
}

void update_statistics(SummaryStats* stats, const GeneratedData* data) {
    if (stats == NULL || data == NULL) return;

    // Update min/max heart rate
    if (data->heart_rate < stats->min_heart_rate) {
        stats->min_heart_rate = data->heart_rate;
    }
    if (data->heart_rate > stats->max_heart_rate) {
        stats->max_heart_rate = data->heart_rate;
    }

    // Update average heart rate
    stats->total_records++;
    stats->avg_heart_rate = ((stats->avg_heart_rate * (stats->total_records - 1)) + data->heart_rate) / stats->total_records;

    // Update SpO2 below threshold count
    if (data->spo2 < 92) {
        stats->spo2_below_threshold_count++;
    }

    // Update fever episode count
    if (data->temperature > 38.0) {
        stats->fever_episode_count++;
    }
}

void print_statistics(const SummaryStats* stats) {
    if (stats == NULL) return;

    printf("\n--- Summary Statistics ---\n");
    printf("Min Heart Rate: %d bpm\n", stats->min_heart_rate);
    printf("Max Heart Rate: %d bpm\n", stats->max_heart_rate);
    printf("Avg Heart Rate: %.2f bpm\n", stats->avg_heart_rate);
    printf("SpO2 Below Threshold: %d times\n", stats->spo2_below_threshold_count);
    printf("Fever Episodes: %d times\n", stats->fever_episode_count);
    printf("---------------------------\n\n");
}
