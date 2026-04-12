/*
 * IR (Infrared) Obstacle Detection Sensor with ESP32
 * Detects objects and obstacles using infrared reflection
 *
 * Wiring:
 *   IR Module VCC  -> ESP32 3.3V
 *   IR Module GND  -> ESP32 GND
 *   IR Module OUT  -> ESP32 GPIO 34 (Digital Output)
 *
 * How it works:
 *   - The IR LED emits infrared light
 *   - The IR receiver detects reflected light from nearby objects
 *   - OUT pin goes LOW when an object is detected
 *   - OUT pin stays HIGH when no object is in range
 *   - Onboard potentiometer adjusts detection sensitivity/distance
 *
 * Required Library: None (uses built-in digitalRead)
 */

// Pin Definitions
#define IR_SENSOR_PIN  34   // Digital output from IR sensor module

// Detection state tracking
bool lastState = HIGH;
unsigned long lastDetectionTime = 0;
unsigned long detectionCount = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Set IR sensor pin as input
  pinMode(IR_SENSOR_PIN, INPUT);

  Serial.println("=================================");
  Serial.println("  ESP32 + IR Sensor Demo         ");
  Serial.println("=================================");
  Serial.println("OUT Pin     : GPIO 34");
  Serial.println("Logic       : LOW = Object Detected");
  Serial.println("             HIGH = No Object");
  Serial.println("---------------------------------");
  Serial.println("IR sensor initialized successfully.");
  Serial.println("Waiting for object detection...");
  Serial.println();
}

void loop() {
  bool currentState = digitalRead(IR_SENSOR_PIN);
  unsigned long currentTime = millis();

  // Object just detected (HIGH -> LOW transition)
  if (currentState == LOW && lastState == HIGH) {
    detectionCount++;
    lastDetectionTime = currentTime;

    Serial.println("--- IR Sensor Event ---");
    Serial.println("Status      : OBJECT DETECTED");
    Serial.print("Event Count : ");
    Serial.println(detectionCount);
    Serial.print("Timestamp   : ");
    Serial.print(currentTime / 1000.0, 2);
    Serial.println(" s");
    Serial.println("-----------------------");
    Serial.println();
  }

  // Object just cleared (LOW -> HIGH transition)
  if (currentState == HIGH && lastState == LOW) {
    unsigned long duration = currentTime - lastDetectionTime;

    Serial.println("--- IR Sensor Event ---");
    Serial.println("Status      : OBJECT CLEARED");
    Serial.print("Object held : ");
    Serial.print(duration);
    Serial.println(" ms");
    Serial.print("Timestamp   : ");
    Serial.print(currentTime / 1000.0, 2);
    Serial.println(" s");
    Serial.println("-----------------------");
    Serial.println();
  }

  // Continuous status print every 2 seconds
  static unsigned long lastPrint = 0;
  if (currentTime - lastPrint >= 2000) {
    Serial.print("[Status] ");
    Serial.print(currentTime / 1000.0, 1);
    Serial.print("s | ");
    Serial.print(currentState == LOW ? "OBJECT DETECTED" : "No Object");
    Serial.print(" | Total Detections: ");
    Serial.println(detectionCount);
    lastPrint = currentTime;
  }

  lastState = currentState;
  delay(10); // Small debounce delay
}
