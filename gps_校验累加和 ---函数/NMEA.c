#include "NMEA.h"

//$GPGGA,003558,3802.4794,N,11425.9508,E,1,04,16.20,100.3,M,-15.0,M,,*63
//$GPGSA,A,3,06,23,07,31,,,,,,,,,16.97,16.20,4.91*00
//$GPRMC,003558,A,3802.4794,N,11425.9508,E,1.131,169.2,261007,5.3,W*65
//$GPGS$GPGS$GPGS$GPGS$GPRMC,033737,V,5249.4309,N,03755.4661,E,0.000,0.0,291007,0.0,E*6A\r\n

//ASCII码中的十六进制数转换为十进制数
U8 ASCToInt(char c)
{
	U8 rVal = 0;
	
	if ((c >= 'a') && (c <= 'f')) {
		rVal =  c - 'a' + 10;
	}
	else if ((c >= 'A') && (c <= 'F')) {
		rVal =  c - 'A' + 10;
	}
	else if ((c >= '0') && (c <= '9')) {
		rVal = c - '0';
	}
	else {
		;
	}

	return rVal;
}

//ASCII码中的十进制数转换为十六进制数
U8 IntToASC(char c)
{
	U8 rVal = 0;
	
	if ((c >= 0) && (c <= 9)) {
		rVal = c + '0';
	}
	else if ((c >= 0x0a) && (c <= 0x0f)) {
		rVal = c - 10 + 'A';
	}
	else {
		;
	}

	return rVal;
}

U8  NMEA_Checksum(U8 *pFrame)
{
	U8 checksum = 0;
	U8 rx_sum;

	while ((*pFrame != '*')&&(*pFrame != 0U)) {
		checksum ^= *pFrame++;
	}
	
	if (*pFrame != '*') {
		return 0U;
	}
	
	pFrame++;
	rx_sum = (ASCToInt(*pFrame)) * 16U;
	pFrame++;
	rx_sum += (ASCToInt(*pFrame));
	if (checksum != rx_sum) {
		return 0U;
	}
	else {
		return 1U;
	}
}
