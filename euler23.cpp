#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

bool abundant[28124];

int sumDivisors(int n)
{
	std::list<int> divisors;
	for(int i=1; i <= n; i++)
		if(n%i==0)
			divisors.insert.push_back(i);
	return std::accumulate(divisors.begin(), divisors.end(), 0);
}

int main()
{
	for(int i=1; i<28124; i++)
	{
		abundant[i] = sumDivisors(i) > i;
	}

	int sum=0;

	for(int n=1; n <= 28123; n++)
	{
		bool isabund = false;
		for(int i=1, j=n-1; i < n; i++, j--)
		{
			if(abundant[i] && abundant[j]){
				isabund = true;
				break;}
		}
		if(!isabund) sum += n; 
	}
	cout << n;	
	exit(0);
}
