#ifndef UWE_PROGRAMMING_FOR_ENGINEERS_COURSEWORK_POWER_ANALYSER_H
#define UWE_PROGRAMMING_FOR_ENGINEERS_COURSEWORK_POWER_ANALYSER_H


typedef struct {
    double time;
    double v1;
    double v2;
    double v3;
} PowerSample;


PowerSample* load_data(const char* filename, int* count);

#endif //UWE_PROGRAMMING_FOR_ENGINEERS_COURSEWORK_POWER_ANALYSER_H