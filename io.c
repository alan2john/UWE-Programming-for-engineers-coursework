//
// Created by 20ala on 05/05/2026.
//
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"
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
        int result = fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                            &data[i].time, &data[i].v1, &data[i].v2, &data[i].v3, &data[i].current, &data[i].frequency, &data[i].power_factor, &data[i].thd);

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
void save_report(const char* filename, PowerSample* data, int count) {
    FILE* file = fopen(filename,"w");

    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    fprintf(file, "Report:\n");
    fprintf(file, "Phase TrueRMS P2P DC Offset Clips Compliance\n");
    for (int p = 0; p <= 3; p++) {
        double rms = calculate_rms(data, count, p);
        double p2p = calculate_peak_to_peak(data, count, p);
        double dc = calculate_dc_offset(data, count, p);
        int clips = detect_clipping(data, count, p);
        int compliant = check_tolerance(rms);

        fprintf(file, "  %d    %7.2f V     %7.2f V  %7.4f V   %4d       %s\n",
                p, rms, p2p, dc, clips, compliant ? "YES" : "NO");

    }

    fclose(file);
}