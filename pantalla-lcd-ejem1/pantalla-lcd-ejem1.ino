/*
Nombre Proyecto: Pantalla-lcd-ejem1

Ejercicio correspondiente a la lección 22.

Importante seguir el mapa de conexiones de la documentación de Elegoo. La pantalla LCD es Hitachi hd44780 lcd 16x2.

Los problemas encontrados:
  - Hay que ajustar la intensidad de la pantalla con el potenciometro.
  - He tenido problema con los cables en el protoboard.

Mapa de conexiones:

  - VSS GND, tierra
  - VDD 5V, fuente de alimentación.
  - VO 5V, ajuste de contraste.
  - RW GND, selecciona el modo de lectura/escritura.
  - A 5V, ánodo de contraalimentación.
  - K GND, cátodo de contraalimentación.

  - RS_PIN 7, command/data select
  - E_PIN 8, habilitador.

  - D4_PIN 9   
  - D5_PIN 10  
  - D6_PIN 11  
  - D7_PIN 12  

*/

#include <LiquidCrystal.h>

#define RS_PIN 7 // Command/Data select
#define E_PIN 8 // Enable

#define D4_PIN 9   // Parallel data 4 D4
#define D5_PIN 10  // Parallel data 5 D5
#define D6_PIN 11  // Parallel data 6 D6
#define D7_PIN 12  // Parallel data 7 D7


LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
  Serial.begin(9600);

  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("Hola Alvaro!");

  Serial.println("Pantalla LCD inicializada.");
}

void loop() {
  lcd.setCursor(0,1); // (columna, fila)
  lcd.print(millis()/1000);
}
