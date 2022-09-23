/*
Nombre del proyecto: Leccion16-modulo-gy521-ejem2

Ejemplo básico del módulo GY-521.

*/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu; // Referencia al módulo MPU.
sensors_event_t eventAcelerometre; // Evento que se retorna del módulo MPU con los datos del acelerómetro.
sensors_event_t eventGiroscope;    // Evento que se retorna del módulo MPU con los datos del giroscopio.
sensors_event_t eventTemperature;  // Evento que se retorna del módulo MPU con los datos de temperatura.

void setup() {
  Serial.begin(115200);

  while( !mpu.begin()){
    Serial.println("MPU6050 not connected!");
    delay(1000);
  }
  Serial.println("MPU6050 ready!");

}

void loop() {
  mpu.getEvent(&eventAcelerometre, &eventGiroscope, &eventTemperature);

  // Datos del acelerómetro.
  Serial.print("[");
  Serial.print(millis());
  Serial.print("] X: [");
  Serial.print(eventAcelerometre.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(eventAcelerometre.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(eventAcelerometre.acceleration.z);
  Serial.print(" m/s^2 ]");

  // Datos del giroscopio.
  Serial.print("[Rotation X: ");
  Serial.print(eventGiroscope.gyro.x);
  Serial.print(", Y: ");
  Serial.print(eventGiroscope.gyro.y);
  Serial.print(", Z: ");
  Serial.print(eventGiroscope.gyro.z);
  Serial.print("rad/s]");

  // Temperatura.
  Serial.print("[Temperatura: ");
  Serial.print("");
  Serial.print(eventTemperature.temperature);
  Serial.print(" C]");

  Serial.println("");

  delay(500);
}
