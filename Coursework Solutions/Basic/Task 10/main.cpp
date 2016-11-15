#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

/*
    Function header
*/

void checkSequence(int *s, int l)
{
    vector<int> count, tmp;

    for(int i = 0; i < l; i++)  //O(n)
    {
        if(i == 0 || s[i] >= s[i - 1])
        {
            count.push_back(s[i]);
        }
        else if(s[i] < s[i - 1])
        {
            if(count.size() > tmp.size())
            {
                tmp = count;
            }
            count.clear();
            count.push_back(s[i]);
        }
    }

    if(count.size() > tmp.size())
    {
        for(int j = 0; j < count.size(); j++)
        {
            cout << count[j] << ", ";
        }
    }
    else
    {
        for(int k = 0; k < tmp.size(); k++)
        {
            cout << tmp[k] << ", ";
        }
    }
}

/*
    The main function is where the user can input the size of the sequence and then every number
    at their respected indexs, using a for loop to add them iterativly. After the values have been
    inputted the function is called where the sequence and the size is passed as a parameter.

    It has been enclosed in a try statement since it prevent the user from inputting bad characters.
*/

int main(int argc, const char * argv[])
{
    int size, i;

    cout << "Enter size of sequence: ";
    cin >> size;

    int sequence[size];         //Create array and set it with the size of the user input

    for(i = 0; i < size; i++)   //O(n)
    {
        cout << "Enter number at index " << i << ": ";  //User can input numbers
        cin >> sequence[i];
    }
    checkSequence(sequence, size);
    return 0;
}
