#include <stdio.h>
#include <stdlib.h>
#include "power_analyser.h"

int main() {
    int sampleCount = 0;

    PowerSample* myData = load_data("C:\\Users\\20ala\\CLionProjects\\UWE-Programming-for-engineers-coursework\\test.txt", &sampleCount);

    if (myData != NULL) {
        printf("Loaded %d samples from file.\n", sampleCount);
        double peak1 = find_peak(myData, sampleCount, 1);
        double peak2 = find_peak(myData, sampleCount, 2);
        double peak3 = find_peak(myData, sampleCount, 3);

        printf("Analysis Report\n");
        printf("peak1 : %.2f\n", peak1);
        printf("peak2 : %.2f\n", peak2);
        printf("peak3 : %.2f\n", peak3);

        free(myData);
    } else {
        printf("ERROR: Could not load data from file.\n");
    }
    return 0;
}