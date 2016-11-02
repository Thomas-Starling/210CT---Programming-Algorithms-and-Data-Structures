#include <iostream>
#include <array>
#include <ctime>
#include <stdlib.h>

using namespace std;

bool binarySearch(int *s, int &l, int &h)
{
    //Iterative approach
    int start = 0;
    int end = 9;

    if(l >= h)
    {
        cout << "Error - Low value larger than high" << endl;
        return false;
    }

    //Binary search
    while(start <= end) //O(log(n))
    {
        int mid = (start + end) / 2;

        if(s[mid] == h || s[mid] == l)
        {
            return true;
        }
        else if(s[mid] > l && s[mid] < h)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return false;
}

int main(int argc, const char * argv[])
{
    int sequence[10];
    int low, high, i, j, tmp;
    bool sorted;

    srand((unsigned)time(NULL));    //Random each time never the same

    cout << "Random Generated Sequence: " << endl;

    //Fill vector with random numbers
    for(i = 1; i < 10; i++)
    {
        sequence[i] = 1 + rand() % 100;
        cout << sequence[i] << ", ";
    }

    //Bubble sort the random list
    for(i = 1; i <= 10; i++)    //O(n^2)
    {
        for (j = 0; j < 9; j++)
        {
            if (sequence[j + 1] > sequence[j])
            {
                tmp = sequence[j];
                sequence[j] = sequence[j + 1];
                sequence[j + 1] = tmp;
            }
        }
    }

    cout << endl
         << endl;
    cout << "Sorted Generated Sequence (DESC): " << endl;

    //Print sequence
    for(int i = 1; i < 10; i++)
    {
        cout << sequence[i] << ", ";
    }

    cout << endl
         << endl;

    cout << "Input High & Low Numbers: ";
    cin >> high >> low;

    bool isIn = binarySearch(sequence, low, high);
    cout << "Is there a value between your inputs in the array?: " << ((isIn == 1) ? "True" : "False") << endl;

    return 0;
}
