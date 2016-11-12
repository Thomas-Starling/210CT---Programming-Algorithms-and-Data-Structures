ask 9#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

/*
    The function checkSequence searches a sequence to check for the longest subsequence
    or the longest sorted sequence. It does this by using a loop to iterate over the
    sequence and a comparison statement to check if the value of index i is more than
    or equal to i - 1, if it is then you increment the count by 1. If no then if the
    variable count is more than tmp you store count in tmp and count will then be set to
    zero since the subsequence is no longer valid due to a number not been more than i.

    The expected output is the longest subsequence, a tennery statement is used ot compare to see if the
    count or tmp is higher then returns the number it is holding. The parameters are the sequence
    called by pointer so the data can be modified and the size of the sequence used for the loops.

    We are then taking both variables count and tmp and comparing to see which one is
    holding the longest subsequence count. The algorithm complexity of this is O(n)
    since we are iterating through the sequence.
*/

void checkSequence(int *s, int l)
{
    int  count = 0, tmp = 0;
    for(int i = 0; i < l; i++)  //O(n)
    {
        if(s[i] >= s[i - 1])    //if i is more than i - 1
        {
            count++;            //Increment count
        }
        else
        {
            if(count > tmp)     //If count is more than tmp
            {
                tmp = count;    //Store the value of count in tmp
            }
            count = 0;          //Reset the count
        }
    }
    cout << "Longest Subsequence: " << ((count > tmp) ? count : tmp) << endl;   //Which is higher?
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

    try
    {
        for(i = 0; i < size; i++)   //O(n)
        {
            cout << "Enter number at index " << i << ": ";  //User can input numbers
            cin >> sequence[i];
        }

        checkSequence(sequence, size);
    }
    catch()
    {
        //Something happened
    }

    return 0;
}
