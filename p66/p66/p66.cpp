// p66.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int findMinInX(int d)
{
	if(isPerfectSq(d))
		return -1;

}

//find x such that x^2 - D*(y^2) = 1,
//or -1 if no solution exists
int findX(int d, int y)
{
	//find out if 1 + d*y^2 is a perfect ssquare
	if(isPerfectSq(1+d*y*y))
		return sqrt(1+d*y*y);
	else return -1;

}

bool isPerfectSq(int n)
{
	double res = sqrt(n);
	return (static_cast<int>(res) == res);
}

int _tmain(int argc, _TCHAR* argv[])
{


	return 0;
}

