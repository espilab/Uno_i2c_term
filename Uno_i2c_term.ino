/*
 *  Uno_i2c_term.ino
 *  
 *  I2C device accessing tool  
 *    This program can run on the Arduino Uno and Leonard.
 *  (2022-12-18)
 *   This source copied from Leo_i2c_term01
 *   
 *   
 *  Author: Sakamoto
 *  
 *  Ver  Date        note
 *  ---- ----------  ------------------
 *  1.0  2018-08-16  first release
 *  1.1  1025-12-25  Change all var. type to Fixed-width integer types
 */ 

#include  "user_define.h"

void setup() {
  pinMode(13, OUTPUT);  //DEBUG,  LED

  init_uart();
  init_i2c();
  init_session();  
}

void loop() {
}
