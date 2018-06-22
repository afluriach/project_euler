#include <cstdlib>
#include <iostream>

using namespace std;

int used[10] = {0,0,0,0,0,0,0,0,0,0};
int count = 0;
int crnt[10];
void recCount(int crntDigit, int targetDigit)
{
	if(crntDigit==targetDigit)
	{
		count++;
		if(count==1000000){
			for(int i=0;i<10;i++)
				cout <<  crnt[i] << " ";
			exit(0);
		}
	}
	for (int i=0;i<=9; i++)
	{
		if(used[i]) continue;
		used[i] = 1;
		crnt[crntDigit] = i;
		recCount(crntDigit+1, targetDigit);
		used[i] = 0;
	}
}

int main()
{
	recCount(0, 9);
	exit(0);
}
