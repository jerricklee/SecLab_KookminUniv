#include "calcFuncs2Bits.h"
#include <iostream>

double arithmeticCalc2Bits(int digitCount[], int length)
{
	double sum = 0;
	for (int i = 0; i < 4; i++)
		sum += i * digitCount[i];

	return sum / 4.0;
}

double entropyCalc2Bits(int digitCount[], int length)
{
	double entropy = 0;
	double probability;

	for (int i = 0; i < 4; i++)
	{
		if (digitCount[i] != 0)
		{
			probability = (double)digitCount[i] / (double)length;
			entropy += -probability * log2f(probability);
		}
	}
	return entropy;
}

double chiSquaredDistribution2Bits(int digitCount[], int length)
{
	double CSD = 0;
	double expectation = length / (double)4;

	for (int i = 0; i < 4; i++)
		CSD += ((double)digitCount[i] - expectation)*((double)digitCount[i] - expectation) / expectation;

	return CSD;
}

int countCases2Bits(int digitCount[], char * fileName, int startPoint, int windowSize)
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

	memset(digitCount, 0, sizeof(int) * 4);
	length = 0;
	for (int i = 0; i < n; i++)
	{
		unsigned char temp = buffer[i];
		for (int j = 0; j < 4; j++)
		{
			digitCount[(int)temp & 0x3]++;
			temp >>= 2;
		}
		length += 4;
	}

	return length;
}