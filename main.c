#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main() {
    int sampleCount = 0;

    PowerSample* myData = load_data("C:\\Programming for Engineers Coursework\\UWE-Programming-for-engineers-coursework\\power_quality_log.csv", &sampleCount);

    if (myData != NULL) {
        printf("Loaded %d samples from file.\n", sampleCount);
        printf("Phase     Peak voltage    RMS voltage   P2P   DC Offset\n");

        for (int p = 1; p<= 3; p++) {
            double peak = find_peak(myData, sampleCount, p);
            double rms = calculate_rms(myData, sampleCount, p);
            double peak_to_peak = calculate_peak_to_peak(myData, sampleCount, p);
            double dc_offset = calculate_dc_offset(myData, sampleCount, p);
            int clips = detect_clipping(myData, sampleCount, p);
            int is_compliant = check_tolerance(rms);
            printf("Phase %d -> RMS: %.2fV | P-P: %.2fV | DC: %.4fV | Clips: %d | Compliant: %s\n",
                   p, rms, peak_to_peak, dc_offset, clips, is_compliant ? "YES" : "NO");
            printf("\n");
            //printf("  %d      %7.2f V       %7.2f V    %.2f V   %.4f V\n", p, peak, rms, peak_to_peak, dc_offset);
            printf("\n");
        }
        double p1 = find_peak(myData, sampleCount, 1);
        double r1 = calculate_rms(myData, sampleCount, 1);
        double p2 = find_peak(myData, sampleCount, 2);
        double r2 = calculate_rms(myData, sampleCount, 2);
        double p3 = find_peak(myData, sampleCount, 3);
        double r3 = calculate_rms(myData, sampleCount, 3);
        save_report("C:\\Users\\20ala\\CLionProjects\\UWE-Programming-for-engineers-coursework\\report.txt", myData, sampleCount);

        free(myData);
    } else {
        printf("ERROR: Could not load data from file.\n");
    }
    return 0;
}
//.