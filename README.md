# RC Line - Radio-Teledirigit basat en Arduino

Repositori del Projecte de Recerca (PdR) **RC Line** dels alumnes de 4t ESO de l'Institut Joan Oró.

## 📋 Descripció del Projecte

Construcció d'un **radio-teledirigit basat en Arduino** amb els següents objectius:
- ✅ Funcionalitat completa de control remot
- ✅ Pressupost menor de **30€**
- ✅ Sistema de doble Arduino: un per al comandament i un per al vehicle
- ✅ Comunicació wireless mitjançant mòdul nRF24L01

## 🎯 Objectius del Projecte

1. **Aprendre programació en C++** per a microcontroladors
2. **Comprendre el funcionament** de sistemes de control remot
3. **Construir un prototip funcional** de forma econòmica
4. **Aplicar coneixements d'electrònica** i programació

## 🛠️ Components Utilitzats

| Component | Funció |
|-----------|--------|
| Arduino Nano (x2) | Microcontrolador principal |
| nRF24L01 | Mòdul de comunicació wireless |
| Joystick analògic | Entrada de control |
| Servo motor | Control de direcció |
| Motors DC (x2) | Propulsió de les rodes |
| Controlador L298N | Driver de motors |
| Bateria 9V | Font d'alimentació |

## 📐 Estructura del Projecte

### Arxitetura de Control
```
Comandament (Mando):
  Arduino Nano 1 → Joystick → nRF24L01 TX

Vehicle (Cotxe):
  Arduino Nano 2 ← nRF24L01 RX ← Motors + Servo
```

### Estructura de Carpetes
```
RC-Line/
├── Codi/
│   ├── src/
│   │   ├── main.cpp          # Lògica principal
│   │   ├── joystick.cpp      # Lectura del joystick
│   │   ├── motors.cpp        # Control de motors i servo
│   │   └── radio.cpp         # Comunicació wireless
│   ├── include/
│   │   └── config.h          # Configuració de pins
│   └── platformio.ini        # Configuració PlatformIO
└── README.md
```

## 🔌 Esquema de Connexions

### Arduino Mando (Comandament)
| Component | Pin Arduino | Funció |
|-----------|------------|--------|
| Joystick VRX | A0 | Lectura eix X (velocitat) |
| Joystick VRY | A1 | Lectura eix Y (direcció) |
| Joystick GND | GND | Connexió a massa |
| Joystick VCC | 5V | Alimentació (+5V) |
| nRF24 CE | D9 | Chip Enable |
| nRF24 CSN | D10 | Chip Select |
| nRF24 SCK | D13 | Clock SPI |
| nRF24 MOSI | D11 | Master Out Slave In |
| nRF24 MISO | D12 | Master In Slave Out |
| nRF24 VCC | 3V3 | Alimentació (+3.3V) |

### Arduino Cotxe (Vehicle)
| Component | Pin Arduino | Funció |
|-----------|------------|--------|
| Servo Direcció | D3 | Control servomotor (PWM) |
| Motor L298N ENA | D5 | Velocitat motor 1 (PWM) |
| Motor L298N ENB | D6 | Velocitat motor 2 (PWM) |
| Motor L298N IN1 | D7 | Direcció motor 1 |
| Motor L298N IN2 | D8 | Direcció motor 2 |
| nRF24 CE | D9 | Chip Enable |
| nRF24 CSN | D10 | Chip Select |
| nRF24 SCK | D13 | Clock SPI |
| nRF24 MOSI | D11 | Master Out Slave In |
| nRF24 MISO | D12 | Master In Slave Out |
| nRF24 VCC | 3V3 | Alimentació (+3.3V) |

## 💻 Instal·lació i Configuració

### Requisits
- Arduino IDE o PlatformIO
- Driver de ports USB CH340 (per a Arduino Nano)
- Biblioteques:
  - `RF24` (nRF24L01)
  - `Servo` (servo control)

### Instruccions

