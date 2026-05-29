#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

RF24 radio(CE_PIN, CSN_PIN);
byte direccion[5] = {'c','a','n','a','l'};

void IniciRadio() {
  radio.begin(); // Inicia el mòdul de ràdio

#ifdef Mando
  radio.openWritingPipe(direccion);
#endif

#ifdef Cotxe
  radio.openReadingPipe(1, direccion);
  radio.startListening(); // Comença a escoltar per rebre dades
#endif
}