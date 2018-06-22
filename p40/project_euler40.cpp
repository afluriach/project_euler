// project_euler40.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

char buf[2000000];

int _tmain(int argc, _TCHAR* argv[])
{
	char * pos = buf;
	for(int i=1; (pos - buf) <= 1000000; ++i)
	{
		pos += sprintf(pos, "%d", i);
	}

	long result = (buf[0] - '0') *
		          (buf[9] - '0') *
				  (buf[99]- '0') *
				  (buf[999]- '0') *
				  (buf[9999]- '0') *
				  (buf[99999]- '0') *
				  (buf[999999]- '0');

	cout << result << endl;
	system("PAUSE");


	return 0;
}