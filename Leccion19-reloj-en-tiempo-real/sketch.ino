/*
Nombre del proyecto: Leccion19-reloj-en-tiempo-real

Ejemplo básico de uso del sensor RTC DS3231 reloj en tiempo real.

*/

#include <RTClib.h>

RTC_DS1307 rtc; // Instancia al sensor reloj.

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thrusday", "Friday", "Saturday"};

void setup() {
  Serial.begin(115200);

  if( ! rtc.begin() ){
    Serial.println("No encuetra en sensor RTC.");
    Serial.flush();
    abort();
  }

}

void loop() {
  DateTime now = rtc.now();

  Serial.print("Current Time: ");
  Serial.print(now.year(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print("/");
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.print(now.second(), DEC);
  Serial.println();

  Serial.println();
  delay(3000);
}
