/*
Nombre proyecto: Leccion9 servo.

Ejemplo de uso de un servo.

*/

#include <Servo.h>

Servo myServo; // Referencia al servo

int position = 0;

void setup() {
  myServo.attach(9);

}

void loop() {

  for(position = 0; position <= 180; position += 1){
    myServo.write(position);
    delay(15);
  }

  for(position = 180; position >= 0; position -= 1){
    myServo.write(position);
    delay(15);
  }  

}
