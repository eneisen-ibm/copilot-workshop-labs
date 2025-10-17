#include "../include/controller.h"
#include <stdio.h>

/**
 * @file main.c
 * @brief Entry point for the glucose data generation program.
 */

/**
 * @brief Main function to start the controller.
 *
 * This function initializes the controller, which manages the generation,
 * analysis, and visualization of glucose data.
 *
 * @return Exit status: 0 on success, 1 on error.
 */
int main(void) {
    int result = run_controller();
    if (result != 0) {
        printf("Controller failed with error code: %d\n", result);
        return 1;
    }
    return 0;
}
