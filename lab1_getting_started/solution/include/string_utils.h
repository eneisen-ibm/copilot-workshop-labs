#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdlib.h>

/**
 * Trims whitespace from the beginning and end of a string
 * @param str The string to trim (modified in place)
 * @return Pointer to the trimmed string
 */
char* trim_whitespace(char* str);

/**
 * Splits a CSV line into fields
 * @param line The CSV line to split
 * @param delimiter The delimiter character (usually ',')
 * @param fields Array to store the field pointers
 * @param max_fields Maximum number of fields to extract
 * @return Number of fields extracted
 */
int split_csv_line(char* line, char delimiter, char** fields, int max_fields);

/**
 * Safely converts string to integer
 * @param str The string to convert
 * @param result Pointer to store the result
 * @return 1 if successful, 0 if failed
 */
int safe_str_to_int(const char* str, int* result);

/**
 * Safely converts string to double
 * @param str The string to convert
 * @param result Pointer to store the result
 * @return 1 if successful, 0 if failed
 */
int safe_str_to_double(const char* str, double* result);

#endif // STRING_UTILS_H