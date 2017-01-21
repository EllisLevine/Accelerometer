/*
 *              E L L I S  L E V I N E
 *                     Team 86
 *                     1/21/17
 *              Accelerometer: LIS3DH
 * 
 * Gets 3 axis values, finds the difference between them, 
 *  calculates the angle made from the differences, and 
 *          prints the angle to the console.
 *  Note: This is only accurate to around 40-45 degrees.
 */

#include "SparkFunLIS3DH.h"
#include "Wire.h"
#include "SPI.h"
#include "Math.h"

LIS3DH myIMU; //Default constructor is I2C, addr 0x19.

void setup() {
  // Set-up code
  Serial.begin(9600);
  delay(1000);
  Serial.println("Processor Resetted.\n");

  // Configures myIMU
  myIMU.begin();

}

void loop()
{
  // Repeats call_ angle function every 1000 microseconds
  calc_angle();
  delay(1000);
}

void calc_angle() {
  // INITIALIZATIONS
  // floats x y and z come from the the accelerometer axis.
  // The result (or angle) is also instantiated here 
  // Finally I instantiate the squared values
  float x = myIMU.readFloatAccelX();
  float y = myIMU.readFloatAccelY();
  float z = myIMU.readFloatAccelZ();
  float angle;
  float angleX;
  float angleY;
  unsigned long xsqrd, ysqrd, zsqrd;
  
  // Note we do not have to find the differences. myIMU does it for us

  // Squared values here so I wouldnt have to later
  xsqrd = ((unsigned long)(x * x));
  ysqrd = ((unsigned long)(y * y));
  zsqrd = ((unsigned long)(z * z));

  // Calculate angle of x axis using arctan 
  angle = x / (sqrt(ysqrd + zsqrd));
  angleX  = atan(angle);

  // Calculate angle of y axis using arctan
  angle = y / sqrt(xsqrd + zsqrd);
  angleY = atan(angle);

  // Print both angle x and y to the consol when called 
  Serial.print(" Angle X = ");
  Serial.println(angleX);
  
  Serial.print(" Angle Y = ");
  Serial.println(angleY);
  
} 

