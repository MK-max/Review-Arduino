#include <Stepper.h> 

#define STEPS_PER_360_DEGREE 2038 

Stepper stepper(STEPS_PER_360_DEGREE, 8, 10, 9, 11); 

void setup() {
  Serial.begin(9600);

  stepper.setSpeed(16); 
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 

  Serial.println("Step CW 360  Degrees"); 
  stepper.step(STEPS_PER_360_DEGREE); 
  delay(900);
  
}

void loop() {

}