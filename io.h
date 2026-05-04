//
// Created by 20ala on 05/05/2026.
//

#ifndef POWERANALYSER_IO_H
#define POWERANALYSER_IO_H
#include "waveform.h"
PowerSample* load_data(const char* filename, int* count);
void save_report(const char* filename, PowerSample* data, int count);
#endif //POWERANALYSER_IO_H
