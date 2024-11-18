#include "iParol.h"

#define DIN 1
#define CS 3
#define CLK 2
#define DEV 4       // Number of Devices

#define END nullptr

static LedControl lc = LedControl(DIN, CLK, CS, DEV);

void iParol_Init(int intensity=15) {
  if (intensity < 0 || intensity > 15) intensity = 15;
  for (int i = 0; i < DEV; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, intensity);
    lc.clearDisplay(i);
  }
}

void write(byte pin, bool state) {
    byte col = (pin - 1) / 15;
    byte row = (pin - 1) % 15;
    byte addr = ((col >= 8) << 1) | (row >= 8);

    col -= (col >= 8) * 8;
    row -= (row >= 8) * 8;

    lc.setLed(addr, row, col, state);
}

template <typename T, byte N>
void write(T (&arr)[N], bool state) {
  for (size_t i = 0; i < N; ++i) {
    write(arr[i], state);
  }
}

void write(byte** arr, bool state) {
    for (size_t i = 0; arr[i] != nullptr; i++) {
        for (size_t j = 0; j < arr[i][j]; j++) {
            if (arr[i][j] == 0) break;
            write(arr[i][j], state);
        }
    }
}
