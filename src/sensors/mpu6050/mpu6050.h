
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "acceleration.h"
#include "rotation.h"

class Mpu6050 {
    Adafruit_MPU6050 mpu;
    SoftwareSerial mySerial;
    sensors_event_t a, g, temp;
  public:
    Mpu6050() {};
    void setup();
    void loop();
    Acceleration getAccelerometerRange();
    Rotation getGyroRange();
    float getTemperature(); 
};