
#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <bitset>
#include <math.h>
using namespace std;

#define MAX 10000000l

#define max(a,b) ((a>b) ? (a) : (b))

bitset <MAX> isprime;

bool is_prime(int n)
{
	if (n < 0) return false;
	if (n >= MAX)
	{
		cout << "Error: " << n << " beyond the range." << endl;
		exit(1);
	}
	return isprime[n];
}



int consec = 0, maxprod = 0;


int main()
{
	isprime[2] = 1;
	isprime[3] = 1;

	for(int i=4; i<MAX; i++)
{
	for(int j=2; j<= sqrt(i); j++)
	{
		if(isprime[j] && i % j == 0){
			isprime[i] = 0;
			break;
		}
		isprime[i] = 1;

	}
}

cout << "primes calculated" << endl;


	for(int a = -999; a <= 999; a++)
	{
		for(int b= -999; b<= 999; b++)
		{
			int n;
			for(n=0; is_prime(n*n + a*n + b); n++)
			cout << "a=" << a << " b=" << b << "n="<<n << endl; 
			if (n > consec) { consec = n; maxprod  = a*b;}
		}
	}
	printf("%d\n", maxprod);
	exit(0);
}
