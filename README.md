## Hybrid Scalable Smart Home: Upgrading Legacy GSM-DTMF to ESP32 IoT Control
## Overview
This project represents a technical evolution of a home automation system, transitioning from a Legacy V1.0 (based on Arduino Uno and GSM-DTMF) to an Enhanced V2.0 powered by the ESP32 IoT ecosystem. The core philosophy of this upgrade is Scalability—maintaining the reliability of the established GSM infrastructure while integrating modern, high-speed IoT capabilities.

## Link to the previous version:
https://github.com/ahmedsamy200525-ship-it/Arduino-DTMF-Home-Automation

## The Technical Journey: From V1.0 to V2.0
Version 1.0 (The Legacy System)
The original architecture relied on an Arduino Uno and a SIM800L GSM Module. Users controlled home appliances via DTMF (Dual-Tone Multi-Frequency) tones during a standard phone call.


## Engineering Challenge:

A significant Voltage Drop was encountered in the GSM module during network bursts and active calls, leading to system instability and frequent resets.


## The Solution:

Implemented a robust power management strategy using a high-capacity Electrolytic Capacitor to act as a local energy reservoir, alongside a Step-down Module to stabilize the power rails for the logic circuits.


## Version 2.0 (The IoT Upgrade)

The upgraded system introduces the ESP32 as the primary controller, leveraging its dual-core processing and built-in wireless connectivity.


## Hybrid Control Logic:

The system supports three simultaneous control modes: Bluetooth (via Dabble App), Physical Manual Buttons, and the Legacy GSM system.


## Audio Precision:

Integrated a dedicated Voice Decoder on the GSM module to ensure high-accuracy tone recognition and eliminate command errors.


## Enhanced HMI (Human-Machine Interface): 

Added an I2C 16x2 LCD for real-time status monitoring and an Active Buzzer to provide distinctive audible feedback for each command.


## Hardware Architecture and Components
Microcontrollers:

ESP32 (Main IoT Hub), Arduino Uno (Legacy Controller).


## Communication: 

Bluetooth Serial, SIM800L GSM Module, DTMF Decoder.

## Peripherals:

2-Channel Relay Module (Active LOW configuration), 16x2 LCD with I2C, Active Buzzer.


## Power Management:

7805 Voltage Regulator for 5V stability, Step-down modules, and stabilizing capacitors.


## Safety Implementation: 

Utilized GPIO 16 and 17 for relay control to prevent interference during the ESP32 boot process and ensure safe startup.

## Operation Modes
Bluetooth Mode (IoT): Use the Dabble App (Terminal Mode) to send commands. The system provides real-time "Two-Way" feedback directly to the phone screen.

1 / 4: Toggle LED 1 ON/OFF.

2 / 3: Toggle LED 2 ON/OFF.

8 / 0: Master Switch (ALL ON/OFF).

## Manual Mode: Physical push-buttons on the control panel for instant hardware override.

## GSM Mode (Legacy): Call the system from any phone and use the dial pad to trigger commands via DTMF tones.



## Academic Context
This project was developed as a practical application for the **Automatic Control** course at Mansoura National University. 
The system demonstrates the principles of **Closed-Loop Monitoring** and feedback integration. By utilizing the I2C LCD and Bluetooth Serial Terminal, the system provides real-time state confirmation (Feedback), ensuring that the controller's output matches the user's intent—a fundamental concept in reliable control system design.

## Key Engineering Solutions
* **Power Stability:** Overcoming SIM800L voltage drops using electrolytic capacitors.
* **Noise Mitigation:** Implementing software debounce and internal pull-up resistors to prevent ghost switching.
* **Boot Safety:** Strategic GPIO selection (16, 17) to ensure stable startup states for connected actuators.



## Media and Demonstration
Watch the Project in Action





https://github.com/user-attachments/assets/f2c1add1-a0ae-4592-b374-48e41ddaf996



