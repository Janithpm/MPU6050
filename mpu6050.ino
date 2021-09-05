
#include "Wire.h"      
#include "I2Cdev.h"    
#include "MPU6050.h"    

MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;


int data[6];


void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();              

}

void loop() {


  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  data[0] = ax;
  data[1] = ay;
  data[2] = az;
   data[3] = gx;
  data[4] = gy;
  data[5] = gz;

  delay(50);

  Serial.print("Axis X = ");
  Serial.print(data[0]);
  Serial.print("  ");
  Serial.print("Axis Y = ");
  Serial.print(data[1]);
  Serial.print("  ");
  Serial.print("Axis Z = ");
  Serial.print(data[2]);
  Serial.print("G X = ");
  Serial.print(data[3]);
  Serial.print("  ");
  Serial.print("G Y = ");
  Serial.print(data[4]);
  Serial.print("  ");
  Serial.print("G Z = ");
  Serial.println(data[5]);

}
