/*
  Empowerment Technology
  iParol v2 (PHS)
  s.2023
*/

//******************************************
// USE write() in replace to digitalWrite()
//
// This will work with 15x15 boards
//******************************************

#include "MUX_iParol.h"


void setup() {
    iParol_Init();
}

void loop() {
    //you dont need to write anything here
    for(byte i = 1; i<=225; i++){
        write(i, HIGH);
    }
    delay(100);
    
    for(byte i = 1; i<=225; i++){
        write(i, LOW);
    }
    delay(100);
}
