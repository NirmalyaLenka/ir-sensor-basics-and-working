# ESP32 IR Obstacle Sensor

A small Arduino example that reads a digital IR obstacle-sensor module with an ESP32. The firmware logs detection and clearance transitions, counts detection events, records approximate event timestamps, and measures how long the output remains in the detected state.

## Behavior

The sketch assumes a common active-low module:

- **LOW:** object detected
- **HIGH:** no object detected

Module polarity varies. Confirm the OUT signal and onboard indicator on your particular sensor before relying on these labels. The detection distance depends on the target surface, ambient infrared light, module design, and potentiometer setting.

## Hardware and wiring

| IR module | ESP32 |
| --- | --- |
| VCC | 3.3 V |
| GND | GND |
| OUT | GPIO 34 |

GPIO 34 is input-only on the classic ESP32 and can be used for digital input. Power the module at 3.3 V for this setup and make sure OUT never exceeds the ESP32 GPIO voltage limit. Do not connect a 5 V output directly to an ESP32 input.

## Bill of materials

| Item | Qty. | Notes |
| --- | ---: | --- |
| ESP32 development board | 1 | Classic ESP32 pin mapping |
| IR obstacle sensor module | 1 | Digital OUT type |
| Jumper wires | 3 | VCC, GND, OUT |
| USB data cable | 1 | Upload and Serial Monitor |
| Breadboard | 1, optional | For prototyping |

## Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install ESP32 board support using Espressif's board-manager package URL:
   `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. Open `ir sensor esp32.ino` in Arduino IDE.
4. Select the target ESP32 board and serial port, then compile and upload.
5. Open Serial Monitor at **115200 baud**.

No extra Arduino library is required; the sketch uses `digitalRead()`, `millis()`, and standard Arduino APIs.

## What the code records

- Detection event count since boot
- Timestamp in seconds since boot
- Time between a detection transition and the corresponding clear transition
- Periodic status output every two seconds

The 10 ms loop delay is a simple polling interval, not a guaranteed debounce or safety-rated detection system. Brief transitions can be missed, and this reflective sensor is not suitable as a safety barrier.

## Repository structure

```text
ir-sensor-basics-and-working/
├── ir sensor esp32.ino   # Main ESP32 firmware sketch
└── README.md             # Wiring, setup, BOM, behavior, and limitations
```

## Troubleshooting

| Symptom | Check |
| --- | --- |
| No detection | Confirm OUT wiring, module power, and sensitivity potentiometer |
| Always detected | Check the module's active logic and adjust sensitivity |
| Unstable output | Reduce ambient IR interference and adjust the potentiometer |
| No serial text | Select the correct port and 115200 baud |
| ESP32 resets or input heats | Disconnect power and check for an unsafe 5 V signal |

## Project extensions

- Add a configurable active-high/active-low setting
- Add a proper state debounce or interrupt-driven event capture where appropriate
- Log events to an OLED, SD card, or local dashboard
- Use two sensors for direction-aware counting

## Skills and technologies

`ESP32` · `Arduino C++` · `GPIO` · `Digital sensors` · `Event logging`

## Maintenance & audit

- **Last updated:** 11 November 2026
- **Review scope:** Checked the tracked sketch against the documented pin, logic, file path, features, and BOM.
- **Documentation changes:** Corrected the sketch path and clarified the module's assumed active-low behavior, voltage safety, and limitations.
- **Firmware status:** No firmware change was made; no compile or physical hardware test was run.
- **License:** No `LICENSE` file was found in the current root listing, so this README does not claim a specific reuse license.
