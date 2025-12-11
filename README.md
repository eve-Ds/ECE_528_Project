
# ECE 528 Robotics and Embedded Systems Project

# Introduction
Ovo is a remote-controlled robot equipped with an LCD that displays different faces. Using the control pad, users can move Ovo forward, backward, left, and right, as well as play a short tune. Ovo is controlled wirelessly via Bluetooth through the Bluefruit Connect app. This project was built with the MSP432 Launchpad, TI-RSLK MAX chassis, Bluetooth Low Energy module, a piezo buzzer, and the Nokia 5110 LCD Display. 

# Background and Methodology 



# Block Diagram

![alt text](image.png)

# Components Used

|      Description          |    Quantity    |      Manufacturer        |
|:-------------------------:|:--------------:|:------------------------:|
|    MSP432 LaunchPad       |       1        |     Texas Instruments    |
|   TI-RSLK MAX Chassis     |       1        |          Pololu          |
|  USB-A to Micro-USB Cable |       1        |           N/A            |       
| Adafruit BLE UART Module  |       1        |         Adafruit         |
|   Nokia 1150 LCD Display  |       1        |        SparkFun          |
|        Piezo Buzzer       |       1        |           TDK            |

 
# Pinout Plan

|   Bluetooth Low Energy    |       MSP432 LaunchPad        |
|:-------------------------:|:-----------------------------:|
|        MOD (Pin 1)        |            Pin P4.6           | 
|        CTS (Pin 2)        |           GND                 |
|        TXO (pin 3)        |    Pin P3.2 (PM_UCA2RXD)      |        
|        RXI (Pin 4)        |    Pin3.3 (PM_UCA2TXD)        |
|        VIN (Pin 5)        |       VCC (3.3V)              |
|        RTS (Pin 6)        |       Not Connected           |
|        GND (Pin 7)        |            GND                |
|        DFU (pin 8)        |        Not Connected          |





# Analysis and Results



