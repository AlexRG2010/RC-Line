#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

#ifdef Cotxe
Servo Direccio; // Objecte Servo per controlar la direcció

void IniciMotors() {
    // Inicialitza els pins dels motors com sortides digitals
    pinMode(Pin_Vel_1, OUTPUT);
    pinMode(Pin_Vel_2, OUTPUT);
    pinMode(Pin_Sentit_1_A, OUTPUT);
    pinMode(Pin_Sentit_1_B, OUTPUT);
    pinMode(Pin_Sentit_2_A, OUTPUT);
    pinMode(Pin_Sentit_2_B, OUTPUT);

    // Inicialitza el servo de direcció
    Direccio.attach(Pin_Direccio);
    Direccio.write(90); // Posició central (90 graus)
}

void Moures(int Velocitat, int Direccio_Valor){
    // Mapeja la velocitat de -100 a 100 a 0-255 per a analogWrite
    int Vel_Mapejada = map(abs(Velocitat), 0, 100, 0, 255);
    
    if (Velocitat > 0) {
        // Mou cap endavant
        digitalWrite(Pin_Sentit_1_A, HIGH);
        digitalWrite(Pin_Sentit_1_B, LOW);
        digitalWrite(Pin_Sentit_2_A, HIGH);
        digitalWrite(Pin_Sentit_2_B, LOW);

        analogWrite(Pin_Vel_1, Vel_Mapejada);
        analogWrite(Pin_Vel_2, Vel_Mapejada);
    } else if (Velocitat < 0) {
        // Mou cap enrere
        digitalWrite(Pin_Sentit_1_A, LOW);
        digitalWrite(Pin_Sentit_1_B, HIGH);
        digitalWrite(Pin_Sentit_2_A, LOW);
        digitalWrite(Pin_Sentit_2_B, HIGH);
        analogWrite(Pin_Vel_1, Vel_Mapejada);
        analogWrite(Pin_Vel_2, Vel_Mapejada);
    } else {
        // Atura els motors
        analogWrite(Pin_Vel_1, 0);
        analogWrite(Pin_Vel_2, 0);
    }
    
    // Controla la direcció del servo de direcció
    // Mapeja de -100 a 100 a 0 a 180 graus
    int Posicio_Direccio = map(Direccio_Valor, -100, 100, 0, 180);
    // Limita la posició entre 0 i 180
    Posicio_Direccio = constrain(Posicio_Direccio, 0, 180);
    Direccio.write(Posicio_Direccio);
}
#endif