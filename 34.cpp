#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

int facts[10];

#define HARD_CEILING 1e9


int factorial(int n)
{
	if (n==0 || n==1 ) return 1;
	int f = 1;
	for(int i=n;i>=1; i--) f *= i;
	return f;
}

list<int> getDigits(int n)
{
	list<int> l;
	if(n==0)
	{
		l.push_back(0);
		return l;
	}

	while(n>0)
	{
		l.push_back(n%10);
		n /= 10;
	}
	return l;
}

long sumFact(list<int> l)
{
	long sum = 0;
	while(!l.empty()){
		sum += facts[l.front()];
		l.pop_front();
	}
	return sum;
}

int main()
{
	for(int i=0; i<=9;i++) facts[i] = factorial(i);
	long sum = 0;
	for(int i=0;i<= HARD_CEILING; i++)
	{
		int s = sumFact(getDigits(i));
		if (s==i) sum += i;

		if(i%10000==0) cout << "n: " << i << endl;
	}

	cout << "sum: "<< sum << endl;
	exit(0);
}
