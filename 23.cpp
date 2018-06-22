#include <cstdlib>
#include <map>
#include <list>
#include <numeric>
#include <iostream>

using namespace std;

bool isabundant[28124];

void printList(list<int>::iterator begin, list<int>::iterator end)
{
    for(;begin != end; begin++)
        cout << *begin << ' ';
    cout << endl;
}

list<int> getDivisors(int n)
{
    list<int> a;
    a.push_front(1);
    for(int i=n/2 ; i > 1; i--)
        if(n % i==0) a.push_front(i);
    return a;
}

int main()
{
    for(int i=1; i<=28123; i++){
        list<int> divs = getDivisors(i);

        //cout << "i: " << i<< "sum of divisors: " << accumulate(divs.begin(), divs.end(), 0) <<endl;
        //printList(divs.begin(), divs.end());
        //cout << "-----------------\n";
        isabundant[i] = accumulate(divs.begin(), divs.end(), 0) > i;
        }

    int sum = 0;

    for(int n = 1; n <= 28123; n++)
    {
        bool isab=false;
        for(int i=n-1, j =1; i > 1; i--, j++ )
            if (isabundant[i] && isabundant[j])
            {
                isab = true;
                break;
            }
        if(!isab)
        {
            sum += n;
            cout << n << " can't be written as two abundant numbers.";
        }
    }

    cout << sum << endl;
    exit(0);
}
