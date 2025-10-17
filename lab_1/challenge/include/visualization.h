#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "data_generator.h"

/**
 * @file visualization.h
 * @brief Header file for glucose data visualization functions.
 */

/**
 * @brief Prints the glucose data to the terminal.
 *
 * Displays the current glucose data, including the timestamp, glucose value,
 * and glucose history.
 *
 * @param data Pointer to the GeneratedData structure to print.
 * @return 0 on success, -1 on error.
 */
int print_glucose_data(const GeneratedData* data);

#endif // VISUALIZATION_H
