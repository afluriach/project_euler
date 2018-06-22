#include <iostream>
#include <cstdlib>

using namespace std;

bool isright(int a,int b,int c)
{
	return a*a + b*b == c*c;
}



int main()
{
	int max_per=0;
	int max_sols = 0;

	for(int p=1; p<=1000; p++)
	{
		int crnt_sols=0;
		for(int a=1; a < p; a++)
		{
			for(int b=1; a+b < p ; b++)
			{
				int c = p-a-b;
				if(isright(a,b,c)) crnt_sols++;
			}
		}
		if (crnt_sols > max_sols){
			max_sols = crnt_sols;
			max_per = p;
		}
	}

	cout << "Maximum value" << max_sols << "at perimeter of " << max_per << endl;
	exit(0);

}
