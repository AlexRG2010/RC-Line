#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

#ifdef Cotxe
Servo Direcció; // Defineix l'objecte Servo un sol cop per a l'emissor

void Moures(int Velocitat, int Direccio){
    // Controla els motors en funció de la velocitat i direcció rebudes
    if (Velocitat > 0) {
        // Mou cap endavant
        digitalWrite(Pin_Sentit_1, HIGH);
        digitalWrite(Pin_Sentit_2, HIGH);
        analogWrite(Pin_Vel_1, Velocitat);
        analogWrite(Pin_Vel_2, Velocitat);
    } else if (Velocitat < 0) {
        // Mou cap enrere
        digitalWrite(Pin_Sentit_1, LOW);
        digitalWrite(Pin_Sentit_2, LOW);
        analogWrite(Pin_Vel_1, -Velocitat);
        analogWrite(Pin_Vel_2, -Velocitat);
    } else {
        // Atura els motors
        analogWrite(Pin_Vel_1, 0);
        analogWrite(Pin_Vel_2, 0);
    }
    
    // Controla la direcció del servo de direcció
    int Posicio_Direccio = map(Direccio, -100, 100, 0, 180); // Mapeja la direcció a un rang de 0 a 180 graus
    Direcció.write(Posicio_Direccio); // Mou el servo a la posició corresponent
}
#endif