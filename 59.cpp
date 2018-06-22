#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print (unsigned char elem)
{
    cout << elem << ' ';
}

int main() {

    vector<unsigned char> ciphertext;
    ifstream fin;
    

    fin.open("cipher1.txt", "r");
    
    while(!feof(fin))
    {
        char dummy;
        int i;
        unsigned char c;
        fscanf(fin, ",%d", &i);
        c = i;`
        ciphertext.push_back(c);
    }
    
    for_each( ciphertext.begin(), ciphertext.end(), print);
    cout << endl;
    
    

    return 0;
}
