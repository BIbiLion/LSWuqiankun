#ifndef __NMEA__
#define __NMEA__

#include "../app/def.h"

U8	ASCToInt(char c);
U8	IntToASC(char c);
U8  NMEA_Checksum(U8 *pFrame);

#endif

