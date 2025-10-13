#ifndef ALARM_H
#define ALARM_H

#include "data_generator.h"
#include "config.h"

/**
 * @file alarm.h
 * @brief Header file for glucose alarm functions.
 */

/**
 * @brief Checks and prints alarms based on glucose data and configuration.
 *
 * This function checks for hypoglycemia, hyperglycemia, and rapid changes
 * in glucose values using the provided configuration and prints appropriate alarms.
 *
 * @param data Pointer to the GeneratedData structure containing glucose data.
 * @param config Pointer to the Config structure containing thresholds.
 * @return 0 on success, -1 on error.
 */
int check_and_print_alarms(const GeneratedData* data, const Config* config);

#endif // ALARM_H
