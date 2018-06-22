#include <iostream>
#include <cstdlib>
#include <list>
#include <math>

using namespace std;

int rotate(n)
{
	list<int> l;
	while(n >0){
		l.push_back(n%10);
		 n /= 10;
	}
	int val = l.front();
	l.pop_front();
	l.push_back(val);
	val=0;
	while(!l.empty())
	{
		val *= 10;
		val += l.back();
		l.pop_back();
	}
	return val;
}

list<int> rotations(n)
{
	int original = n;
	list<int> l;
	for(;original != n; n = rotate(n))
	{
		l.push_back(n);
	}
	return l;
}

