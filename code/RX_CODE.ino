#include <ESP8266WiFi.h>
#include <espnow.h>

#define LED_PIN D2       // LED pin (onboard LED for ESP8266)
#define BUZZER_PIN D5    // Buzzer pin

// Define the threshold value for the fire sensor
#define FIRE_THRESHOLD 800

// Define a structure to receive fire sensor data
typedef struct struct_message {
  int fireSensorValue;
} struct_message;

struct_message receivedData;

void setup() {
  Serial.begin(115200);
  
  // Set up the LED and Buzzer pins
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  WiFi.mode(WIFI_STA);

  // Initialize ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  // Set ESP-NOW role
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);

  // Register the callback function for receiving data
  esp_now_register_recv_cb(onDataReceived);

  Serial.println("Receiver ready");
}

void loop() {
  // Nothing needed here, all logic is in the callback
}

// Callback function to handle received data
void onDataReceived(uint8_t *mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&receivedData, incomingData, sizeof(receivedData));

  // Print the received fire sensor value
  Serial.print("Received -> Fire Sensor Value: ");
  Serial.println(receivedData.fireSensorValue);

  // Check if the fire sensor value exceeds the threshold
  if (receivedData.fireSensorValue < FIRE_THRESHOLD) {
    // Turn on the LED and Buzzer if the threshold is exceeded
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    // Turn off the LED and Buzzer if the threshold is not exceeded
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
}
