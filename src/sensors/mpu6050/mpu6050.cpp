#include "mpu6050.h"
#include "acceleration.h"

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

int Mpu6050::getGyroRange() {

}

int Mpu6050::getFilterBandwidth() {

}