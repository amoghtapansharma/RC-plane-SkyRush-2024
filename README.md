# RC-plane-SkyRush-2024
Participated in skyrush of  MIT Manipal
This repository contains the wireless control system code for the SkyRush 2024 RC aircraft. The system uses Arduino Nano microcontrollers and NRF24L01 wireless transceivers to transmit pilot control inputs from the ground transmitter to the onboard receiver, which controls the aircraft’s motor and control surfaces.

📡 System Overview

The control system is divided into two parts:

1. Transmitter (Ground Station)

Reads joystick and potentiometer inputs

Sends control data wirelessly using NRF24L01

2. Receiver (Aircraft)

Receives control data wirelessly

Controls:

Electronic Speed Controller (ESC)

Roll servo

Pitch servo

Yaw servo

Includes failsafe motor cut-off

🧩 Hardware Components
Transmitter Side

Arduino Nano

NRF24L01 module (with adapter board)

PS2 Joystick module

Potentiometers (Throttle / Yaw)

100 µF capacitor across NRF24L01 VCC–GND

Receiver Side

Arduino Nano

NRF24L01 module (with adapter board)

Brushless ESC

Brushless DC motor

Servo motors (Roll, Pitch, Yaw)

7.4 V Li-ion / Li-Po battery

⚠️ Important: NRF24L01 operates at 3.3 V only. Do NOT connect directly to 5 V.
