/*
Nombre proyecto: Leccion 5 entradas digitales.

Ejemplo de entradas digitales con pulsadores configurados como PullUp.
*/

#define buttonApin 9
#define buttonBpin 8
#define ledPin 5

void setup() {
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  if(digitalRead(buttonApin) == LOW){
    digitalWrite(ledPin, HIGH);
  }

  if(digitalRead(buttonBpin) == LOW){
    digitalWrite(ledPin, LOW);
  }

}
