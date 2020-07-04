#include "TM1637.h"

const int CLK = 17; 
const int DIO = 16; 

TM1637 sevenSegment(CLK, DIO); 

#include <Stepper.h> 

#define STEPS_PER_360_DEGREE 2038 

Stepper stepper(STEPS_PER_360_DEGREE, 8, 10, 9, 11); 

void setup(){

  tone(8, 900,600);
  Serial.begin(9600);
  Serial.println( "Hello MDT" );

  stepper.setSpeed(1); 
  Serial.println("Step CW 360  Degrees"); 
  stepper.step(STEPS_PER_360_DEGREE); 
  delay(900);

  stepper.setSpeed(1); 
  Serial.println("Step CCW 360  Degrees"); 
  stepper.step(-STEPS_PER_360_DEGREE); 
  delay(800);  
  sevenSegment.init();
  sevenSegment.set(7); 

  sevenSegment.displayStr("0000");
  delay(800);

  sevenSegment.displayStr("");
  delay(800);
    
  delay(800);
  tone(8, 600, 300);

  stepper.setSpeed(8); 
}
void loop(){
    if (digitalRead(2) == 0)
    {
        stepper.step(STEPS_PER_360_DEGREE/6);
    }
}