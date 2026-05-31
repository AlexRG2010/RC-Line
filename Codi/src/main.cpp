#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

void setup() {
  IniciRadio(); // Inicia el mòdul de ràdio 
}

void loop() {
  
  #ifdef Mando
    mapJoystick(); // Mapeja els valors del joystick i els emmagatzema a l'array Joystick

    // Envia els valors del joystick a través del mòdul de ràdio
    radio.write(Joystick, sizeof(Joystick));

  #endif

  #ifdef Cotxe

    radio.read(Joystick, sizeof(Joystick)); // Llegeix els valors del joystick rebuts a través del mòdul de ràdio

    
  #endif

}
