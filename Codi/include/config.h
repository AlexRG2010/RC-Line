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
    void IniciRadio();

#ifdef Mando

//Servo Direcció
    #define Pin_Direccio 9 // Pin de control del servo de direcció per a l'emissor

    // Creació d'objectes Servo per la direcció
    Servo Direcció;  // Crea un objecte Servo per al primer motor

//Motors


#endif

#ifdef Cotxe

//Joystick
    #define Pin_Joystick_X A0 // Pin de control del joystick per a l'eix X
    #define Pin_Joystick_Y A1 // Pin de control del joystick per a l'eix Y

#endif

#endif