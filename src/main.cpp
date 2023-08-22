#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "sensors/mpu6050/mpu6050.h"
#include "credentials/credentials.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

WiFiClient espClient;
Mpu6050 mpu6050;
PubSubClient client(espClient);

void sensorSetup() {
  Serial.println("Initializing sensors");
  mpu6050.setup();
}

void wifiConnect() {
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void mqttSetup() {
  client.setServer("joel-telegraf", 1883);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Waiting for serial");
  while (!Serial) {
    delay(10);
  }
  sensorSetup();
  wifiConnect();
  mqttSetup();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("joel-sense-movement")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    Serial.println("foobar");
    reconnect();
  }
  Serial.println("foobar2");
  client.loop();

  DynamicJsonDocument jsonDocument(1024);

  for(int i = 0; i < 10; i++) {
    mpu6050.loop();
    Acceleration a = mpu6050.getAccelerometerRange();
    Rotation g = mpu6050.getGyroRange();
    jsonDocument[i]["acceleration"]["x"] = a.getX();
    jsonDocument[i]["acceleration"]["y"] = a.getY();
    jsonDocument[i]["acceleration"]["z"] = a.getZ();
    jsonDocument[i]["rotation"]["x"] = g.getX();
    jsonDocument[i]["rotation"]["y"] = g.getY();
    jsonDocument[i]["rotation"]["z"] = g.getZ();
    delay(100);
  }

  serializeJson(jsonDocument, Serial);

  String json_value;
  serializeJson(jsonDocument, json_value);

  char mqtt_value[200];
  json_value.toCharArray(mqtt_value, 200);
  
  client.publish("/joel-sense-3/sensor", mqtt_value, true);
}