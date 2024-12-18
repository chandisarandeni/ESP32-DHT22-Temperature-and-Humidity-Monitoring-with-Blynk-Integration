# ESP32 DHT22 Temperature and Humidity Monitoring with Blynk Integration

This project demonstrates real-time monitoring of temperature and humidity using a **DHT22 sensor** connected to an **ESP32 microcontroller** on pin **2**, simulated in **Wokwi**. The sensor data is sent to the **Blynk cloud** for remote monitoring via a web interface.

## Features
- Real-time temperature and humidity monitoring.
- Data displayed on the Blynk web interface.
- Fully simulated using [Wokwi IoT Simulator](https://wokwi.com).

## Components
- **ESP32 DevKit-C V4**
- **DHT22 Temperature and Humidity Sensor**
- **Blynk Web Dashboard**

## How It Works
1. The ESP32 reads temperature and humidity data from the DHT22 sensor.
2. The data is sent to the Blynk cloud using the ESP32 WiFi capabilities.
3. Users can monitor the real-time data on the Blynk web interface (Virtual Pin `V0` for temperature, `V1` for humidity).

## Setup and Simulation
### Required Libraries
Add the following libraries to your `libraries.txt` file:

```
BlynkESP32_BT_WF
AsyncMQTT_ESP32
DHT sensor library
```

### Simulation
- This project is designed to run on the **Wokwi IoT Simulator**.
- [Simulate the project here](https://wokwi.com/projects/new/esp32).

<div align="left">
  <img src="https://github.com/user-attachments/assets/cea620c8-6e5b-4086-995d-6808b529fa03" alt="Wiring Diagram" width="500" height="400">
</div>

| ESP32 Pin | DHT22 Pin |
|-----------|-----------|
| GND       | GND       |
| 5V        | VCC       |
| 2         | SDA       |

## Code
The main Arduino sketch (`sketch.ino`) initializes the DHT22 sensor and connects the ESP32 to the Blynk cloud. The code sends sensor data to the Blynk app every second.

### Key Snippet
```cpp
Blynk.virtualWrite(V0, temperature);
Blynk.virtualWrite(V1, humidity);
```

## File Descriptions
- **`sketch.ino`**: Arduino code to read data from the DHT22 and send it to Blynk.
- **`libraries.txt`**: Required library list for Wokwi simulation.
- **`wokwi-project.txt`**: Reference to simulate the project on Wokwi.
- **`diagram.json`**: Wokwi setup file for simulating the ESP32 and DHT22 connections.

## Simulation Environment
This project is fully simulated in Wokwi IoT Simulator. Use the following `diagram.json` to visualize the hardware setup:

```json
{
  "version": 1,
  "author": "Anonymous maker",
  "editor": "wokwi",
  "parts": [
    { "type": "board-esp32-devkit-c-v4", "id": "esp", "top": -86.4, "left": -177.56, "attrs": {} },
    {
      "type": "wokwi-dht22",
      "id": "dht1",
      "top": -143.7,
      "left": 157.8,
      "attrs": { "humidity": "68", "temperature": "17.7" }
    }
  ],
  "connections": [
    [ "esp:TX", "$serialMonitor:RX", "", [] ],
    [ "esp:RX", "$serialMonitor:TX", "", [] ],
    [ "esp:GND.2", "dht1:GND", "black", [ "v0", "h105.6", "v96", "h172.8" ] ],
    [ "esp:5V", "dht1:VCC", "red", [ "h-19.05", "v67.2", "h364.8" ] ],
    [ "esp:2", "dht1:SDA", "green", [ "h0" ] ]
  ],
  "dependencies": {}
}
```

## How to Use
1. Clone this repository to your local machine.
2. Open `sketch.ino` in Arduino IDE.
3. Install required libraries using `libraries.txt`.
4. Upload the code to your ESP32.
5. Simulate the hardware setup using Wokwi or deploy it physically.


