#include "../include/config.h"

/**
 * @brief Initializes the configuration with default values.
 *
 * @return Config structure with default values.
 */
Config initialize_config(void) {
    Config config;
    config.sleep_interval = 2;
    return config;
}
