#include "calcFuncs8Bits.h"
#include <iostream>

double arithmeticCalc8Bits(int digitCount[], int length)
{
	double sum = 0;
	for (int i = 0; i < 16; i++)
		sum += i * digitCount[i];

	return sum / 16.0;
}

double entropyCalc8Bits(int digitCount[], int length)
{
	double entropy = 0;
	double probability;

	for (int i = 0; i < 256; i++)
	{
		if (digitCount[i] != 0)
		{
			probability = (double)digitCount[i] / (double)length;
			entropy += -probability * log2f(probability);
		}
	}
	return entropy;
}

double chiSquaredDistribution8Bits(int digitCount[], int length)
{
	double CSD = 0;
	double expectation = length / (double)256;

	for (int i = 0; i < 256; i++)
		CSD += ((double)digitCount[i] - expectation)*((double)digitCount[i] - expectation) / expectation;

	return CSD;
}

int countCases8Bits(int digitCount[], char * fileName, int startPoint, int windowSize)
{
	unsigned int n;
	unsigned char buffer[1024];
	int length = 0;

	FILE* inFile = fopen(fileName, "rb");
	if (inFile == NULL)
		return -1;
	fseek(inFile, 0, SEEK_END);
	if (startPoint - windowSize < 0 || startPoint + windowSize > ftell(inFile))
	{
		std::cerr << "UNDER or OVER FLOW" << std::endl;
		return -1;
	}
	fseek(inFile, 0, startPoint - windowSize);
	n = fread(buffer, sizeof(char), 2 * windowSize, inFile);
	fclose(inFile);

	memset(digitCount, 0, sizeof(int) * 16);
	length = 0;
	for (int i = 0; i < n; i++)
	{
		int frongDigit = ((int)buffer[i] & 0xF0) >> 4;
		int backDigit = (int)buffer[i] & 0x0F;
		digitCount[frongDigit]++;
		digitCount[backDigit]++;
		length += 2;
	}

	return length;
}
