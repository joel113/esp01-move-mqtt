#include "mpu6050.h"

void Mpu6050::setup() {
  mySerial.begin(115200);

  Serial.println("Waiting for serial");
  while (!Serial) {
    delay(10);
  }

  Serial.println("Serial initialized");

  if(!mpu.begin()) {
    while(1) {
      Serial.println("Waiting for MPU6050 to begin");
      delay(10);
    }
  }

  Serial.println("MPU6050 initialized");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void Mpu6050::loop () {
  mpu.getEvent(&a, &g, &temp);
}

Acceleration Mpu6050::getAccelerometerRange() {
  return Acceleration(a.acceleration.x, a.acceleration.y, a.acceleration.z);
}

Rotation Mpu6050::getGyroRange() {
  return Rotation(g.gyro.x, g.gyro.y, g.gyro.z);
}

float Mpu6050::getTemperature() {
  return temp.temperature;
}