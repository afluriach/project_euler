#include<bitset>
#include<iostream>
using namespace std;

//find all primes <= sqrt(10,000,000,000) i.e. <= 100,000
//then iterate backwards from 987,654,321 until a prime pandigital is found

bitset<100001> primes;

void findPrimes()
{
	primes[0] = false;
	primes[1] = false;
	primes[2] = true;

	for(int i=2; i <= 100000; ++i)
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

bool isPandigital(long n)
{
	bool digits[9];
	memset(digits, 0, sizeof(bool)*9);
	if(n % 10 == 0) return false;
	while(n != 0)
	{
		int digit = (n % 10)-1;
		if(digit < 0 || digits[digit]) return false;
		else digits[digit] = true;
		n /= 10;
	}
	for(int i=0;i<9; ++i)
		if (!digits[i]) return false;
	return true;
}

bool isPrime(long n)
{
	for(int i=2; i*i <= n; ++i)
	{
		if(!primes[i]) continue;

		if(n % i == 0) return false;
	}
	return true;
}

int main()
{
	findPrimes();

	
	cout << isPandigital(987654321) << endl;
	cout << isPandigital(123456789) << endl;


	for(long i = 987654321; i > 0; --i)
	{
		if(isPandigital(i) && isPrime(i))
		{
			cout << i << endl;
			system("PAUSE");
			break;
		}
	}
	return 0;
}