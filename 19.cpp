#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <assert.h>

bool isleap(int n)
{
	if(n%400 == 0) return true;
	else if (n%100 == 0 ) return false;
	else return (n%4 == 0);
		
}
using namespace std;

int months [] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int monthLength(int month, int year)
{
	if(month==2)
		return (isleap(year)) ? 29 : 28;
	else return months[month];
}

int countWeekday(int start, int day, int ndays)
{
	assert(start >= 0); assert(start <=6);
	assert(day >= 0); assert(day <= 6);
	
	int sum=0;
	
	for(int date=1, dotw=start; date <= ndays; date++, dotw = (dotw+1)%7)
		if(dotw==day) sum++;
	return sum;
}

int main()
{
	//1 = monday, 0 = sunday
	int dotw = 2;
	int sum=0;
	for(int year=1901; year<=2000; year++)
	{
		for(int month=1; month<=12; month++)
		{
			cout << "Month " << month << "started on day of the week: " << dotw << endl;
			if(dotw==0) sum++;
			//sum += countWeekday(dotw, 0, monthLength(month, year));
			dotw = (dotw + monthLength(month, year)) % 7;
		}
	}
	cout << sum << endl;
}
