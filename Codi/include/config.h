#ifndef config_h
#define config_h

//Inclou les llibreries necessàries per al projecte
    #include <Arduino.h> //Inclou la llibreria d'Arduino
    #include <Servo.h> //Inclou la llibreria per controlar servomotors
    #include <RF24.h> //Inclou la llibreria per controlar el mòdul de ràdio nRF24L01

//Radio
    #define CE_PIN 7 // Pin CE del mòdul de ràdio
    #define CSN_PIN 10 // Pin CSN del mòdul de ràdio
    extern RF24 radio;
    extern byte direccion[5];

    void IniciRadio(); // Declaració de la funció per iniciar el mòdul de ràdio

//Joystick
    extern int Joystick[2]; // Array global per emmagatzemar els valors del joystick

#ifdef Cotxe

//Servo Direcció
    #define Pin_Direccio 9 // Pin de control del servo de direcció per a l'emissor

    // Creació d'objectes Servo per la direcció
    Servo Direcció;  // Crea un objecte Servo per al primer motor

//Motors
    #define Pin_Vel_1 5 // Pin de control del motor 1 per a l'emissor
    #define Pin_Vel_2 6 // Pin de control del motor 2 per a l'emissor

    #define Pin_Sentit_1 7 // Pin de control de la direcció del motor 1 per a l'emissor
    #define Pin_Sentit_2 8 // Pin de control de la direcció del motor 2 per a l'emissor


#endif

#ifdef Mando

//Joystick
    #define Pin_Joystick_X A0 // Pin de control del joystick per a l'eix X
    #define Pin_Joystick_Y A1 // Pin de control del joystick per a l'eix Y

    void mapJoystick(); // Declaració de la funció per mapear els valors del joystick
#endif

#endif