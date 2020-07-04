#include <Stepper.h> 

#define STEPS_PER_360_DEGREE 2038 

Stepper stepper(STEPS_PER_360_DEGREE, 8, 10, 9, 11); 

void setup() {
  tone(8, 900,600);
  Serial.begin(9600);
  Serial.println( "Hello MDT" );
  Serial.begin(9600);

  stepper.setSpeed(16); 
  Serial.println("Step CW 360  Degrees"); 
  stepper.step(STEPS_PER_360_DEGREE); 
  delay(900);
  
}

void loop() {

}