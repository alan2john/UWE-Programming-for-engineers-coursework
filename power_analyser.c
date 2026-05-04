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

    char dummy_buffer[1024];
    fgets(dummy_buffer, sizeof(dummy_buffer), file);
    for (int i = 0; i < lines - 1; i++) {
        int result = fscanf(file, "%lf,%lf,%lf,%lf,%*lf,%*lf,%*lf,%*lf",
                            &data[i].time, &data[i].v1,
                            &data[i].v2, &data[i].v3);

        //printf("bug checker: Line %d, read %d items\n", i + 1, result);
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

            if (fabs(current_v) > max_v) {
                max_v = fabs(current_v);
            }
        }
        return max_v;

        }
double calculate_rms(double peak_voltage) {
    return peak_voltage / sqrt(2.0);
}

void save_report(const char* filename, int count, double p1, double r1, double p2, double r2, double p3, double r3) {
    FILE* file = fopen(filename,"w");

    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    fprintf(file, "Report:\n");
    fprintf(file, "Phase Peak RMS\n");
    fprintf(file, "1    %.2fV, %.2fV\n", p1, r1);
    fprintf(file, "2    %.2fV, %.2fV\n", p2, r2);
    fprintf(file, "3    %.2fV, %.2fV\n", p3, r3);

    fclose(file);
    printf("Saved report to %s.\n", filename);

}