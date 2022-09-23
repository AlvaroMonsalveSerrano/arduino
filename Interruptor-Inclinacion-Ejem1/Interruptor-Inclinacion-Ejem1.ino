/*
Nombre proyecto: Interruptor-Inclinacion-Ejem1

Ejemplo básico de uso del interruptor de inclinación "AETHOX"

*/

#define SWITCH_PIN 2


void setup() {
  Serial.begin(9600);

  pinMode(SWITCH_PIN, INPUT);  

  Serial.println("Placa iniciada.");

}

void loop() {

  if(digitalRead(SWITCH_PIN) == LOW){
    Serial.println("Interruptor conectado.");

  }else if(digitalRead(SWITCH_PIN) == HIGH){
    Serial.println("Interruptor NO conectado.");
  }
  
  delay(2000);
}
