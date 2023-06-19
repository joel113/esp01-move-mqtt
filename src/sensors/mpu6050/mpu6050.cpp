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
}

int Mpu6050::getAccelerometerRange() {

}

int Mpu6050::getGyroRange() {

}

int Mpu6050::getFilterBandwidth() {
  
}