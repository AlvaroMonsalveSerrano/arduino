/*
Nombre proyecto: Leccion10 módulo sensor ultrasónico

Ejempo básico de uso del sensor HC-SR04 ultrasónico.

*/

#define PIN_TRIG 3
#define PIN_ECHO 2

void setup() {
  Serial.begin(9600);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  Serial.println("Ejemplo de uso de HC-SR04.");

}

void loop() {
  long duration, cm;

  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, LOW);

  duration = pulseIn(PIN_ECHO, HIGH); 

  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();

  delay(1000);

}

long microsecondsToCentimeters(long microseconds){
  // La velocidad del sonida es 340 m/seg o bien 29 microsegundos por centímetro.
  // El ping hace dos viajes de ida y de vuelta.
  return microseconds / 29 / 2;
}
