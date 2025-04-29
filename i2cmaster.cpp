/*
 * i2cmaster.cpp
 */
#include "user_define.h"
#include  <Wire.h>


void init_i2c(){
    Wire.begin();
    Wire.setClock(100000);
}


// i2c write
int i2c_write(UCHAR adr, UCHAR *data, USHORT len){
  int j,ret;
  Wire.beginTransmission((uint8_t)adr);
  for (j=0; j<len; j++){
    Wire.write(data[j]);
  }
  ret = Wire.endTransmission();
  /*
  if (ret == 0){    // DEBUG
    Serial.println("ok");
  } else {
    Serial.print("i2c_write, result=");  Serial.println(ret);
  }
  */
  return ret;
}

// i2c read
int i2c_read(UCHAR adr, UCHAR *data, USHORT len){
  int j,ret;
  j = 0;
  ret = Wire.requestFrom(adr, len);
  while (Wire.available()){
    char c = Wire.read();
    data[j] = c;
    j++;
  }
  return ret;
}

// i2c stop condition
void i2c_stopCond(){
  byte ret;
  ret = Wire.endTransmission(true);
  Serial.print("endTransmission, result=");  Serial.println(ret);
}


// i2c list all address
void i2c_deviceList(){
  UCHAR adr, data[2],ret;

  char *cp PROGMEM =
    "x0 x1 x2 x3 x4 x5 x6 x7 x8 x9 xA xB xC xD xE xF\r\n"
    "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --";
  Serial.print(cp);
  for (adr = 0x00; adr < 0x80; adr++){
    if (!(adr & 0x0F)) Serial.println("");
    ret = i2c_write(adr, data, 0);    // check slave by write
    //ret = i2c_read(adr, data, 1);   // check slave by read
    //if (adr==0x05){ ret=1; }//DEBUG
    //if (ret > 0){
    if (ret == ENDTX_OK){
      if (adr < 0x10){   Serial.print("0"); }
      Serial.print(adr, HEX);  Serial.print(" ");
    } else {
      Serial.print("** ");
    }
  }//for
  Serial.println("");
}
