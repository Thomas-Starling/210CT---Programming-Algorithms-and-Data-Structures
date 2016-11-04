#include <iostream>
#include <array>
#include <ctime>
#include <stdlib.h>

using namespace std;

void returnSequence()
{
    
}

void checkSequence(int *s, int l)
{
    cout << endl;
    for(int i = 0; i < l; i++)
    {
        if(s[i] >= s[i + 1] && s[i] <= s[i + 2])    //Need to finish
        {
            cout << s[i] << ", ";
        }
    }
}

int main(int argc, const char * argv[])
{
    int size, i;
    char choice;
    int sequence[size];
    
    try
    {
        cout << "Do you want manual or automatic sequence generation? (M or A): " << endl;
        cin >> choice;
        if(choice == 'M' || choice == 'm')
        {
            cout << "Enter size of sequence: ";
            cin >> size;
            
            for(i = 0; i < size; i++)
            {
                cout << "Enter number at index " << i << ": ";
                cin >> sequence[i];
            }
            
            checkSequence(sequence, size);
        }
        else if(choice == 'A' || choice == 'a')
        {
            cout << "Enter size of sequence: ";
            cin >> size;
            
            srand((unsigned)time(NULL));
            
            //Fill array with random numbers
            for(i = 1; i < size; i++)   //O(n)
            {
                sequence[i] = 1 + rand() % 100;
                cout << sequence[i] << ", ";
            }
            checkSequence(sequence, size);
        }
    }
    catch(exception e)
    {
        cout << &e << endl;
    }
    return 0;
}
