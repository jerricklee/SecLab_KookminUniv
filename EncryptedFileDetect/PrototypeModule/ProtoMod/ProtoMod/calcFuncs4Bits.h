#ifndef __CALC_FUNCS_4BITS_H__
#define __CALC_FUNCS_4BITS_H__

#pragma warning(disable : 4996)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

double arithmeticCalc4Bits(int digitCount[], int length);
double entropyCalc4Bits(int digitCount[], int length);
double chiSquaredDistribution4Bits(int digitCount[], int length);
int countCases4Bits(int digitCount[], char* fileName, int startPoint, int windowSize);

#endif // !__CALC_FUNCS_4BITS_H__
