#include <stdio.h>
#include <stdlib.h>
#include "power_analyser.h"

int main() {
    int sampleCount = 0;

    PowerSample* myData = load_data("C:\\Users\\20ala\\CLionProjects\\UWE-Programming-for-engineers-coursework\\test.txt", &sampleCount);

    if (myData != NULL) {
        printf("Loaded %d samples from file.\n", sampleCount);
        printf("Phase     Peak voltage    RMS voltage\n");

        for (int p = 1; p<= 3; p++) {
            double peak = find_peak(myData, sampleCount, p);
            double rms = calculate_rms(peak);
            printf("\n");
            printf("  %d      %7.2f V       %7.2f V\n", p, peak, rms);

        }
        double p1 = find_peak(myData, sampleCount, 1);
        double r1 = calculate_rms(p1);
        double p2 = find_peak(myData, sampleCount, 2);
        double r2 = calculate_rms(p2);
        double p3 = find_peak(myData, sampleCount, 3);
        double r3 = find_peak(myData, sampleCount, 3);
        save_report("C:\\Users\\20ala\\CLionProjects\\UWE-Programming-for-engineers-coursework\\report.txt", sampleCount, p1, r1, p2, r2, p3, r3);

        free(myData);
    } else {
        printf("ERROR: Could not load data from file.\n");
    }
    return 0;
}