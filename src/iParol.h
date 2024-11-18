#ifndef IPAROL_H
#define IPAROL_H

#include "LedControl.h"

void iParol_Init(int intensity);
void write(byte pin, bool state);
template <typename T, byte N>
void write(T (&arr)[N], bool state);
void write(byte** arr, bool state);

#endif // IPAROL_H
