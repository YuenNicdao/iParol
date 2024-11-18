# MUX_iParol

MUX_iParol is an Arduino library for controlling a 15x15 matrix of LEDs using the LedControl library. It allows for easy manipulation of individual LEDs or groups of LEDs on a matrix.

## Features
- Control multiple LED devices
- Set individual LEDs to on/off state
- Support for arrays of LEDs

## Usage
### Basic Example
```cpp
#include "iParol.h"

void setup() {
    iParol_Init();
}

void loop() {
    for(byte i = 1; i<=225; i++){
        write(i, HIGH);
    }
    delay(100);
    
    for(byte i = 1; i<=225; i++){
        write(i, LOW);
    }
    delay(100);
}

