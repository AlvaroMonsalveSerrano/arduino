/*
Nombre Proyecto: ampliar-puertos-serie-74hc595-ejem1

El proyecto utiliza el chip 74hc595 el cual realiza la ampliación de salidas series.
El chip contiene un registro con los valores de las 8 salidas a escribir. Una vez 
almacenado los 8 valores en el registro interto realiza la escritura de las 8 salidas.
*/

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

  Serial.println("Arduino iniciado.");

}

void loop() {
  Serial.println("Bucle...");
  leds = 0;
  updateShiftRegister();
  delay(tDelay);
  for(int i=0; i < 8; i++){
    bitSet(leds, i);
    updateShiftRegister();
    delay(tDelay);
  }
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