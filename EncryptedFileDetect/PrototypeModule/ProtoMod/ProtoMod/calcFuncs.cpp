#include "calcFuncs.h"

Values calcValues(int startPointer, int windowSize, int sampleSize, char filename[])
{
	int (*countCases)(int[], char[], int, int);
	double(*entropyCalc)(int[], int);
	double(*arithmeticCalc)(int[], int);
	double(*chiSquaredDistribution)(int[], int);

	int* digitCount = NULL;
	switch (sampleSize)
	{
	case 2:
		countCases = countCases2Bits;
		entropyCalc = entropyCalc2Bits;
		arithmeticCalc = arithmeticCalc2Bits;
		chiSquaredDistribution = chiSquaredDistribution2Bits;
		digitCount = new int[4];
		memset(digitCount, 0, sizeof(int) * 4);
		break;
	case 4:
		countCases = countCases4Bits;
		entropyCalc = entropyCalc4Bits;
		arithmeticCalc = arithmeticCalc4Bits;
		chiSquaredDistribution = chiSquaredDistribution4Bits;
		digitCount = new int[16];
		memset(digitCount, 0, sizeof(int) * 16);
		break;
	case 8:
		countCases = countCases8Bits;
		entropyCalc = entropyCalc8Bits;
		arithmeticCalc = arithmeticCalc8Bits;
		chiSquaredDistribution = chiSquaredDistribution8Bits;
		digitCount = new int[256];
		memset(digitCount, 0, sizeof(int) * 256);
		break;
	default:
		return Values();
		break;
	}

	Values result;
	result.length = countCases(digitCount, filename, startPointer, windowSize);
	result.arithmeticValue = arithmeticCalc(digitCount, result.length);
	result.CSDValue = chiSquaredDistribution(digitCount, result.length);
	result.entropyValue = entropyCalc(digitCount, result.length);

	return result;
}
