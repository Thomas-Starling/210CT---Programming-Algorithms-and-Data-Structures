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
*/

void FisherYatesShuffle(vector <int> &shuffle)  //Returning no value so void
{
    int i, j, tmp;
    srand(time(0)); //Seeds the number of rand()

    cout << "After: " << endl;
    for( i = shuffle.size(); i > 0; i--)    //Decrement from the size of the vector
    {
        j = rand() % i + 1; //+1 otherwise the index will be out of range or repeat numbers
        swap(shuffle[i], shuffle[j]); //C++11 short-cut of shuffling
        //tmp = shuffle[j];
        //shuffle[j] = shuffle[i];
        //shuffle[i] = tmp;
        cout << shuffle[i] << ", ";
    }
}

int main()
{
    cout << "--------------Task 1--------------" << endl;

    vector <int> shuffleVec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Before: " << endl;

    for(int i = 0; i < shuffleVec.size(); i++)  //Print out the elements in the vector
    {
        cout << shuffleVec[i]  << ", ";
    }
    cout << endl;
    FisherYatesShuffle(shuffleVec); //Pass arguments to function and call it
    return 0;
}
