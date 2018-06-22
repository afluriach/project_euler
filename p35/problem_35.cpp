// problem_35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<bitset>
#include <memory>
#include <list>
#include <iostream>

using namespace std;

bitset<1000000> primes;
bitset<1000000> primesSummed;
void findPrimes()
{
	primes[0] = false;
	primes[1] = false;
	primes[2] = true;

	for(int i=2; i < 1000000; ++i)
	{
		bool isprime = true;
		for(int j=2; j*j <= i; ++j)
		{
			if(i%j == 0){
				isprime = false;
				break;
			}
		}
		if(isprime) primes[i] = true;
	}
}

int cycleDigit(int n)
{
	if(n < 10)
		return n;
	int digit = n % 10;
	n /= 10;
	n += digit*pow(10.0f, static_cast<int>(log10(static_cast<double>(n)))+1);
	return n;
}

auto_ptr<list<int> > cycleDigits(int n)
{
	auto_ptr<list<int> > nums(new list<int>());
	if(n % 10 == 0)
		return nums;
	nums->push_front(n);

	for(int c = cycleDigit(n); c != n; c = cycleDigit(c))
	{
		//rotations of numbers with zeroes are not considered
		//an empty list should be returned
		if(c % 10 == 0)
		{
			nums->erase(nums->begin(), nums->end());
			return nums;
		}
		nums->push_back(c);
	}
	return nums;
}

bool listIsPrime(list<int> * nums)
{
	list<int>::iterator it;
	for(it = nums->begin(); it != nums->end(); ++it)
	{
		if(!primes[*it])
			return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	long sum = 0;
	findPrimes();

	//consider every prime that has not already been summed
	//uses more memory but saves computation to sum all elements of a cycle and mark them

	for(int i=2; i < 1000000; ++i)
	{
		if(primes[i] && !primesSummed[i])
		{
			auto_ptr<list<int> > iDigits=cycleDigits(i);
			if(listIsPrime(iDigits.get()))
			{
				list<int>::iterator it;
				for(it = iDigits->begin(); it != iDigits->end(); ++it)
				{
					if(!primesSummed[*it])
					{
						sum ++;
						primesSummed[*it] = true;
					}
				}
			}
		}
	}
	cout << sum << endl;
	system("PAUSE");
	return 0;
}

