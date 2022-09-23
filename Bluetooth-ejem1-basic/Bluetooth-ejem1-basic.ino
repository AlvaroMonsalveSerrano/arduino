/*
Ejemplo de comunicación de placa Arduino mediante el módulo Bluetooth H6.

*/
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    Serial.print("Dato recibido=");
    Serial.println(data);
  }
}