// problem_73.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

int gcd(int a, int b)
{
	if(b==0) return a;

	return gcd(b, a%b);
}

struct fraction
{
	unsigned short n,d;
};

bool operator<(const fraction &lhs, const fraction& rhs)
{
	return static_cast<double>(lhs.n)/lhs.d < static_cast<double>(rhs.n) / lhs.d;
}

list<fraction> fractions;

int _tmain(int argc, _TCHAR* argv[])
{

	int count = 0;
	for(int n=1; n < 12000; ++n)
	{
		for(int d=2; d < 12000; ++d)
		{
			if(gcd(n,d) == 1)
			{
				double amount = static_cast<double>(n)/d;
				if(amount > 0.25 && amount < 1.0/3)
					++count;
			}
		}
	}

	cout << count;
	system("PAUSE");
	return 0;
}

