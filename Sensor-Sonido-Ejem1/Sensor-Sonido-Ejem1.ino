/*
Nombre proyecto: Sensor-Sonido-Ejem1

Referencia: https://www.prometec.net/sensor-sonido-ky038/

Ejemplo básico de utilización de un sensor de sonido.

Se define una placa con un sensor de sonido y una luz lez. La luz led se encenderá o apagará en 
función de la recepción de un sonido.

Sensor de sonido KY-038

En el potenciometro hay un tornillo que sirve para regular el nivel. Si giramos a la izquierda hasta que se 
apoga la luz, deja de detectar soniso; y, desde estado no sonido girando un poco a derecha, obtiene los valores máximos.

*/

#define LED_PIN 2
#define SOUND_PIN 6
#define SOUND_VALUE_PIN A0 // Pin analógico que realiza la lectura del nivel de sonido que detecta.

bool estado = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  pinMode(SOUND_PIN, INPUT_PULLUP);

  Serial.println("Sensor y led iniciados.");

}

void loop() {

  if( digitalRead(SOUND_PIN) == HIGH){
    int value_sound = analogRead(SOUND_VALUE_PIN);
    Serial.print("Se ha detectado un sonido; ");
    Serial.println(value_sound);

    if( digitalRead(LED_PIN) == HIGH){
      digitalWrite(LED_PIN, LOW);
    }else{
      digitalWrite(LED_PIN, HIGH);
    }

  }else{
    Serial.println("No se ha detectado sonido");
  }
  delay(1000);

}
