/*
	uart.cpp
*/
#include "user_define.h"
#include <string.h>


/* ---------- UART access functions ---------- */

void init_uart(){
  Serial.begin(UART_BPS);
}


int uart_sendchar(UCHAR c){
  Serial.print((char)c);
}

/* get a received char from receive buffer */
bool uart_getchar(UCHAR *c){
  bool f;
  f = false;
  if (Serial.available() > 0){
    f = true;
    *c = (UCHAR)(Serial.read());
  } 
  return f;
}

int recv_len(){
	return Serial.available();
}
