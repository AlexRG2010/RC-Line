#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

void setup() {
  Serial.begin(9600); // Inicia la comunicació serial per debugging
  IniciRadio(); // Inicia el mòdul de ràdio 
  
  #ifdef Cotxe
    IniciMotors(); // Inicialitza els motors i el servo
  #endif
}

void loop() {
  
  #ifdef Mando
    mapJoystick(); // Mapeja els valors del joystick i els emmagatzema a l'array Joystick

    // Envia els valors del joystick a través del mòdul de ràdio si està disponible
    if (radio.write(Joystick, sizeof(Joystick))) {
      // Transmissió exitosa (opcional)
    }

  #endif

  #ifdef Cotxe

    // Comprova si hi ha dades disponibles del mòdul de ràdio
    if (radio.available()) {
      radio.read(Joystick, sizeof(Joystick)); // Llegeix els valors del joystick rebuts
    }

    // Mapeja els valors del joystick a variables de velocitat i direcció
    int Velocitat = Joystick[0]; // El primer element de l'array correspon a la velocitat
    int Direccio = Joystick[1];  // El segon element de l'array correspon a la direcció

    // Controla els motors i el servo amb els valors rebuts
    Moures(Velocitat, Direccio);

  #endif

}
