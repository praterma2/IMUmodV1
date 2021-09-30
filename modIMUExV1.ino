/*
 * Project for CSC230
 * based on M5StickC IMU example
 * no temp, gyro, and ahrs needed
 * 
 * M.Prater mprater@uat.edu
 * 
 */

#include <M5StickCPlus.h>

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;
float accelHigh = 0.0F; ​
float xSq = 0.0F;
float ySq = 0.0F;
float zSq = 0.0F;
float accelCur = 0.0F;
float magSq = 0.0F;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(80, 15);
  M5.Lcd.println("IMU mod TEST");
  
}


/*****************************************
M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);
M5.IMU.getAccelData(&accX,&accY,&accZ);
M5.IMU.getAhrsData(&pitch,&roll,&yaw);
M5.IMU.getTempData(&temp);
*****************************************/
void loop() {
  // put your main code here, to run repeatedly:
  
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  xSq = pow(accX, 2);  
  ySq = pow(accY, 2);
  zSq = pow(accZ, 2);
  magSq = xSq + ySq + zSq;
  accelCur = pow(magSq,0.5);
  if(accelCur > accelHigh){
    accelHigh = accelCur;
  }
  
  
  
  M5.Lcd.setCursor(30, 50);
  M5.Lcd.printf(accelHigh);
  
  

 
  delay(100);
}
