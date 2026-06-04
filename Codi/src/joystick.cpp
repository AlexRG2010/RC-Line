#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

int Joystick[2]; // Array global per emmagatzemar els valors del joystick

#ifdef Mando
void mapJoystick(){
    int JoystickX = analogRead(Pin_Joystick_X); // Llegeix el valor del joystick en l'eix X
    int JoystickY = analogRead(Pin_Joystick_Y); // Llegeix el valor del joystick en l'eix Y
    
    // Mapeja els valors del joystick a un rang de -100 a 100
    int Velocitat_Joystick = map(JoystickX, 0, 1023, -100, 100);
    int Direccio_Joystick = map(JoystickY, 0, 1023, -100, 100);
    
    // Zona morta: si el valor és molt petit, es considera com 0 (més precís)
    if (Velocitat_Joystick > -30 && Velocitat_Joystick < 30) {
        Velocitat_Joystick = 0;
    }
    
    if (Direccio_Joystick > -30 && Direccio_Joystick < 30) {
        Direccio_Joystick = 0;
    }

    Joystick[0] = Velocitat_Joystick; // Emmagatzema la velocitat mapejada al primer element de l'array
    Joystick[1] = Direccio_Joystick; // Emmagatzema la direcció mapejada al segon element de l'array
}
#endif