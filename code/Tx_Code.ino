#include <ESP8266WiFi.h>
#include <espnow.h>

// Replace with the receiver's MAC address
uint8_t receiverMAC[] = {0xC8, 0x2B, 0x96, 0x1D, 0x38, 0xB4}; 

// Fire sensor pin
#define FIRE_SENSOR_PIN A0

// LED Pin (Modify with your actual GPIO pin for the LED)
#define LED_PIN D5  // GPIO2 (onboard LED for most ESP8266 boards)

// Fire threshold to trigger the LED (Modify based on sensor calibration)
#define FIRE_THRESHOLD 800

// Define a structure to send fire sensor data
typedef struct struct_message {
  int fireSensorValue;
} struct_message;

struct_message sensorData;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  // Set ESP-NOW role
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);

  // Add peer
  if (esp_now_add_peer(receiverMAC, ESP_NOW_ROLE_SLAVE, 1, NULL, 0) != 0) {
    Serial.println("Failed to add peer");
    return;
  }

  Serial.println("Transmitter ready");
}

void loop() {
  // Read fire sensor value
  sensorData.fireSensorValue = analogRead(FIRE_SENSOR_PIN);

  // Send fire sensor data via ESP-NOW
  esp_now_send(receiverMAC, (uint8_t *)&sensorData, sizeof(sensorData));

  Serial.print("Sent -> Fire Sensor Value: ");
  Serial.println(sensorData.fireSensorValue);

  // Check if the fire sensor value exceeds the threshold
  if (sensorData.fireSensorValue < FIRE_THRESHOLD) {
    // Turn on the LED when fire is detected
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Turn off the LED when no fire is detected
    digitalWrite(LED_PIN, LOW);
  }

  delay(2000);  // Delay for 2 seconds before the next reading
}
