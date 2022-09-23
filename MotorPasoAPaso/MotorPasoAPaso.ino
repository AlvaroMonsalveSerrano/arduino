//www.elegoo.com
//2018.10.25

/*
Nombre del proyecto: MotorPasoAPaso

Ejemplo básico de uso de un motor paso a paso.
Ejemplo correspondiente a la lección 31 de Arduino.

*/

#include <Stepper.h>

#define PIN_IN1 11
#define PIN_IN2 10
#define PIN_IN3 9
#define PIN_IN4 8


const int stepsPerRevolution = 2500;  // change this to fit the number of steps per revolution // 2048 Valor inicial
const int rolePerMinute = 15;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, PIN_IN4, PIN_IN2, PIN_IN3, PIN_IN1);

void setup() {
  myStepper.setSpeed(rolePerMinute);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {  
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
