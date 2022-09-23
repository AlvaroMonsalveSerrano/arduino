/*
Nombre Proyecto: fotocelula-ejem1. 

El proyecto es una ampliación a los proyectos "amplicar-puertos-seria-74hc595-puerto-serie%"

Se utiliza un sensor fotoeléctrico para determinar la luz de los leds del prototipo.

Referencia de la documentación: "Lección 26 Fotocélula"

*/
int LIGHT_SENSOR_PIN = 0; // Sensor totoeléctrico.
int CLOCK_PIN = 9;  // (9) SH_CP [SCK] on 74HC595. Serial clock
int LATCH_PIN = 11; // (11) ST_CP [RCK] on 74HC595. Pin de almacenamiento,
int DATA_PIN  = 12; // (12) DS [S1] on 74HC595. Datos en Serie.

int tDelay = 500;
byte leds = 0; // posición de led

void setup() {
  Serial.begin(9600);

  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  Serial.println("Arduino iniciado...");

}

void loop() {

  int reading = analogRead(LIGHT_SENSOR_PIN);

  Serial.println(reading);

  int numLEDSLit = reading / 57;  //1023 / 9 / 2: 
  // 1023, el total del potencial electrico leído por A0 (sensor fotoeléctrico)
  // 9 ? --> 8 sensores más 1?
  // 2 ?
  if (numLEDSLit > 8) numLEDSLit = 8;
  leds = 0;   // no LEDs lit to start
  for (int i = 0; i < numLEDSLit; i++)
  {
    leds = leds + (1 << i);  // sets the i'th bit
  }
  updateShiftRegister();

  delay(2000);

}

/*
La función updateShiftRegister realiza la escritura del registro 
del chip 74hc595.

*/
void updateShiftRegister(){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, leds);
  digitalWrite(LATCH_PIN, HIGH);
}
