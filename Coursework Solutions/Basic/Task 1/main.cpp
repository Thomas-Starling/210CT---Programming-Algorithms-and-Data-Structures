#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

/*
    Using Fisher Yates shuffle, select random number from vector using the size +1 then shuffle
    the elements each iteration of the loop changes the values around. Using Vector instead of array since you can resize it.
    I have added the swap method already implemented in C++ but also the 'manual' method of shuffling it where
    the position of j becomes i and i becomes the value of temp which holds the position of j on the next iteration.
    j holds a random number from the position of i + 1, where i is the size of the vector.

    Using srand and rand to generate a random sequence each time the code is run, this allows for a ever changing
    sequence of random numbers. On the loop I am assigning i s the size of the sequence -1 since the index start from 0, if
    it was left then it would go out of index and include 0 in the generation. When the program is run what's happening is
    in the first iteration for instance then i is 9 - 1 = 8, j = random between 8 + 1 then the position of i(8) is swapped with position
    of the random number between 1 and 9.

    The pre conditions are that the sequence is ideally sorted before it is passed to the function, this means that your sorted
    sequence will then become unsorted. If you pass a unsorted sequence you are not gaining anything to just shuffle it around.
    The expected output is that the sorted sequence becomes unsorted and in random order.
	
	The algorithm complexity is O(n) since we are using a loop to select the elements are their respecitve
	index's and swap them, so because of the loop, it becomes Linear.
*/

void FisherYatesShuffle(vector <int> &shuffle)  //Returning no value so void
{
    int i, j, tmp;
    srand((unsigned)time(NULL)); //Seeds the number of rand()

    cout << "After: " << endl;
    for( i = shuffle.size() - 1; i >= 0; i--)    //Decrement from the size of the vector, O(n)
    {
        j = rand() % (i + 1); //+1 otherwise the index will be out of range or repeat numbers
        swap(shuffle[i], shuffle[j]); //C++11 short-cut of shuffling
        //tmp = shuffle[j];
        //shuffle[j] = shuffle[i];
        //shuffle[i] = tmp;

        cout << shuffle[i] << ", ";
    }
}

/*
    The main function holds the sorted sequence, prints it out for the user to see and then passes it to the functions
    as a parameter. The sequence can be changed but only in the code, the user can not input numbers of their choice through
    the system input.
*/

int main()
{
    cout << "--------------Task 1--------------" << endl;

    vector <int> shuffleVec = {1, 2, 3, 4, 5, 6, 7, 8, 9};  //Sorted sequence

    cout << "Before: " << endl;

    for(int i = 0; i < shuffleVec.size(); i++)  //Print out the elements in the vector
    {
        cout << shuffleVec[i]  << ", ";
    }
    cout << endl;
    FisherYatesShuffle(shuffleVec); //Pass arguments to function and call it
    return 0;
}
