/*
Nombre del proyecto: Leccion16-modulo-GY521-giroscopio-acelerometro-temp-ejem1

Ejemplo básico del módulo GY-521.

*/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu; // Referencia al módulo MPU.
sensors_event_t eventAcelerometre; // Evento que se retorna del módulo MPU con los datos del acelerómetro.

void setup() {
  Serial.begin(115200);

  while( !mpu.begin()){
    Serial.println("MPU6050 not connected!");
    delay(1000);
  }
  Serial.println("MPU6050 ready!");

}

void loop() {
  mpu.getAccelerometerSensor()->getEvent(&eventAcelerometre);

  Serial.print("[");
  Serial.print(millis());
  Serial.print("] X: [");
  Serial.print(eventAcelerometre.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(eventAcelerometre.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(eventAcelerometre.acceleration.z);
  Serial.print(" m/s^2");
  Serial.println();

  delay(500);
}
