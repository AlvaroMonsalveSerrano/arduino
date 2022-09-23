/*
Ejemplo 2 de comunicación de placa Arduino mediante el módulo Bluetooth H6.

Se utiliza la herramienta de Android "Serial Bluetooth" para realizar la comunicación con la placa.

Ejemplo con lectura de un String.

*/
void setup() {
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()){
    String dataIn = Serial.readString();
    Serial.println("Datos entrada ="+ dataIn);
  }
  
}
