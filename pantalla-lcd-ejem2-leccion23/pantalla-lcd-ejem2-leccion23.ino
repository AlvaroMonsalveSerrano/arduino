/*
Nombre Proyecto: Pantalla-lcd-ejem2-leccion23

Ejercicio correspondiente a la lección 23. Es la lección 22 pero se le añade un termistor (termometro).

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

  - A0, valor del termistor.

  RESULTADO: Los valores que salen reflejado no tienen mucho sentido. 
             Valor mostrado en pantalla -62,46 ºC
             
*/

#include <LiquidCrystal.h>
#include <math.h>

#define RS_PIN 7 // Command/Data select
#define E_PIN 8 // Enable

#define D4_PIN 9   // Parallel data 4 D4
#define D5_PIN 10  // Parallel data 5 D5
#define D6_PIN 11  // Parallel data 6 D6
#define D7_PIN 12  // Parallel data 7 D7

#define TERMISTOR_PIN 0


LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

  Serial.println("Pantalla LCD inicializada.");
}

void loop() {

  int temperatureReading = analogRead(TERMISTOR_PIN);
  Serial.println(temperatureReading);
  // This is OK
  double tempK = log(10000.0 * ((1024.0 / temperatureReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit  
  
  /*  replaced 
  float tempVolts = temperatureReading * 5.0 / 1024.0;
  float tempC = (tempVolts - 0.5) * 10.0;
  float tempF = tempC * 9.0 / 5.0 + 32.0;
  */  

  lcd.setCursor(0, 0);
  lcd.print("Temp C:");

  lcd.setCursor(8, 0);
  lcd.print(tempC);

  delay(500);


/*
  float raw = analogRead(SensorPIN);
  float V =  raw / 1024 * Vcc;

  float R = (Rc * V ) / (Vcc - V);

  float logR  = log(R);
  float R_th = 1.0 / (A + B * logR + C * logR * logR * logR );

  float kelvin = R_th - V*V/(K * R)*1000;
  float celsius = kelvin - 273.15;

  Serial.print("T = ");
  Serial.print(celsius);
  Serial.print("C\n");
  delay(2500);
*/







}
