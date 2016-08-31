#ifndef __CALC_FUNCS_2BITS_H__
#define __CALC_FUNCS_2BITS_H__

#pragma warning(disable : 4996)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

double arithmeticCalc2Bits(int digitCount[], int length);
double entropyCalc2Bits(int digitCount[], int length);
double chiSquaredDistribution2Bits(int digitCount[], int length);
int countCases2Bits(int digitCount[], char* fileName, int startPoint, int windowSize);

#endif // !__CALC_FUNCS_2BITS_H__
