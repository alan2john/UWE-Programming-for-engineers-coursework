#ifndef UWE_PROGRAMMING_FOR_ENGINEERS_COURSEWORK_POWER_ANALYSER_H
#define UWE_PROGRAMMING_FOR_ENGINEERS_COURSEWORK_POWER_ANALYSER_H


typedef struct {
    double time;
    double v1;
    double v2;
    double v3;
} PowerSample;


PowerSample* load_data(const char* filename, int* count);
double find_peak(PowerSample* data, int count, int phase_num);
double calculate_rms(double peak_voltage);
void save_report(const char* filename, int count, double p1, double r1, double p2, double r2, double p3, double r3);
#endif //UWE_PROGRAMMING_FOR_ENGINEERS_COURSEWORK_POWER_ANALYSER_H