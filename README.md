# ESP32 Robot Arm

This project is a robotic arm controlled using an ESP32 microcontroller. The application is built using Qt for the GUI and integrates with the ESP32 for servo control.

## Features

- **Qt GUI**: A user-friendly interface to control the robotic arm.
- **ESP32 Integration**: Communicates with the ESP32 to control servo motors.
- **Cross-Platform**: Designed to work on multiple platforms.

## Project Structure

```
ESPRobotArm/
    ESPRobotArm.ino  # Arduino sketch for ESP32
QtArmRobot/
    esp32.cpp        # ESP32 communication logic
    esp32.h          # Header for ESP32 communication
    main.cpp         # Main application entry point
    mainwindow.cpp   # GUI logic
    mainwindow.h     # Header for GUI logic
    mainwindow.ui    # Qt Designer UI file
    RobotArm.pro     # Qt project file
    build/           # Build artifacts
```

## Project Explanation

This project is designed to control a robotic arm with three servo motors using an ESP32 microcontroller. The servos can be adjusted to angles between 0 and 180 degrees. The communication between the Qt GUI and the ESP32 is established through a serial port (default: COM5). Users can modify the port to suit their setup.

### Key Components

1. **ESP32 Firmware**:

   - The `ESPRobotArm.ino` file contains the Arduino sketch for the ESP32.
   - It handles the communication with the Qt application and controls the servo motors.

2. **Qt Application**:
   - The GUI is built using Qt and provides an intuitive interface for controlling the robotic arm.
   - The `esp32.cpp` and `esp32.h` files manage the communication with the ESP32.
   - The `mainwindow.cpp` and `mainwindow.ui` files define the GUI logic and layout.

### Customization

- **Servo Angles**: The servos are configured to operate within a range of 0 to 180 degrees. This range can be adjusted in the firmware if needed.
- **Serial Port**: The default serial port is set to COM5. Users can change this in the Qt application or the ESP32 firmware to match their system configuration.

### How It Works

1. The Qt application sends commands to the ESP32 via the serial port.
2. The ESP32 interprets these commands and adjusts the servo angles accordingly.
3. The user can control the angles of the three servos through the GUI sliders or input fields.

This setup allows for precise and real-time control of the robotic arm.

## Code Explanation

This section provides an overview of the key components of the code and their functionality:

### ESP32 Firmware (`ESPRobotArm.ino`)

- This Arduino sketch is responsible for controlling the servo motors of the robotic arm.
- It receives commands from the Qt application via the serial port and adjusts the servo angles accordingly.
- The servos are configured to operate within a range of 0 to 180 degrees.
- The default serial communication baud rate is set to 115200.

### Qt Application

#### `esp32.cpp` and `esp32.h`

- These files handle the communication logic with the ESP32.
- The `connect` method establishes a serial connection to the ESP32 (default port: COM5).
- The `sendServoCommand` method sends the servo angles to the ESP32 in a formatted string.

#### `mainwindow.cpp` and `mainwindow.h`

- These files define the logic for the main window of the Qt application.
- The GUI includes sliders for each servo, allowing users to adjust the angles interactively.
- When a slider value changes, the updated angle is sent to the ESP32.
- The `sendAllServoCommands` method sends the current slider values to the ESP32.
- The `updateDegreeLabels` method updates the GUI to reflect the current servo angles.

#### `mainwindow.ui`

- This file defines the layout of the GUI, including sliders and labels for controlling and displaying servo angles.

### Customization

- **Servo Angles**: The range of servo angles (0-180 degrees) can be adjusted in the firmware.
- **Serial Port**: The default serial port is set to COM5. Users can modify this in the Qt application or the ESP32 firmware to match their system configuration.

This explanation should help users understand the structure and functionality of the code, as well as how to customize it for their needs.

## Prerequisites

- **Qt 6.9.0** or later
- **ESP32 Development Board**
- **Arduino IDE** (for ESP32 firmware)

## Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/Yassineg07/RobotArm
   ```
2. Open `RobotArm.pro` in Qt Creator.
3. Build and run the project.
4. Upload `ESPRobotArm.ino` to the ESP32 using the Arduino IDE.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

## Contact

For any inquiries, please contact lansarifedi7@gmail.com or gharbiyasine040@gmail.com.
