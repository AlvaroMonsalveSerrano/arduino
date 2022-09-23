/*
Nombre Proyecto: Display-8-segmentos

Ejemplo de uso de utilización del display de 8 segmentos.
Corresponde a la lección 27.

*/

// define the LED digit patterns, from 0 - 9
// 1 = LED on, 0 = LED off, in this order:
//                74HC595 pin     Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7 
//                Mapping to      a,b,c,d,e,f,g of Seven-Segment LED
byte seven_seg_digits[10] = { B11111100,  // = 0
                              B01100000,  // = 1
                              B11011010,  // = 2
                              B11110010,  // = 3
                              B01100110,  // = 4
                              B10110110,  // = 5
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B11111110,  // = 8
                              B11100110   // = 9
                             };

// connect to the ST_CP of 74HC595 (pin 3,latch pin)
int latchPin = 3;

// connect to the SH_CP of 74HC595 (pin 4, clock pin)
int clockPin = 4;

// connect to the DS of 74HC595 (pin 2)
int dataPin = 2;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin,  OUTPUT);

}

void loop() {

  // Cuenta hacia atrás desde 9 a 0.
  for(byte digit = 10; digit > 0; --digit){
    delay(1000);
    sevenSegWrite(digit - 1);
  }

  delay(1000);

}

void sevenSegWrite(byte digit){
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);

  digitalWrite(latchPin, HIGH);


}
