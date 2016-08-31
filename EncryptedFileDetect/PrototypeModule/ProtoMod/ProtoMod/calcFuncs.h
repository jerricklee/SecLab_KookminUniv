#ifndef __CALC_FUNCS_H__

#include "calcFuncs2Bits.h"
#include "calcFuncs4Bits.h"
#include "calcFuncs8Bits.h"

typedef struct values
{
	double arithmeticValue;
	double entropyValue;
	double CSDValue;
	int length;
} Values;

Values calcValues(int startPointer, int windowSize, int sampleSize, char filename[]);

#endif // !__CALC_FUNCS_H__

