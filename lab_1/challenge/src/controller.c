/**
 * @file controller.c
 * @brief Contains the main controller logic for glucose data generation.
 */

#include "../include/config.h"
#include "../include/data_generator.h"
#include "../include/analysis.h"
#include "../include/visualization.h"
#include <stdio.h>
#include <unistd.h> // For sleep function
#include <stdbool.h>

/**
 * @brief Generates and displays glucose data.
 * 
 * @param data Pointer to GeneratedData structure to populate.
 * @return 0 on success, -1 on error.
 */
int generate_and_display_data(GeneratedData* data) {
    if (data == NULL) return -1;
    
    if (generate_glucose_data(data) != 0) return -1;
    if (print_glucose_data(data) != 0) return -1;
    
    return 0;
}

/**
 * @brief Analyzes glucose data and prints statistics.
 * 
 * @param stats Pointer to GlucoseStats structure.
 * @param data Pointer to GeneratedData structure.
 * @return 0 on success, -1 on error.
 */
int analyze_data() {
}

/**
 * @brief Runs the controller to manage glucose data generation.
 *
 * This function initializes the data generator, updates statistics, formats
 * data as CSV, and handles visualization.
 *
 * @return 0 on success, -1 on error.
 */
int run_controller(void) {
    Config config = initialize_config();

    if (initialize_data_generator() != 0) return -1;
    
    //GlucoseStats stats = {0};
    //if (initialize_glucose_statistics(&stats) != 0) return -1;

    printf("Starting glucose data generation from controller...\n");

    while (1) {
        GeneratedData data;
        
        if (generate_and_display_data(&data) != 0) {
            printf("Warning: Failed to generate data, continuing...\n");
            continue;
        }
        
        //add analysis using analyze_data()
        
        sleep(config.sleep_interval);
    }

    return 0;
}
