#include <Arduino.h>
#include <WiFi.h>
#include "sensors/mpu6050.h"
#include "credentials/credentials.h"
#include <PubSubClient.h>
#include <ArduinoJson.h>

WiFiClient espClient;
Mpu6050 mpu6050;
PubSubClient client(espClient);

void setup() {
  // Begin serial and setup sensors
  Serial.begin(115200);
  mpu6050.setup();

  delay(10);

  // Setup wifi connection
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
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
  // put your main code here, to run repeatedly:
}
