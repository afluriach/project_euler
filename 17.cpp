#include <iostream>
#include <assert.h>
#include <cstring>
#include <cstdlib>

using namespace std;

string ones_teens[] = {"zero", "one", "two", "three", "four", "five", "six",
                    "seven", "eight", "nine", "ten", "eleven", "twelve",
                    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                    "eighteen", "nineteen", "twenty"};

string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int countLetters(string s)
{
	int sum=0;
	for(int i=0;i<s.length(); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z') sum++;
	}
	return sum;
}

string count(int n)
{
    assert(n>=0);
    assert (n<= 1000);
    if(n==0) return "";
    if(n < 20)
        return ones_teens[n];
    else if(n < 100)
        return count(n%10) + " "+ tens[n/10];
    else if(n < 1000)
    {
        return count(n/100)+ string("hundred") +
        (( n%100 == 0 ) ? string("") : string(" and ") + count(n%100));
    }
    else return string("one thousand");
}

int main()
{
    int sum = 0;
    for(int i=1; i<=1000; i++){
        sum += countLetters(count(i));
    }
    cout << sum << endl;
    exit(0);
}
