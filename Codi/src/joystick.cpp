#include <Arduino.h>
#include "config.h" //Inclou el fitxer de configuració

int Joystick[2]; // Array global per emmagatzemar els valors del joystick

void mapJoystick(){
    int JoystickX = analogRead(Pin_Joystick_X); // Llegeix el valor del joystick en l'eix X
    int JoystickY = analogRead(Pin_Joystick_Y); // Llegeix el valor del joystick en l'eix Y
    
    // Mapeja els valors del joystick a un rang de -100 a 100
    int Velocitat_Joystick = map(JoystickX, 0, 1023, -100, 100);
    int Direcció_Joystick = map(JoystickY, 0, 1023, -100, 100);
    
    if (Velocitat_Joystick > -50 && Velocitat_Joystick < 50)
    {
        Velocitat_Joystick = 0;
    }
    
    if (Direcció_Joystick > -50 && Direcció_Joystick < 50)
    {
        Direcció_Joystick = 0;
    }

    Joystick[0] = Velocitat_Joystick; // Emmagatzema la velocitat mapejada al primer element de l'array
    Joystick[1] = Direcció_Joystick; // Emmagatzema la direcció mapejada al segon element de l'array

}