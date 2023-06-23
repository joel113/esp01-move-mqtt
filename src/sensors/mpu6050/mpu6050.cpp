#include "mpu6050.h"

void Mpu6050::setup() {
  mySerial.begin(115200);
  
  while (!Serial) {
    delay(10);
  }

  if(!mpu.begin()) {
    while(1) {
      delay(10);
    }
  }

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