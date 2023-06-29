#include <Arduino.h>
#include <WiFi.h>
#include "sensors/mpu6050/mpu6050.h"
#include "credentials/credentials.h"
#include <PubSubClient.h>
#include <ArduinoJson.h>

WiFiClient espClient;
Mpu6050 mpu6050;
PubSubClient client(espClient);

void setup() {
  // Begin serial and setup sensors
  Serial.begin(115200);

  Serial.println("Initializing sensors");

  mpu6050.setup();

  delay(10);

  // Setup wifi connection
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  // WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  // Setup mqtt connection
  client.setServer(MQTT_SERVER, 1883);

  delay(10000);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("joel-sense-1")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  DynamicJsonDocument jsonDocument(1024);

  for(int i = 0; i < 10; i++) {
    mpu6050.loop();
    Acceleration a = mpu6050.getAccelerometerRange();
    Rotation g = mpu6050.getGyroRange();
    float t = mpu6050.getTemperature();
    jsonDocument[i]["acceleration"]["x"] = a.getX();
    jsonDocument[i]["acceleration"]["y"] = a.getY();
    jsonDocument[i]["acceleration"]["z"] = a.getZ();
    jsonDocument[i]["rotation"]["x"] = g.getX();
    jsonDocument[i]["rotation"]["y"] = g.getY();
    jsonDocument[i]["rotation"]["z"] = g.getZ();
    jsonDocument[i]["temperature"] = t;
    delay(100);
  }

  serializeJson(jsonDocument, Serial);

  String json_value;
  serializeJson(jsonDocument, json_value);

  char mqtt_value[200];
  json_value.toCharArray(mqtt_value, 200);
  
  client.publish("/joel-sense-3/sensor", mqtt_value, true);
}
