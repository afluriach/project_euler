#include <cstdlib>
#include <bitset>
#include <iostream>

const int primesMax = 1000000;
using namespace std;

bitset<primesMax> primes;

int ndigits(int n)
{
	if (n < 10) return 1;
	if (n < 100) return 2;
	if (n < 1000) return 3;
	if (n < 10000) return 4;
	if (n < 100000) return 5;
	if (n < 1000000) return 6;
}

int nmod(int n)
{
	if (n < 10) return 1;
	if (n < 100) return 10;
	if (n < 1000) return 100;
	if (n < 10000) return 1000;
	if (n < 100000) return 10000;
	if (n < 1000000) return 100000;
}

bool singleDigitPrime(int n)
{
	return (n==2 || n==3 || n==5 || n==7);
}

//the number is a prime, and every successive removal of the most significant
//digit leaves you with a prime, until you are left with a single digit prime
bool truncatableLeft(int n)
{
	if(!primes[n]) return false;
	while(n > 10)
	{
		n = n % nmod(n);
		if(!primes[n]) return false;
	}
	return singleDigitPrime(n);
}

//the number is a prime, and every successive removal of the least significant
//digit leaves you with a prime, until you are left with a single digit prime
bool truncatableRight(int n)
{
	if(!primes[n]) return false;

	while(n>10)
	{
		n /= 10;
		if(!primes[n]) return false;
	}
	return singleDigitPrime(n);
}

void buildPrimes()
{
	primes[2] = true;
	for(int i=3; i < primesMax; i++)
	{
		bool isPrime = true;
		for(int j= 2; j*j <= i ; j++)
			if(primes[j] && i%j ==0)
			{
				isPrime = false;
				break;
			}
		if(isPrime) primes[i] = true;
	}
}

int main()
{
	buildPrimes();
	int primesFound=0;
	int sum=0;
	int truncPrimes[11];

	for(int i=11; i<primesMax; i++)
	{
		if(truncatableLeft(i) && truncatableRight(i)) truncPrimes[primesFound++] = i;
	}

	for(int i=0;i<primesFound; i++)
	{
		sum += truncPrimes[i];
	}
	cout << sum << endl;
	system("PAUSE");
	return 0;
}