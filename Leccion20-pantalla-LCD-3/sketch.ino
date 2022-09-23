/*

Nombre Proyecto: Leccion20 pantalla LCD 3.

Ejemplo de la documentación de Arduino. Pantalla LCD con potenciómetro.

El potenciomentro contiene una resistencia que puede variar. En los ejemplos anteriores,
se utiliza una una resistencia de 220 ohmios.

*/

#include <LiquidCrystal.h>

// Sensor temperatura.
#define TEMPERATURE_PIN A0

const float BETA = 3950; // Coeficiente BETA del termistor.

// Pantalla LCD
#define RS_PIN 12 // Command/Data select.
#define E_PIN 11  // Enable

#define D4_PIN 10 // Parallel data 4
#define D5_PIN 9  // Parallel data 5
#define D6_PIN 8  // Parallel data 6
#define D7_PIN 7  // Parallel data 7

LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN); // Pantalla LCD

int temperatureValue = 0;

void setup() {
  Serial.begin(9600);

  lcd.begin(16,2);
  lcd.println("Test....");

}
 
void loop() {

  lcd.setCursor(0, 1);
  lcd.println( millis() / 1000 );

  temperatureValue = analogRead(TEMPERATURE_PIN);
  float celsius = 1 / (log(1 / (1023. / temperatureValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" ℃");

  delay(2000);

}
