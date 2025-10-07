#include <string.h>
#include <stdio.h>
#include "vitals_constants.h"

/**
 * @brief Safe string copy with bounds checking
 * 
 * @param dest Destination buffer
 * @param src Source string
 * @param dest_size Size of destination buffer
 * @return 0 on success, -1 on error
 */
static inline int safe_string_copy(char *dest, const char *src, size_t dest_size) {
    if (!dest || !src || dest_size == 0) {
        return VITALS_ERROR_INVALID;
    }
    
    size_t src_len = strlen(src);
    if (src_len >= dest_size) {
        return VITALS_ERROR_OVERFLOW; // Would overflow
    }
    
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0'; // Ensure null termination
    return VITALS_SUCCESS;
}

/**
 * @brief Remove trailing newline from string safely
 * 
 * @param str String to process
 * @param max_len Maximum length to check
 */
static inline void safe_remove_newline(char *str, size_t max_len) {
    if (!str) return;
    
    size_t len = strnlen(str, max_len);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}