/*
  user_define.h
*/
#include     "Arduino.h"


//============ general definitioin ============
#define	UINT      unsigned int
#define	USHORT    unsigned short int
#define	SHORT     signed short int
#define	UCHAR     unsigned char


#define	TRUE	0x01
#define	FALSE	0x00

#define	CR	((char)0x0d)
#define	LF	((char)0x0a)
#define	BEL	((char)0x07)
#define	BS	((char)0x08)
#define	ESC	((char)0x1b)


//==================================================
// uart.cpp related definitions,vars,functions
//==================================================
//---------- define for uart ----------
#define  UART_BPS  115200
//---------- uart functions ----------
int recv_len(void);
int uart_sendchar(UCHAR c);
bool uart_getchar(UCHAR *c);
void init_uart(void);


//==================================================
// i2cmaster.cpp related definitions,vars,functions
//==================================================
//---------- define for i2cmaster ----------
#define ENDTX_OK      0     // success (endTransmissioin() result, arduino definitioin)
#define ENDTX_TOLONG  1     // data too long
#define ENDTX_NACK_ADR   2  // NACK (address)
#define ENDTX_NACK_DAT   3  // NACK (data)
#define ENDTX_ERR_OTHER  4  // other error
//---------- i2cmaster functions ----------
void init_i2c(void);
int i2c_write(UCHAR adr, UCHAR *data, USHORT len);
int i2c_read(UCHAR adr, UCHAR *data, USHORT len);
void i2c_stopCond(void);
void i2c_deviceList(void);


//==================================================
// session.cpp related definitions,vars,functions
//==================================================
//---------- session functions ----------
void init_session(void);
