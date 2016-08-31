#ifndef __CALC_FUNCS_8BITS_H__
#define __CALC_FUNCS_8BITS_H__

#pragma warning(disable : 4996)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

double arithmeticCalc8Bits(int digitCount[], int length);
double entropyCalc8Bits(int digitCount[], int length);
double chiSquaredDistribution8Bits(int digitCount[], int length);
int countCases8Bits(int digitCount[], char* fileName, int startPoint, int windowSize);

#endif // !__CALC_FUNCS_8BITS_H__
