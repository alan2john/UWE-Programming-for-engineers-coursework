#include <stdio.h>
#include <stdlib.h>
#include "power_analyser.h"
#include "math.h"
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

        //printf("DEBUG: Line %d, read %d items\n", i + 1, result);
    }
    fclose(file);
    return data;
}
    double find_peak(PowerSample* data, int count, int phase_num) {
        double max_v = 0.0;

        for (int i = 0; i < count; i++) {
            double current_v;

            if (phase_num == 1) current_v = data[i].v1;
            else if (phase_num == 2) current_v = data[i].v2;
            else current_v = data[i].v3;

            if (current_v > max_v) {
                max_v = current_v;
            }
        }
        return max_v;

        }
double calculate_rms(double peak_voltage) {
    return peak_voltage / sqrt(2.0);
}