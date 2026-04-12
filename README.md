# ir-sensor-basics-and-working
in this repo you will know about ir sensor and how its work and a example code to run with esp
# ESP32 + IR Obstacle Detection Sensor

Detect nearby objects and obstacles in real time using an IR (Infrared) sensor module with an ESP32 microcontroller. The sketch tracks detection events, counts triggers, and measures how long an object stays in range.

---

## Components Required

| Component | Quantity |
|-----------|----------|
| ESP32 Dev Board | 1 |
| IR Obstacle Sensor Module | 1 |
| Jumper Wires | 3 |
| Breadboard (optional) | 1 |

Most IR obstacle sensor modules include an onboard IR LED, IR receiver, LM393 comparator, and a potentiometer for sensitivity adjustment.

---

## Wiring Diagram

```
IR Module       ESP32
---------       -----
VCC    -------> 3.3V
GND    -------> GND
OUT    -------> GPIO 34
```

Note: GPIO 34 is an input-only pin on the ESP32, which makes it ideal for reading digital sensor signals without accidental misconfiguration.

---

## How It Works

The IR LED on the module continuously emits infrared light. When an object comes within range, the reflected infrared light is picked up by the IR receiver. The onboard LM393 comparator then pulls the OUT pin LOW to signal detection.

- OUT = LOW  means an object is detected
- OUT = HIGH means no object is in range

The detection distance can be adjusted by turning the onboard potentiometer, typically ranging from around 2 cm to 30 cm depending on the module.

---

## Setup and Installation

### 1. Install Arduino IDE

Download from https://www.arduino.cc/en/software

### 2. Add ESP32 Board Support

1. Open Arduino IDE and go to File > Preferences
2. Add the following URL to Additional Boards Manager URLs:

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

3. Go to Tools > Board > Boards Manager
4. Search for esp32 and click Install

### 3. No Extra Libraries Needed

This project uses only the built-in digitalRead() function. No additional libraries are required.

### 4. Upload the Sketch

1. Open ir_sensor_esp32.ino in Arduino IDE
2. Select your board: Tools > Board > ESP32 Dev Module
3. Select the correct port: Tools > Port
4. Click Upload

---

## Serial Monitor Output

Open Serial Monitor at 115200 baud. You will see event-based output plus a periodic status line every 2 seconds.

```
=================================
  ESP32 + IR Sensor Demo
=================================
OUT Pin     : GPIO 34
Logic       : LOW = Object Detected
              HIGH = No Object
---------------------------------
IR sensor initialized successfully.
Waiting for object detection...

--- IR Sensor Event ---
Status      : OBJECT DETECTED
Event Count : 1
Timestamp   : 4.32 s
-----------------------

--- IR Sensor Event ---
Status      : OBJECT CLEARED
Object held : 843 ms
Timestamp   : 5.16 s
-----------------------

[Status] 6.0s | No Object | Total Detections: 1
```

---

## Configuration

### Sensitivity / Detection Distance

Turn the potentiometer on the sensor module clockwise to increase sensitivity (detect farther objects) or counterclockwise to reduce it. Adjust until the onboard LED lights up reliably when your target object is at the desired distance.

### Detection Pin

If you need to use a different GPIO pin, change this line in the code:

```cpp
#define IR_SENSOR_PIN  34
```

Use any GPIO pin that supports digital input on your ESP32 board.

---

## Features

| Feature | Description |
|---------|-------------|
| Object Detection | Detects presence of any IR-reflective object |
| Event Logging | Logs each detection and clearance event separately |
| Object Duration | Measures how long an object stays in the detection zone |
| Event Counter | Tracks total number of detection events since power-on |
| Periodic Status | Prints a status summary every 2 seconds |

---

## Troubleshooting

| Problem | Solution |
|---------|----------|
| No detection at all | Check OUT pin is connected to GPIO 34; verify power |
| Always shows detected | Object too close or sensitivity too high; turn potentiometer back |
| Unstable flickering | Adjust potentiometer; avoid strong ambient IR sources like sunlight |
| Board not recognized | Install CP210x or CH340 USB driver for your ESP32 board |
| No serial output | Ensure baud rate is set to 115200 in Serial Monitor |

---

## Possible Projects Using This Sensor

The IR obstacle sensor is one of the most versatile and beginner-friendly sensors available. Below are project ideas across different skill levels.


### Beginner

**Automatic Hand Sanitizer Dispenser**
Trigger a pump or servo motor when a hand is detected in front of the sensor. No contact required, making it hygienic and practical for home or school use.

**Doorbell or Visitor Alert**
Place the sensor at a doorway or entrance. When someone walks through, the ESP32 sends a notification, triggers a buzzer, or logs the entry time to a display or serial port.

**Object Counter**
Mount the sensor across a conveyor or narrow opening. Each time an object breaks the IR beam, increment a counter. Display the count on an OLED screen or send it to a web dashboard.

**Night Light Trigger**
Combine the IR sensor with an LDR. Turn on an LED or lamp only when it is dark AND someone is nearby, saving power compared to a simple always-on night light.


### Intermediate

**Line-Following Robot**
Mount two or more IR sensors on the underside of a robot chassis. Use the reflection difference between a dark line and a light surface to steer motors and follow a track.

**Obstacle-Avoiding Robot**
Attach the IR sensor to the front of a rover. When an obstacle is detected, the ESP32 commands the motors to stop, reverse, and turn before continuing forward.

**Automatic Trash Can Lid**
Use the sensor above the bin to detect when a hand approaches. A servo motor opens the lid automatically and closes it after a set delay. No need to touch the bin.

**Slot Machine / Game Token Counter**
Mount the sensor inside a coin or token slot. Each time a token passes through, count it and update a score or unlock a game action via the ESP32.


### Advanced

**People Counter for Room Occupancy**
Use two IR sensors spaced apart at a doorway. By detecting the order in which the sensors trigger, determine if someone entered or exited. Send occupancy data over Wi-Fi to an MQTT broker or a web server.

**Conveyor Belt Speed Monitor**
Attach a reflective strip to a rotating shaft or belt. Count pulses per second from the IR sensor to calculate RPM or belt speed in real time.

**Security Perimeter with Alerts**
Place multiple IR sensors along a boundary. When any sensor triggers, the ESP32 logs the zone, timestamps the event, and sends an alert via email or Telegram using its Wi-Fi capability.

**Smart Parking System**
Install sensors at each parking space. The ESP32 reads all sensors and reports which spaces are occupied to a central display or web interface, helping drivers find open spots quickly.

**Automated Plant Watering with Presence Detection**
Combine the IR sensor with a soil moisture sensor. Only run the watering pump when the plant area is unoccupied, avoiding accidental spraying on people or pets nearby.

---

## Project Structure

```
esp32-ir-sensor/
|
|-- ir_sensor_esp32.ino   # Main Arduino sketch
|-- README.md             # This file
```

---

## Resources

- ESP32 GPIO Reference: https://randomnerdtutorials.com/esp32-pinout-reference-gpios/
- Arduino digitalRead(): https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/
- LM393 Comparator Datasheet: https://www.ti.com/product/LM393

---

## License

This project is open source and available under the MIT License.

---

## Contributing

Pull requests are welcome. Feel free to open an issue for bugs, improvements, or new project ideas.

---

## Topics

esp32  ir-sensor  infrared  obstacle-detection  arduino  iot  digital-sensor  embedded  robotics  automation
