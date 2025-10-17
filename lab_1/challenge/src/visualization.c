#include <stdio.h>
#include "../include/data_generator.h"

int print_glucose_data(const GeneratedData* data) {
    if (data == NULL) {
        return -1;
    }
    
    printf("%s %.1f\n", data->timestamp, data->glucose_value);
    
    return 0;
}
