/*
Nombre proyecto: Leccion6 activar zumbador 

Ejemplo 6 de la documentación de Arduino para trabajar con un zumbador.

*/

#define buzzer 12

void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer, 1000);
  delay(1000);
  noTone(buzzer);
  delay(1000);
}
