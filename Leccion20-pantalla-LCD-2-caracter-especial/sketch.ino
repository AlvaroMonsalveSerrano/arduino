/*
Nombre Proyecto: Leccion20 pantalla LCD 2.

Ejemplo básico de configuración y escritura en la pantalla de n carácter definido con un código especial.
*/

#include <LiquidCrystal.h>

#define RS_PIN 12 // Command/Data select
#define E_PIN 11 // Enable

#define D4_PIN 10 // Parallel data 4
#define D5_PIN 9  // Parallel data 5
#define D6_PIN 8  // Parallel data 6
#define D7_PIN 7  // Parallel data 7

LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

// Definición del carácter 'corazón'
uint8_t heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
};

void setup() {
  lcd.createChar(3, heart); // Asociado a '\x03'
  lcd.begin(16, 2);
  lcd.print(" Me \x03 Arduino");
  

}
 
void loop() {
  

}
