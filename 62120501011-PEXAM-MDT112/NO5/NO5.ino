#include "TM1637.h"

const int CLK = 17; 
const int DIO = 16; 

TM1637 sevenSegment(CLK, DIO); 

void setup() {
  sevenSegment.init();
  sevenSegment.set(7); 

  sevenSegment.displayStr("0000");
  delay(800);

  sevenSegment.displayStr("");
  delay(800);
}


void loop() {

}
