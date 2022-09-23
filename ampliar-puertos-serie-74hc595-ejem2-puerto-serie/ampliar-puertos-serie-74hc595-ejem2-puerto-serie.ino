/*
Nombre Proyecto: ampliar-puertos-serie-74hc595-ejem2-puerto-serie

El proyecto utiliza el chip 74hc595 el cual realiza la ampliación de salidas series.
El chip contiene un registro con los valores de las 8 salidas a escribir. Una vez 
almacenado los 8 valores en el registro interto realiza la escritura de las 8 salidas.

En este ejemplo se utilizará la lectura del puerto serie para seleccionar el led a iluminar, o bien,
el apagado de todos los leds.

Para enviar un carácter a la placa Arduino en la ventana "Seral Port" se escribe un carácter y se envío
con la secuencia de comandos "CMD + Enter"

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
  if(Serial.available()) {

    char ch = Serial.read(); // Lectura.
    if(ch >= '0' && ch <= '7' ){ // Encendemos el seleccionado.
      int led = ch - '0';
      bitSet(leds, led);
      updateShiftRegister();
      Serial.print("Seleccionado led número ");
      Serial.println(led);
    }

    if(ch == 'x'){ // Apagamos todos los leds
      leds = 0;
      updateShiftRegister();
      Serial.println("Apagamos luces leds.");
    }

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