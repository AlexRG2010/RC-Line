#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

void setup() {
  IniciRadio(); // Inicia el mòdul de ràdio 
}

void loop() {
  mapJoystick(); // Mapeja els valors del joystick i els emmagatzema a l'array Joystick
}
