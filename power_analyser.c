#include <stdio.h>
#include <stdlib.h>
#include "power_analyser.h"

PowerSample* load_data(const char* filename, int* count) {
    FILE* file = fopen(filename,"r");
    if (file == NULL) {
        return NULL;
    }
    int lines = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        lines++;
    }
    *count=lines;

    PowerSample* data =malloc(lines * sizeof(PowerSample));

    if (data == NULL) {
        fclose(file);
        return NULL;
    }
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < lines; i++) {
        int result = fscanf(file, "%lf, %lf, %lf, %lf",
                            &data[i].time, &data[i].v1,
                            &data[i].v2, &data[i].v3);
        
        printf("DEBUG: Line %d, read %d items\n", i + 1, result);
    }
    fclose(file);
    return data;
}