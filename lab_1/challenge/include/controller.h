#ifndef CONTROLLER_H
#define CONTROLLER_H

/**
 * @file controller.h
 * @brief Header file for the controller logic.
 */

/**
 * @brief Runs the controller to manage glucose data generation.
 *
 * This function initializes the data generator, updates statistics, and
 * formats data as CSV.
 *
 * @return 0 on success, -1 on error.
 */
int run_controller(void);

#endif // CONTROLLER_H
