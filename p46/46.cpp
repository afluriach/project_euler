#include <iostream>
#include <bitset>

using namespace std;

bitset<10000000> primes;

void findPrimes()
{
	primes[0] = false;
	primes[1] = false;
	primes[2] = true;

	for(int i=2; i <= 10000000; ++i)
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


int main()
{
	findPrimes();

	for(int i=9;;i+=2)
	{
		if(primes[i])
			continue;

		bool solutionFound = false;
		//find every possible square
		for(int j=1; j*j*2 + 3 <= i; ++j)
		{
			//if the difference is a valid prime, then we're fine
			if(primes[i-2*j*j])
			{
				solutionFound = true;
				break;
			}
		}
		if(!solutionFound)
		{
			cout << i << endl;
			system("PAUSE");
		}
	}
}