#ifndef MUXIPAROL_H
#define MUXIPAROL_H

#include "LedControl.h"

void LedMatrix_Init(byte dataPin, byte clkPin, byte csPin, byte devices);
void LedMatrix_Write(byte pin, bool state);
template <typename T, byte N>
void LedMatrix_Write(T (&arr)[N], bool state);
void LedMatrix_Write(byte** arr, bool state);

#endif // MUXIPAROL_H
