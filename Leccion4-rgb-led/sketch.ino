/*
Nombre de proyecto: Leccion 4 RGB LED.

Proyecto de uso de una luz led tipo RGB.

*/

#define BLUE 3
#define GREEN 5 
#define RED 6

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

}
