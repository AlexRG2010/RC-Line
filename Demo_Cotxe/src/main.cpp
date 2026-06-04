#include <Arduino.h>
#include <Servo.h>

// === PINS ===
#define Pin_Vel_1 5
#define Pin_Vel_2 6
#define Pin_Sentit_1_A 7
#define Pin_Sentit_1_B 8
#define Pin_Sentit_2_A 4
#define Pin_Sentit_2_B 2
#define Pin_Direccio 3

// === SERVO ===
Servo Direccio;

void setup() {
  Serial.begin(9600);
  Serial.println("\n=== DEMO COTXE RC ===\n");
  
  // Configurar pins motors
  pinMode(Pin_Vel_1, OUTPUT);
  pinMode(Pin_Vel_2, OUTPUT);
  pinMode(Pin_Sentit_1_A, OUTPUT);
  pinMode(Pin_Sentit_1_B, OUTPUT);
  pinMode(Pin_Sentit_2_A, OUTPUT);
  pinMode(Pin_Sentit_2_B, OUTPUT);
  
  // Configurar servo
  Direccio.attach(Pin_Direccio);
  Direccio.write(90); // Posició central
  
  Serial.println("✓ Cotxe inicialitzat!");
  Serial.println("Executant demostració...\n");
  delay(2000);
}

void loop() {
  // DEMOSTRACIÓ 1: MOVIMENT ENDAVANT
  Serial.println("→ Movent ENDAVANT (5 segons)");
  moureEndavant(200);
  delay(5000);
  
  // DEMOSTRACIÓ 2: GIRAR DRETA
  Serial.println("↻ Girant DRETA (3 segons)");
  moureEndavant(150);
  girarDreta();
  delay(3000);
  
  // DEMOSTRACIÓ 3: GIRAR ESQUERRA
  Serial.println("↺ Girant ESQUERRA (3 segons)");
  moureEndavant(150);
  girarEsquerra();
  delay(3000);
  
  // DEMOSTRACIÓ 4: RECTE
  Serial.println("→ Recte (2 segons)");
  moureEndavant(200);
  rectilini();
  delay(2000);
  
  // DEMOSTRACIÓ 5: ENRERE
  Serial.println("← Movent ENRERE (3 segons)");
  moureEnrere(150);
  rectilini();
  delay(3000);
  
  // DEMOSTRACIÓ 6: ATURAR
  Serial.println("⚫ ATURANT (2 segons)");
  aturar();
  delay(2000);
  
  Serial.println("\n🔄 Demostració completada. Repetint...\n");
  delay(2000);
}

// === FUNCIONS DE MOVIMENT ===

void moureEndavant(int velocitat) {
  // Direcció: ambdós motors cap endavant
  digitalWrite(Pin_Sentit_1_A, HIGH);
  digitalWrite(Pin_Sentit_1_B, LOW);
  digitalWrite(Pin_Sentit_2_A, HIGH);
  digitalWrite(Pin_Sentit_2_B, LOW);
  
  // Velocitat
  analogWrite(Pin_Vel_1, velocitat);
  analogWrite(Pin_Vel_2, velocitat);
}

void moureEnrere(int velocitat) {
  // Direcció: ambdós motors cap enrere
  digitalWrite(Pin_Sentit_1_A, LOW);
  digitalWrite(Pin_Sentit_1_B, HIGH);
  digitalWrite(Pin_Sentit_2_A, LOW);
  digitalWrite(Pin_Sentit_2_B, HIGH);
  
  // Velocitat
  analogWrite(Pin_Vel_1, velocitat);
  analogWrite(Pin_Vel_2, velocitat);
}

void girarDreta() {
  // Servo a la dreta
  for (int i = 90; i <= 150; i += 5) {
    Direccio.write(i);
    delay(50);
  }
}

void girarEsquerra() {
  // Servo a l'esquerra
  for (int i = 150; i >= 30; i -= 5) {
    Direccio.write(i);
    delay(50);
  }
}

void rectilini() {
  // Servo al centre
  Direccio.write(90);
  delay(200);
}

void aturar() {
  // Aturar motors
  analogWrite(Pin_Vel_1, 0);
  analogWrite(Pin_Vel_2, 0);
  
  // Servo al centre
  Direccio.write(90);
}
