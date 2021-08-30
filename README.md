# Introduction

The Simple Wireless Measurement (SWM) board is just that - it is a simple board designed to do wireless measurements for remote embedded circuits. It is capable of measuring current and voltage and transmitting it over Bluetooth.

You can retrieve the data with Python, NRF Connect App, or the Flutter app designed to display this data.

This repo consists of the hardware and software required to run the board.

# This branch

This branch is the MINI branch. It follows feature development on the master branch but the hardware is optimized to run on a smaller board.

# Technology

The SWM board uses an EFM8LB12 microcontroller from Silabs to do the analog measurements. The EFM8 is capable of 14-bit ADC measurements with multiple inputs.

The SWM board uses the JDY-08 Bluetooth module because it provides a simple and transparent way to communicate readings over BLE: just connect and send the data over UART. It is also a very low-cost module (< $4).

It is powered by the MCP16415 boost module which can take input ranges from 0.8V to 5.5V, which means that it can be powered by anything from a single AA rechargable to a 5V input from another board.

The total cost of the board comes up to roughly $15, which makes it cheap enough to throw permanently into a system to do wireless reporting of voltage and current. The board size is also small - about the size of two postage stamps placed side by side, which allows it to be embedded in other applications.

| Use case            | Description                                                                                            |
| ------------------- | ------------------------------------------------------------------------------------------------------ |
| Drones              | Measure the power draw of electronics on your drone over time                                          |
| Robotics            | Keep an eye on motors and batteries                                                                    |
| IoT                 | Monitor battries remotely                                                                              |
| Distributed systems | Monitor various test points in the system simultaneously to get a holistic picture of what is going on |
| Rocketry            | Monitor your wireless systems as you mount the rocket. Never wonder again if your system is dead.      |

## Specs

| Current draw | Voltage | Status   |
| ------------ | ------- | -------- |
| 48 mA        | 1.2V    | Fully On |
| 15 mA        | 3.3V    | Fully On |

# Arduino Version

The Arduino Version is a simplified version of the full board but can be programmed directly in Arduino. It has a lower ADC resolution and a lower UART baud rate because it is using Software Serial.

# Software

The python code is searches for a specific device and prints the TX-RX characteristic on the JDY-08.
