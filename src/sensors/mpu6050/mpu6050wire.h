#include <Wire.h>
#include <SoftwareSerial.h>
#include "acceleration.h"
#include "rotation.h"

class Mpu6050Wire {
    SoftwareSerial mySerial;
    const int MPU = 0x68;
    int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;
    float gForceX, gForceY, gForceZ, rotX, rotY, rotZ;
  public:
    Mpu6050Wire() {};
    void setup();
    void loop();
    Acceleration getAccelerometerRange();
    Rotation getGyroRange();
};