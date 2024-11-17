#include "MUX_iParol.h"

#define DIN 8
#define CS 10
#define CLK 9
#define DEV 4       // Number of Devices

#define END nullptr

static LedControl lc = LedControl(DIN, CLK, CS, DEV);

void iParol_Init(byte dataPin, byte clkPin, byte csPin, byte devices) {
    for (int i = 0; i < devices; i++) {
        lc.shutdown(i, false);
        lc.setIntensity(i, 15);
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
