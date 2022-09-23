/*
Nombre proyecto: Leccion17-pir-sensor-movimiento

Ejemplo base de funcionamiento de un sensor PIR de movimiento.

*/

#define LED_PIN 2
#define PIR_PIN 7

int pirState = 0; // Estado de lectura del sensor PIR de movimiento.

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}

void loop() {

  if(digitalRead(PIR_PIN) == HIGH){
    digitalWrite(LED_PIN, HIGH);
    if(pirState == LOW){
      pirState = HIGH;
      Serial.println("Movimiento detectado...");
    }

  } else {
    digitalWrite(LED_PIN, LOW);
    if(pirState == HIGH){
      pirState = LOW;
      Serial.println("Movimiento terminado...");
    }

  }

}
