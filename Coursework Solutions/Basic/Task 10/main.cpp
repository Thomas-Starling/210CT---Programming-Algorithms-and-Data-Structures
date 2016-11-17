#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

/*
    The function checkSequence returns the longest subsequence of numbers in order in acsending order,
    for instance a sequence of 1, 2, 3, 4, 1. The longest subsequence is 1, 2, 3, 4, rather than return
    a count of it, this function returns the actual numbers from the sequence. Using a for loop to
    loop through the sequence then running a comarision on the index of i. The comparision comapres i to
    its previous element seeing it i is larger than i - 1, if it is then it increments the counter and 
    continues to loop, until i is not larger than i - 1 then another conditional statment executes to
    see if i is less than i - 1. So if the element of i is 4 and the next is i, the conditional will 
    execute code with another conditional seeing if the count size is larger than the size of tmp, if
    it is then copy all elements from count into tmp. If the condition is not met then it will clear all
    elements in the vector and push i into i ready to repeat the whole thing again. Example:
 
    Sequence = 1, 2, 1
    1st Iteration:
    s[i] = 1
    i = 0 so push into vector
    vector1 now has the value at index 0 of 1
 
    2nd Iteration:
    i = 1
    s[i] = 2, s[i - 1] = 1, 2 is more than 1 so push back into vector
    vector1 now have the values 1, 2
    
    3rd Iteration:
    i = 2
    s[i] = 1, s[i - 1] = 2, 1 is less 1 so now.....
    if vector1 is more than vector2 which is it then copy all elements from 1 into 2
    vector1 now has only 1 element of the value 1
    vector 2 now has the values 1, 2
 
    no more elements of i so now print the largest one
 
    The pre-condition is that you have an array of random elements, not necessarily in order or even any
    elements in order, you will not get an output otherwise since no elements are found. The expected 
    output is that the program will return the longest sorted sequence of numbers.
*/

void checkSequence(int *s, int l)
{
    vector<int> count, tmp;

    for(int i = 0; i < l; i++)  //O(n)
    {
        if(i == 0 || s[i] >= s[i - 1])  //Check if previous element is smaller than i
        {
            count.push_back(s[i]);
        }
        else if(s[i] < s[i - 1])    //Check if i is less than previous element
        {
            if(count.size() > tmp.size())   //Check between which vector is larger
            {
                tmp = count;
            }
            count.clear();  //Clear all elements in the vector
            count.push_back(s[i]);  //Store the current value of i in the vector ready
        }
    }

    if(count.size() > tmp.size())
    {
        for(int j = 0; j < count.size(); j++)   //O(n) Print vector
        {
            cout << count[j] << ", ";
        }
    }
    else
    {
        for(int k = 0; k < tmp.size(); k++) //O(n) Print vector
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
