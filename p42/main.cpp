/* 
 * File:   main.cpp
 * Author: ant
 *
 * Created on September 14, 2012, 5:00 PM
 */

#include <cstdlib>
#include <list>
#include <iostream>
using namespace std;

//assuming a ten digit number, get the nth to n+2th (inclusive) digit from the
//left

int primes[] = {2,3,5,7,11,13,17};

int sliceDigits(int n, long full)
{
    for(int i=0, divisions = 10-(n+2); i < divisions;i++)
        full /= 10;
    full %= 1000;
    
    return full;
}

bool is10pandigital(long long n)
{
    bool digits[10];
    
    while(n != 0)
    {
        int digit = n % 10;
        if(digits[digit]) return false;
        else digits[digit] = true;
        
        n/= 10;
    }
    
    for(int i=0;i<10; ++i)
        if(!digits[i]) return false;
    
    return true;
    
}

void bruteForceCalc()
{
    for(long long i=1000000000; i < 9999999999; ++i)
    {
        if(!is10pandigital(i)) continue;
        
        bool success = true;
        
        for(int j=0;j < 7; j++)
        {
            if(sliceDigits(j+2, i) % primes[j] != 0)
                success = false;
        }
        if(success)
            cout << i << endl;
    }
}

//level d signifies that we are considering divisibility for the 3digit string
//starting at d. we have a string of d+2 digits.  
//
//base: d=2, three digit set, prev = 0-999 
void checkLevel(int d, bool (&digitFlags)[10], int prev)
{
    for(int crntDigit=0; crntDigit < 10; ++crntDigit)
    {
        if(digitFlags[crntDigit]) continue;
        
        long long newNum = prev*10 + crntDigit;
        
        if((newNum % 1000) %primes[d-2] == 0)
        {
            //divisibility has been passed
            if(d== 8) cout << newNum << endl;
            else
            {
                digitFlags[crntDigit] = true;
                checkLevel(d+1, digitFlags, newNum);
                digitFlags[crntDigit] = false;
            }
        }
    }
}

//determine if valid starting digit. must be three non-matching digits, first
//not equal to zero. init digits flag array to match the digit
//
//or return false if n is not a valid starting digit
bool threeDigit(int n, bool (&digits)[10])
{
    for(int j=0; j < 3; j++)
    {
        int digit = n % 10;
        if(digits[digit]) return false;
        else digits[digit] = true;
    }
    return true;
}

int main(int argc, char** argv)
{
    for(int i=0;i<1000; ++i)
    {
        bool digits[10];
        if(!threeDigit(i, digits)) continue;
        
        checkLevel(2, digits, i);
    }
    return 0;
}