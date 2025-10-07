#include "../include/string_utils.h"
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

char* trim_whitespace(char* str) {
    if (str == NULL) return NULL;
    
    // Trim leading whitespace
    while (isspace((unsigned char)*str)) str++;
    
    // Handle empty string
    if (*str == '\0') return str;
    
    // Trim trailing whitespace
    char* end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    
    // Null terminate
    end[1] = '\0';
    
    return str;
}

int split_csv_line(char* line, char delimiter, char** fields, int max_fields) {
    if (line == NULL || fields == NULL || max_fields <= 0) {
        return 0;
    }
    
    int field_count = 0;
    char* start = line;
    char* pos = line;
    
    while (*pos != '\0' && field_count < max_fields) {
        if (*pos == delimiter || *pos == '\n' || *pos == '\r') {
            *pos = '\0';  // Null terminate the field
            fields[field_count] = trim_whitespace(start);
            field_count++;
            start = pos + 1;
        }
        pos++;
    }
    
    // Handle the last field if we haven't reached max_fields
    if (field_count < max_fields && start < pos) {
        fields[field_count] = trim_whitespace(start);
        field_count++;
    }
    
    return field_count;
}

int safe_str_to_int(const char* str, int* result) {
    if (str == NULL || result == NULL) {
        return 0;
    }
    
    char* endptr;
    errno = 0;
    long val = strtol(str, &endptr, 10);
    
    // Check for conversion errors
    if (errno != 0 || endptr == str || *endptr != '\0') {
        return 0;
    }
    
    // Check for integer overflow
    if (val < INT_MIN || val > INT_MAX) {
        return 0;
    }
    
    *result = (int)val;
    return 1;
}

int safe_str_to_double(const char* str, double* result) {
    if (str == NULL || result == NULL) {
        return 0;
    }
    
    char* endptr;
    errno = 0;
    double val = strtod(str, &endptr);
    
    // Check for conversion errors
    if (errno != 0 || endptr == str || *endptr != '\0') {
        return 0;
    }
    
    *result = val;
    return 1;
}