1. **Clonar o descarregar el repositori:**
```bash
git clone https://github.com/AlexRG2010/RC-Line.git
cd RC-Line/Codi
```

2. **Instal·lar biblioteques (si uses Arduino IDE):**
   - Sketch → Include Library → Manage Libraries
   - Busca: `RF24` i `Servo`
   - Click Install

3. **Configurar l'ambiente:**
   - Obrir `include/config.h`
   - Verificar els pins segons la taula de connexions

4. **Compilar i carregar el codi:**

**Comandament (Mando):**
```bash
# Amb PlatformIO
pio run -e Mando -t upload

# Amb Arduino IDE
Sketch → Build (o Ctrl+R)
Sketch → Upload (o Ctrl+U)
```

**Vehicle (Cotxe):**
```bash
# Amb PlatformIO
pio run -e Cotxe -t upload

# Amb Arduino IDE
Seleccionar configuració per a Cotxe a config.h
Sketch → Build i Upload
```

## 🚀 Com Funciona

### Flux de Control
1. **Lectura de joystick** (Mando): Es llegeixen els valors analògics (0-1023) i es mapegen a rang (-100 a 100)
2. **Transmissió wireless**: Els valors es envien via nRF24L01 a través de 5 bytes
3. **Recepció de dades** (Cotxe): L'Arduino receptor captura els bytes
4. **Control de motors**: Els valors es converteixen en velocitat (0-255) i direcció
5. **Moviment del vehicle**: Els motors giren amb velocitat variable i el servo controla la direcció

### Paràmetres de Control
- **Velocitat**: -100 (enrere) a +100 (endavant)
- **Direcció**: -100 (esquerra) a +100 (dreta)
- **Zona morta del joystick**: ±30 (evita drifts)
- **Mapeig servo**: 0-180 graus

## 🐛 Debugging i Resolució de Problemes

### El cotxe no es mou
- ✓ Verificar connexions dels motors
- ✓ Comprovar tensió de la bateria
- ✓ Revisar compilació sense errors
- ✓ Obrir Serial Monitor (9600 baud) per veure missatges

### No hi ha comunicació wireless
- ✓ Verificar pins CE i CSN (D9 i D10)
- ✓ Assegurar alimentació 3.3V del nRF24
- ✓ Comprovar que els dos Arduinos usen la mateixa adreça (`'c','a','n','a','l'`)
- ✓ Canviar de canal (76) si hi ha interferències

### Servo que salta/vibra
- ✓ Revisar alimentació estable de 5V
- ✓ Verificar cable de senyal en pin PWM (D3)
- ✓ Provar mapeig manual: `Direccio.write(90)` al setup

## 📊 Specs Tècniques

- **Microcontrolador**: ATMega168 (Arduino Nano)
- **Freqüència**: 16 MHz
- **RAM**: 1 KB
- **Flash**: 16 KB
- **Comunicació wireless**: 2.4 GHz, 250 kbps
- **Alcance**: ~30 metres (en condicions òptimes)
- **Alimentació**: 7-12V

## 📚 Conceptes Teòrics Implementats

- ✅ Microcontroladors i programació en C++
- ✅ Entrada/sortida digital i analògica
- ✅ Modulació PWM (Pulse Width Modulation)
- ✅ Comunicació wireless (nRF24L01)
- ✅ Control de motors DC
- ✅ Servomotors de posició
- ✅ Mapatge de rangs de valors

## 🎓 Autors

Alumnes de 4t ESO de l'Institut Joan Oró (Badminton)  
Projecte de Recerca 2025-2026

## 📄 Llicència

Aquest projecte es distribueix amb fins educatius.

## 🔗 Enllaços d'Interès

- [Arduino Documentation](http://docs.arduino.cc)
- [RF24 Library GitHub](https://github.com/nRF24/RF24)
- [Servo Library](https://www.arduino.cc/reference/en/libraries/servo/)

---

**Últim update**: Desembre 2025  
**Estat**: ✅ Funcional i testat
