#include "../include/config.h"

/**
 * @brief Initializes the configuration with default values.
 *
 * @return Config structure with default values.
 */
Config initialize_config(void) {
    Config config;
    config.hypoglycemia_threshold = 70;
    config.hyperglycemia_threshold = 180;
    config.rapid_change_threshold = 30;
    config.sleep_interval = 2;
    return config;
}
