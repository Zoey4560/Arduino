#include <Wire.h>

// https://pdf1.alldatasheet.com/datasheet-pdf/view/254714/AD/ADXL345.html
// not sure if correct manufacturer
const int SENSOR = 0x53;

int X, Y, Z;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  setRegister(0x31, 0x8); // DATA_FORMAT   2g range (hopefully) 13 bits?
  setRegister(0x2E, 0x80);// INT_ENABLE    Enable DATA_READY interupt
  setRegister(0x2D, 0x8); // POWER_CTL     Measure mode
  delay(100);
}

void loop() {
  Wire.beginTransmission(SENSOR);
  Wire.write(0x32); // Start at DATAX0
  Wire.endTransmission(false);
  
  Wire.requestFrom(SENSOR, 6);
  X = Wire.read() | Wire.read() << 8;
  Y = Wire.read() | Wire.read() << 8;
  Z = Wire.read() | Wire.read() << 8;

  Serial.println("X Y Z");
  Serial.print(X);
  Serial.print(" ");
  Serial.print(Y);
  Serial.print(" ");
  Serial.println(Z);

  delay(10);
}

void setRegister(int reg, byte value) {
  Serial.print("setReg ");
  Serial.print(reg);
  Serial.print(" ");
  Serial.println(value);
   
  Wire.beginTransmission(SENSOR);
  Wire.write(reg);
  Wire.write(value);
  Serial.println(Wire.endTransmission());
}
