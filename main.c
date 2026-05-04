#include <stdio.h>
#include <stdlib.h>
#include "power_analyser.h"

int main() {
    int sampleCount = 0;

    PowerSample* myData = load_data("C:\\Users\\20ala\\CLionProjects\\UWE-Programming-for-engineers-coursework\\test.txt", &sampleCount);

    if (myData != NULL) {
        printf("Loaded %d samples from file.\n", sampleCount);

        printf("Row 1 is Time: %.1f, V1: %.1f, V2: %.1f, V3: %.1f\n",
            myData[0].time, myData[0].v1, myData[0].v2, myData[0].v3);

        free(myData);
    } else {
        printf("ERROR: Could not load data from file.\n");
    }
    return 0;
}