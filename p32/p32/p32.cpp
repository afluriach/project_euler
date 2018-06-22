//return true if both factors and the result is
//pandigital

#include <iostream>

using namespace std;

int results[100];
int resultCount = 0;

int ndigits(int n)
{
	if (n < 10) return 1;
	if (n < 100) return 2;
	if (n < 1000) return 3;
	if (n < 10000) return 4;
	if (n < 100000) return 5;
	if (n < 1000000) return 6;
	if (n < 10000000) return 7;
	if (n < 100000000) return 8;
	if (n < 1000000000) return 9;
	else return 10;
}


bool isPandigital(int a, int b)
{
	bool digits[10]={false,false,false,false,false,false,false,false,false,false};

	int temp = a;
	for(int i=ndigits(temp); i > 0; i--)
	{
		int digit = temp % 10;
		if( digits[digit] || digit == 0) return false;
		digits[digit] = true;
		temp /= 10;
	}
	temp = b;
	for(int i=ndigits(temp); i > 0; i--)
	{
		int digit = temp % 10;
		if( digits[digit] || digit == 0) return false;
		digits[digit] = true;
		temp /= 10;
	}
	temp = a*b;
	for(int i=ndigits(temp); i > 0; i--)
	{
		int digit = temp % 10;
		if( digits[digit] || digit == 0) return false;
		digits[digit] = true;
		temp /= 10;
	}
	//make sure all digits were used
	for(int i=1; i <= 9; i++)
		if(!digits[i]) return false;
	return true;
}

void addResult(int n)
{
	for(int i=0;i<resultCount;i++)
		if(results[i] ==n) return;

	results[resultCount++] = n;
}

int main()
{
	int sum = 0;
	for(int i=1; i <100000; i++)
		for(int j=1; j < 100000; j++)
		{
			if(ndigits(i) + ndigits(j) + ndigits(i*j) > 9)
				break;
			if(isPandigital(i,j))
				addResult(i*j);
		}
	for(int i=0;i<resultCount; i++){
		cout << results[i] << endl;
		sum += results[i];
	}
	cout << endl << endl << sum << endl<<endl;
	cout << resultCount << endl;
	system("PAUSE");
}