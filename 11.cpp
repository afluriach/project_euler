#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>

#define max(a,b) ((a>b) ? (a) : (b))

int tri[15][15];

using namespace std;

int main()
{
	ifstream fin;
	fin.open("18.in", ifstream::in);
	
	for(int i=0;i<15; i++)
	{
		for(int j=0;j<=i;j++)
			fin >> tri[i][j];
	}
	//Start at the second highest row and make each cell the sum of itself and the larger of its children
	for(int i=13; i >= 0; i--)
	{
		for(int j=0;j<=i;j++)
		{
			tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
		}
	}
	cout << tri[0][0] <<endl;
	exit(0);
}