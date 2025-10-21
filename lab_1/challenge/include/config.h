#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 * @brief Configuration module for glucose monitoring system.
 */

/**
 * @brief Structure to hold configuration parameters.
 */
typedef struct {
    int hypoglycemia_threshold;
    int hyperglycemia_threshold;
    int sleep_interval;
} Config;

/**
 * @brief Initializes the configuration with default values.
 *
 * @return Config structure with default values.
 */
Config initialize_config(void);

#endif // CONFIG_H
