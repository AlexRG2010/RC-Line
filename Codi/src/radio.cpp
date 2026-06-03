#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

RF24 radio(CE_PIN, CSN_PIN);
byte direccion[5] = {'c','a','n','a','l'};

void IniciRadio() {
  // Inicia el mòdul de ràdio
  Serial.print("Intentant iniciar el ràdio (CE=");
  Serial.print(CE_PIN);
  Serial.print(", CSN=");
  Serial.print(CSN_PIN);
  Serial.println(")...");
  
  // Afegeix delays per donar temps al mòdul
  delay(500);
  
  if (!radio.begin()) {
    Serial.println("ERROR: No s'ha pogut iniciar el mòdul de ràdio!");
    Serial.println("Intentant altre vegada en 2 segons...");
    delay(2000);
    
    if (!radio.begin()) {
      Serial.println("ERROR PERSISTENT: Verifica:");
      Serial.println("  1. Connections: GND, VCC (3.3V), MOSI (11), MISO (12), SCK (13)");
      Serial.println("  2. CE=Pin9, CSN=Pin10 connectats correctament");
      Serial.println("  3. NECESSITA Capacitor 10µF entre VCC i GND!");
      while (1);
    }
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