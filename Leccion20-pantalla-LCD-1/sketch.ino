/*
Nombre Proyecto: Leccion20 pantalla LCD 1.

Ejemplo básico de configuración y escritura en la pantalla.
*/

#include <LiquidCrystal.h>

#define RS_PIN 12 // Command/Data select
#define E_PIN 2 // Enable

#define D4_PIN 10 // Parallel data 4
#define D5_PIN 9  // Parallel data 5
#define D6_PIN 8  // Parallel data 6
#define D7_PIN 7  // Parallel data 7

LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.println("Hola Arduino!");
}

void loop() {
  lcd.setCursor(0,1); // (columna, fila)
  lcd.println(millis()/1000);

  Serial.print(digitalRead(D4_PIN));
  Serial.print(digitalRead(D5_PIN));
  Serial.print(digitalRead(D6_PIN));
  Serial.print(digitalRead(D7_PIN));
  Serial.println(" ");

}
