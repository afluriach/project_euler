#include <iostream>
#include <map>

using namespace std;

map<int,int > nmemo;


int nways(int n)
{
    if (nmemo.count(n) > 0)
        return nmemo[n];
    int sum=0
    for(int i=2, j=n-2; i > 1; i--, j++)
    {
        sum +=
    }
}

int main()
{

}
