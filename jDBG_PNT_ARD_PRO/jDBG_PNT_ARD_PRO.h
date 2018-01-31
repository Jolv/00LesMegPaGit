// jDBG_PNT_ARD_PRO.h

#ifndef _JDBG_PNT_ARD_PRO_h
#define _JDBG_PNT_ARD_PRO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
/*=============================================
The h-file is used to  control printing when a ARDUINO PRP
is used, because Serial.printing require the USB-TTL hw to be 
connected to the PRO to run reliably

This is not finished and fully tested!

// IMPORTANT   IMPORTANT to control printing the
following stm should be included in the main program:
at the very begining, BEFORE declarations:
//#define removeSerialPrint
in beginning of Setup():
#define BeginjDBGprinting
====================================== ======  */
#ifdef removeSerialPrint
#define VPnt(...) //omdoepes JPnt2 2parameters
#define WPln(...) //omdoepes JPnt3 3parameters
//#define DBGPRINTMACRO bool dbgExtraFlg=1; 
#else
#define BeginjDBGprinting Begin.Serial(115200);	
#define VPnt(x) Serial.print(x);
#define WPln(x) Serial.println(x);
#endif

// Define a debug print macros
#define DbgPlnVplZ
#ifdef DbgPlnVpl
//#define DbgP_ln WPln
#ifndef removeSerialPrint
#define DBGPRINTMACRO bool dbgExtraFlg=1; 
#else  DBGPRINTMACRO bool dbgExtraFlg=0;
#endif // removeSerialPrint
#else
//#define DbgP_ln(...)
#define DBGPRINTMACRO bool dbgExtraFlg=0;
#endif
//----------------
#define DbgPlnFlg
//#define DbgPlnFlg
#ifdef DbgPlnFlg
#define XPnt(x,y) VPnt(F(x));VPnt(y);
#define YPnt(x,y,z) VPnt(F(x));VPnt(y);VPnt(z);
#define DBGPRINTMACRO bool dbgExtraFlg=1; 
#else
#define XPnt(...) //omdoepes JPnt2 2parameters
#define YPnt(...) //omdoepes JPnt3 3parameters
#define DBGPRINTMACRO bool dbgExtraFlg=0;
#endif


#define X2Pnt(x,y) VPnt(F(x));VPnt(y); //only for sts printing
#define Y2Pnt(x,y,z) VPnt(F(x));VPnt(y);VPnt(z);//only for sts printing

DBGPRINTMACRO;



#endif

