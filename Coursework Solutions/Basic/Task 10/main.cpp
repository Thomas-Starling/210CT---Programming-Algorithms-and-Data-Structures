#include <iostream>
#include <array>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

/*
    Function header
*/

void checkSequence(int *s, int l)
{
    int  count = 0, tmp = 0;
    for(int i = 0; i < l; i++)
    {
        if(s[i] >= s[i - 1])
        {
            count++;
        }
        else
        {
            if(count > tmp)
            {
                tmp = count;
            }
            count = 0;
        }
    }
    cout << "Longest Subdequence: " << ((count > tmp) ? count : tmp) << endl;
}

int main(int argc, const char * argv[])
{
    int size, i;
    
    cout << "Enter size of sequence: ";
    cin >> size;
    
    int sequence[size];
    
    for(i = 0; i < size; i++)
    {
        cout << "Enter number at index " << i << ": ";
        cin >> sequence[i];
    }
    
    checkSequence(sequence, size);

    return 0;
}
