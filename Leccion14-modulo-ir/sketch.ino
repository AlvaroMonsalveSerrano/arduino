/*
Nombre proyecto: Lección 14 módulo receptor IR

Definición de un ejemplo básico de uso de un receptor IR.

*/

#include <IRremote.h>


#define PIN_RECEIVER 2   // Pin de IR 

IRrecv receiver(PIN_RECEIVER);

decode_results results;

void setup()
{
  Serial.begin(115200);
  receiver.enableIRIn(); // Inicio de recepción de señales.
  Serial.println("Entramos...");
}

void loop()
{
  if (receiver.decode()) {
    translateIR();
    receiver.resume();  // Recibe siguiente valor
  }

}

void translateIR()
{
  switch (receiver.decodedIRData.command) {
    case 162:
      Serial.println("POWER");
      break;
    case 226:
      Serial.println("MENU");
      break;
    case 34:
      Serial.println("TEST");
      break;
    case 2:
      Serial.println("PLUS");
      break;
    case 194:
      Serial.println("BACK");
      break;
    case 224:
      Serial.println("PREV.");
      break;
    case 168:
      Serial.println("PLAY");
      break;
    case 144:
      Serial.println("NEXT");
      break;
    case 104:
      Serial.println("num: 0");
      break;
    case 152:
      Serial.println("MINUS");
      break;
    case 176:
      Serial.println("key: C");
      break;
    case 48:
      Serial.println("num: 1");
      break;
    case 24:
      Serial.println("num: 2");
      break;
    case 122:
      Serial.println("num: 3");
      break;
    case 16:
      Serial.println("num: 4");
      break;
    case 56:
      Serial.println("num: 5");
      break;
    case 90:
      Serial.println("num: 6");
      break;
    case 66:
      Serial.println("num: 7");
      break;
    case 74:
      Serial.println("num: 8");
      break;
    case 82:
      Serial.println("num: 9");
      break;
    default:
      Serial.println(" other button");
  }
}

