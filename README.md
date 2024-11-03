# ThothBox: The Ultimate Cybersecurity Toolkit

![ThothBox Logo](path/to/logo.png) <!-- Add logo path -->

## Overview

**ThothBox** is a powerful, portable device designed for cybersecurity professionals and enthusiasts. Combining the capabilities of both the **nRFBOX** and **Superior Boy**, ThothBox provides a comprehensive suite of features for wireless communication analysis, testing, and experimentation. This open-source project leverages advanced microcontrollers—**ESP32** and **RP2040**—and a variety of wireless technologies to equip users with tools for security assessments, educational exploration, and hobbyist projects.

## Table of Contents

- [Features](#features)
- [Core Functions](#core-functions)
- [Getting Started](#getting-started)
- [Hardware Components](#hardware-components)
- [Schematic](#schematic)
- [Use Cases](#use-cases)
- [Code & Documentation](#code--documentation)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Features

ThothBox comes packed with a variety of features that make it an essential tool for cybersecurity professionals:

### Software Features
- **Dynamic Channel Scanning**: Monitors wireless frequencies, identifying active devices and channels across 2.4 GHz and Sub-1 GHz bands.
- **Signal Analysis**: Provides insights into signal strength, modulation, and data rates.
- **Jamming Capabilities**: Supports multiple jamming modes for network resilience testing.
- **Device Emulation**: Simulates BLE and NFC devices for security testing.
- **User-Friendly Interface**: Easy navigation via an OLED display and tactile controls.

### Hardware Features
- **ESP32 Wroom32U**: Dual-core processing with Wi-Fi/Bluetooth capabilities.
- **RP2040**: Additional processing power and functionality.
- **NRF24 & CC1101 Modules**: Communication in 2.4 GHz and Sub-1 GHz frequencies.
- **PN532 Module**: Supports NFC/RFID functionalities.
- **Sensors**: 9-axis gyroscope (MPU9250) and barometer (BMP280) for environmental awareness.
- **MicroSD Support**: Data storage and logging capabilities.

## Core Functions

### 1. Wireless Communication Scanner
Continuously scans for devices operating in the 2.4 GHz and Sub-1 GHz bands.

### 2. Signal Analyzer
Offers detailed information about detected signals.

### 3. Jamming and Interference
Disrupts specific wireless communication channels.

### 4. Device Emulation
Emulates BLE and NFC devices for security assessments.

### 5. BadUSB/HID Functionality
Simulates Human Interface Device (HID) attacks.

### 6. Wi-Fi and IoT Scanning
Detects and analyzes nearby Wi-Fi networks.

### 7. Infrared Communication
Facilitates the transmission and reception of infrared signals.

### 8. Gaming Features
Includes basic games for entertainment during breaks.

## Getting Started

### Step 1: Gather Your Components
To build your ThothBox, you will need the following components:

- ESP32 Wroom32U
- RP2040 microcontroller
- NRF24 GTmini Modules
- CC1101 transceiver
- PN532 NFC/RFID module
- MPU9250 9-Axis Gyroscope
- BMP280 Barometer
- MicroSD Card module
- ST7735s TFT display
- Power management components

### Step 2: Assembly Options
- **Breadboard Prototype**: For initial testing and modifications.
- **Custom PCB**: Follow the provided design files for a more durable build.

### Step 3: Programming the Device
Download the code from the GitHub repository and upload it to the ESP32 and RP2040 using the Arduino IDE or compatible programming environment.

## Schematic

The schematic detailing the connections between components is available in the GitHub repository. It includes power management instructions to ensure stable operation.

## Use Cases

- **Wireless Security Testing**: Ideal for assessing the security of wireless networks.
- **Educational Tool**: Great for learning about wireless communication protocols.
- **Research and Development**: Useful for developing and testing new communication methods.
- **Hobby Projects**: Perfect for hobbyists exploring wireless technology.

## Code & Documentation

The source code, schematics, and documentation can be found on our [GitHub repository](https://github.com/cifertech/thothbox). Feel free to explore, contribute, and share your feedback!

## Contributing

We welcome contributions to ThothBox! If you have suggestions, improvements, or bug fixes, please create a pull request or open an issue on GitHub.

## License

ThothBox is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Acknowledgements

Special thanks to our sponsors and contributors who have supported the ThothBox project. Your efforts make this project possible!

---

Whether you're a cybersecurity expert or a curious beginner, ThothBox is your go-to device for exploring the fascinating world of wireless communication. Happy building!
