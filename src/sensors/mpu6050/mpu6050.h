
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SoftwareSerial.h>

class Mpu6050 {
    Adafruit_MPU6050 mpu;
    SoftwareSerial mySerial;
  public:
    Mpu6050() {};
    void setup();
    int getAccelerometerRange();
    int getGyroRange();
    int getFilterBandwidth();
}