/*
Nombre de proyecto: Sensor-Agua-Ejem1

Referencia: https://lastminuteengineers.com/water-level-sensor-arduino-tutorial/

Ejemplo básico de uso de un sensor detector de agua.

un problema deestos sensores es la corta vida que tiene debído a la corrosión por
efecto del agua. Si el sensor tiene corriente de forma constante el desgaste del 
sensor se acelera; la solución, suministrar corriente al sensor en el instante 
de realizar una medición. En el ejemplo el pin 7 digital es el pin por donde 
suministraremos la corriente al sensor.

*/

#define sensorPower 7 // VCC del sensor
#define sensorPin A0  // Pin S del sensor, dato de lectura.

int valueWater = 0; // Nivel de agua.


void setup() {
  pinMode(sensorPower, OUTPUT);
  // Asignamos a LOW para ponerlo HIGH para suministrar corriente al medir.
  digitalWrite(sensorPower, LOW); 

  Serial.begin(9600);
}


void loop() {
  int levelWater = readWaterSensor();
  Serial.println("Nivel de agua: ");
  Serial.println(levelWater);

  delay(1000);
}


/*
La función readWaterSensor realiza la lectura del sensor en el pin sensorPower.

*/
int readWaterSensor(){
  digitalWrite(sensorPower, HIGH);
  delay(10);
  valueWater = analogRead(sensorPin);
  digitalWrite(sensorPower, LOW);

  return valueWater;
}
