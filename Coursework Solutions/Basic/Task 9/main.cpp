#include <iostream>
#include <array>
#include <ctime>
#include <stdlib.h>

using namespace std;

/*
    The function shown below is a binary search algorithm, the binary search is a divide on conquer search 
    in the means of it divides the sequence in half, if the value is higher then the middle value + 1 else - 1
    repeat until the value has been found. However in this instance my searching algorithm has been adapted to
    see if their are any values between the users input, same sturcture as the regular binary search algorithm 
    however it sees if the middle value in the sequence is between the users input, if there are value/values 
    then return true otherwise it will increment or decrement the start or end depeneding on whether the value
    is higher or lower.
 
    As well as the binary search algorithm I have made this program robust by making automatic generation of a
    sequence then using bubble sort to sort it in descending order making it searchable by the binary search 
    algorithm. The algorithm complexity of binary search is O(log n) this is becuase you are dividing the
    sequence. The complexity of bubblesort is O(n^2) since there are two nested for loops.
*/

bool binarySearch(int *s, int &l, int &h)
{
    //Iterative approach
    int start = 0;  //Begining of the sequence
    int end = 9;    //End of the sequence - 1 so 9 since the size of the sequence is 10,
                    //if we compute 10 we are out of index
    if(l >= h)
    {
        cout << "Error - Low value larger than high" << endl;
        return false;
    }

    //Binary search
    while(start <= end) //O(log(n))
    {
        int mid = (start + end) / 2;    //Divide the sequence to get the middle value

        if(s[mid] > l && s[mid] < h)    //If middle is between the high and low
        {
            return true;
        }
        else if(s[mid] < l) //If middle is less than low
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
    int sequence[10];   //Array with the size of 10
    int low, high, i, j;

    srand((unsigned)time(NULL));    //Random each time never the same

    cout << "Random Generated Sequence: " << endl;

    //Fill vector with random numbers
    for(i = 1; i < 10; i++) //O(n)
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
                swap(sequence[j], sequence[j + 1]);
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
    cout << "Is there a value between your inputs in the array?: " << ((isIn == 1) ? "True" : "False") << endl; //Use tennery statment to see if the variable is holding true or false

    return 0;
}
