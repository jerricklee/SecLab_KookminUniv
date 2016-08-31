#include <iostream>
#include "calcFuncs.h"

int main(int argc, char* argv[])
{
	if (argc != 6)
	{
		std::cerr << "4 arguments are required." << std::endl;
	std::cerr << "start pointer(byte), window size(byte), \
					sample size(2, 4, 8 bits), absolute file path" << std::endl;
		return -1;
	}

	//int startPointer = strtol(argv[1], 0, 10);
	//int windowSize = strtol(argv[2], 0, 10);
	//int sampleSize = strtol(argv[3], 0, 10); // only 2, 4, 8
	//char fileName[255];		strcpy_s(fileName, argv[4]);

	//Values v = calcValues(startPointer, windowSize, sampleSize, fileName);
	Values v = calcValues(10, 8, 4, "calcFuncs2Bits.cpp");
	std::cout << v.arithmeticValue << " " << v.entropyValue << " "
		<< v.CSDValue << std::endl;

	return 0;
}