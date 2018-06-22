#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;

#define TARGET 1000000000
#define START 40756
set<int> tri, pent, hexa;

int main()
{
	for(int n=1; ; n++)
	{
		int v = n*(n+1)/2;
		if (v > TARGET) break;
		else tri.insert(v);
	}

	for(int n=1; ; n++)
	{
		int v = n*(3*n-1)/2;
		if (v > TARGET) break;
		else pent.insert(v);
	}

	for(int n=1; ; n++)
	{
		int v = n*(2*n-1);
		if (v > TARGET) break;
		else hexa.insert(v);
	}

	for(int i=START;i<= TARGET; i++)
	{
		if(i%10000 == 0) cout << i << endl;
		if(hexa.find(i) != hexa.end() && pent.find(i) != pent.end() && tri.find(i) != tri.end()){
			cout << "result: " << i << endl;
			exit(0);
		}
	}
	return 0;

}
