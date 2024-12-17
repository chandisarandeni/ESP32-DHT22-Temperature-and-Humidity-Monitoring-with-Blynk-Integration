/**
   ESP32 + DHT22 Example for Wokwi
   https://wokwi.com/arduino/projects/322410731508073042
*/

#include "DHTesp.h"

// DHT22 sensor pin
const int DHT_SENSOR_PIN = 2;

// DHT22 sensor object
DHTesp dhtSensor;
float temperature;
float humidity;

/* Blynk credentials */
#define BLYNK_TEMPLATE_ID "TMPL6fog_H_HX"
#define BLYNK_TEMPLATE_NAME "SmartMeasureSystem"
#define BLYNK_AUTH_TOKEN "1N5I26xW11l62uM1Tk9pM2tKlymExRNp"

// Enable serial monitor output
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

// Function to send temperature and humidity data to Blynk app
void sendSensorDataToBlynk() {
  // Retrieve temperature and humidity data
  TempAndHumidity data = dhtSensor.getTempAndHumidity();
  temperature = data.temperature;
  humidity = data.humidity;

  // Send data to Blynk virtual pins
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);

  // Print data to the serial monitor
  Serial.println("Temperature: " + String(temperature, 2) + "°C");
  Serial.println("Humidity: " + String(humidity, 1) + "%");
  Serial.println("---");
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize DHT22 sensor
  dhtSensor.setup(DHT_SENSOR_PIN, DHTesp::DHT22);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Set up timer to call sendSensorDataToBlynk every second
  timer.setInterval(1000L, sendSensorDataToBlynk);
}

void loop() {
  // Run Blynk
  Blynk.run();
  
  // Run the timer
  timer.run();
}
