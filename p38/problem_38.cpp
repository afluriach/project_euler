// problem_38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <sstream>
#include <iostream>
using namespace std;

//add number to digit collector.
//if false, the resulting concatenation is not a valid
//pandigital number
bool applyDigits(bool (&digits)[10], int n)
{
	if(n % 10 == 0)
		return false;
	
	while(n != 0)
	{
		int crntDigit = n % 10;
		n /= 10;

		if(digits[crntDigit] || crntDigit == 0)
			return false;
		else
		{
			digits[crntDigit] = true;
		}
	}
	return true;
}

//test if a digit collector refers to a valid pandigital number
bool isPandigital(const bool (&arr)[10])
{
	if(arr[0]) return false;

	for(int i=1; i < 10; ++i)
	{
		if(!arr[i]) return false;
	}
	return true;
}

//iterate through cofactors:
//if a product is found that is 1 to 9 panddigital, we
//have found an answer
//otherwise, if we encounter a reepeat or the digit 0, 
//there is none, return -1
//
long findConcatProduct(long n, int base)
{
	bool digitCollector[10];
	memset(digitCollector, 0, sizeof(bool)*10);
	stringstream numAccumulator;
	for(long cofactor = 1; ; ++cofactor)
	{
		long product = n*cofactor;
		numAccumulator << product;
		if(applyDigits(digitCollector, product))
		{
			if(isPandigital(digitCollector))
			{
				cout << "found pandigital: " << numAccumulator << endl;
				return atol(numAccumulator.str().c_str());
			}
			//else continue 
		}
		else
		{
			//we have run into an issue and a pandigital number
			//can't be built
			cout << "invalid number: " << numAccumulator.str() << endl;
			return -1;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	long largest=0;

	for(int i=1; i <= 10000; ++i)
	{
		long temp=findConcatProduct(i, -1);
		if(temp > largest)
			largest = temp;
	}
	cout << largest << endl;
	system("PAUSE");
	return 0;
}

