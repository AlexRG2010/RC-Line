#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

RF24 radio(CE_PIN, CSN_PIN);
byte direccion[5] = {'c','a','n','a','l'};

void IniciRadio() {
  // Inicia el mòdul de ràdio
  if (!radio.begin()) {
    Serial.println("ERROR: No s'ha pogut iniciar el mòdul de ràdio!");
    while (1); // Es queda bloquejat si no funciona el ràdio
  }
  
  // Configuració del mòdul de ràdio
  radio.setPALevel(RF24_PA_MIN);   // Potència mínima
  radio.setDataRate(RF24_250KBPS); // Taxa de dades: 250 kbps
  radio.setChannel(76);            // Canal de comunicació (0-125)

#ifdef Mando
  radio.openWritingPipe(direccion);
  radio.stopListening(); // Mode transmissor
#endif

#ifdef Cotxe
  radio.openReadingPipe(1, direccion);
  radio.startListening(); // Mode receptor
#endif
}