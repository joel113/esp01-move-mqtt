#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "acceleration.h"
#include "rotation.h"

class Mpu6050 {
  private:
    Adafruit_MPU6050 mpu;
    sensors_event_t a, g, temp;
  public:
    Mpu6050() : mpu() {};
    void setup();
    void loop();
    Acceleration getAccelerometerRange();
    Rotation getGyroRange();
    float getTemperature(); 
};