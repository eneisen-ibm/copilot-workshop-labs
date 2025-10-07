#include "../include/data_generator.h"
#include "../include/statistics.h"
#include <stdio.h>
#include <unistd.h> // For sleep function

#define BUFFER_SIZE 256
#define GENERATION_INTERVAL 2 // Interval in seconds

int main() {
    // Initialize the data generator
    initialize_data_generator();

    // Initialize summary statistics
    SummaryStats stats;
    initialize_statistics(&stats);

    printf("Starting data generation...\n");

    while (1) {
        GeneratedData data;
        char buffer[BUFFER_SIZE];

        // Generate vital signs data
        generate_vital_data(&data);

        // Update statistics
        update_statistics(&stats, &data);

        // Format the data as a CSV line
        format_data_as_csv(&data, buffer, BUFFER_SIZE);

        // Print the generated data
        printf("%s\n", buffer);

        // Print updated statistics
        print_statistics(&stats);

        // Wait for the next generation interval
        sleep(GENERATION_INTERVAL);
    }

    return 0;
}