/*
  Empowerment Technology
  iParol v2 (PHS)
  s.2024
*/

//******************************************
// USE write() in replace to digitalWrite()
//
// This will work with 15x15 boards
//******************************************

#include "iParol.h"

void setup() {
    iParol_Init(3); // Optionally, you can enter a brightness level from 1 - 15 only.
}

void loop() {
    // This example will blink all leds for 0.1 second

    for(byte i = 1; i<=225; i++){
        write(i, HIGH);
    }
    delay(100);
    
    for(byte i = 1; i<=225; i++){
        write(i, LOW);
    }
    delay(100);
}
