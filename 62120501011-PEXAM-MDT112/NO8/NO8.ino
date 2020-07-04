#include "TM1637.h"

const int CLK = 17; 
const int DIO = 16; 

TM1637 sevenSegment(CLK, DIO); 

#include <Stepper.h> 

#define STEPS_PER_360_DEGREE 2038 
Stepper stepper(TEPS_PER_360_DEGREE, 8, 10, 9, 11); 

void setup(){

  tone(8, 900,600);
  Serial.begin(9600);
  Serial.println( "Hello MDT" );

  stepper.setSpeed(16); 
  Serial.println("Step CW 360  Degrees"); 
  stepper.step(TEPS_PER_360_DEGREE); 
  delay(900);

  stepper.setSpeed(16); 
  Serial.println("Step CCW 360  Degrees"); 
  stepper.step(-TEPS_PER_360_DEGREE); 
  delay(800);  
  sevenSegment.init();
  sevenSegment.set(7); 

  sevenSegment.displayStr("0000");
  delay(800);

  sevenSegment.displayStr("");
  delay(800);
    
  delay(800);
  tone(8, 600, 300);

}

void loop(){

    stepper.setSpeed(8);

    for( int TEPS_PER_360_DEGREE = 0; TEPS_PER_360_DEGREE < 9; TEPS_PER_360_DEGREE++)
    {
        if (digitalRead(2) == 0)
        {
            stepper.step(TEPS_PER_360_DEGREE/6);
        }
    }
    for( int TEPS_PER_360_DEGREE = 0; TEPS_PER_360_DEGREE > 1; TEPS_PER_360_DEGREE++)
    {
        if (digitalRead(2) == 0)
        {
            stepper.step(-TEPS_PER_360_DEGREE/6);
        }
    }
    
}