#ifndef config_h
#define config_h

//Inclou les llibreries necessàries per al projecte
    #include <Arduino.h> //Inclou la llibreria d'Arduino
    #include <Servo.h> //Inclou la llibreria per controlar servomotors
    #include <RF24.h> //Inclou la llibreria per controlar el mòdul de ràdio nRF24L01

//Radio
    #define CE_PIN 9 // Pin CE del mòdul de ràdio
    #define CSN_PIN 10 // Pin CSN del mòdul de ràdio
    extern RF24 radio;
    extern byte direccion[5];

    void IniciRadio(); // Declaració de la funció per iniciar el mòdul de ràdio

//Joystick
    extern int Joystick[2]; // Array global per emmagatzemar els valors del joystick

    extern int Velocitat_Joystick; // Variable global per emmagatzemar la velocitat mapejada del joystick
    extern int Direccio_Joystick; // Variable global per emmagatzemar la direcció mapejada del joystick
    extern int Joystick[2]; // Array global per emmagatzemar els valors del joystick

#ifdef Cotxe

//Servo Direcció
    #define Pin_Direccio 3 // Pin de control del servo de direcció (PWM)

    // Declaració de l'objecte Servo per la direcció
    extern Servo Direccio;  // Objecte Servo definit en un fitxer .cpp

//Motors
    #define Pin_Vel_1 5 // Pin PWM de control de velocitat motor 1 (ENA)
    #define Pin_Vel_2 6 // Pin PWM de control de velocitat motor 2 (ENB)

    #define Pin_Sentit_1 7 // Pin de control de direcció motor 1 (IN1)
    #define Pin_Sentit_2 8 // Pin de control de direcció motor 2 (IN2)
    
    void Moures(int Velocitat, int Direccio); // Declaració de la funció per controlar motors
    void IniciMotors(); // Declaració de la funció per iniciar motors


#endif

#ifdef Mando

//Joystick
    #define Pin_Joystick_X A0 // Pin de control del joystick per a l'eix X
    #define Pin_Joystick_Y A1 // Pin de control del joystick per a l'eix Y

    void mapJoystick(); // Declaració de la funció per mapear els valors del joystick
#endif

#endif