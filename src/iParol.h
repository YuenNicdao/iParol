#ifndef IPAROL_H
#define IPAROL_H

#include "LedControl.h"

#define END nullptr

void iParol_Init(int intensity);
void write(byte pin, bool state);

template <typename T, size_t N>
void write(T (&arr)[N], bool state) {
    for (size_t i = 0; i < N; ++i) {
        write(arr[i], state);  // Call the single pin write for each element
    }
}

void write(byte** arr, bool state);

#endif // IPAROL_H
