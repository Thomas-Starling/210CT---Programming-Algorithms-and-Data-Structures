#include <iostream>
#include <cmath>

using namespace std;

/*
    Function to work out the trailing zero's on a factorial number, using division we divide the user input by 5,
    to get a multiple of 5, but then the function is left with left over numbers so we divide it again by 25. You
    could also + (f/125) for bigger numbers.

    The pre conditions are that the user enters a number, it can be both whole and decimal since the code will do the
    same operation without error. The expected output is that the user is returned a number to the console with the
    amount of trailing zeros. For instance input 10 output 2. This method works because we count the number of prime
    factors of 2 and 5

    The algorithm complexity is a simple O(1) since we are not using loops and a quick operation like this is constant time
    every time.
*/

int factorial(int &f)    //O(1)
{
    int trailingZeros;
    trailingZeros = (f / 5) + (f / 25);         //Divide the parameter by 5 and 25
    return trailingZeros;
}

/*
    The main function is where the user can input their number as a factorial such as 5 or 10 and then that input is passed
    to the function that calculates the trailing zeros of that number.
*/

int main()
{
    cout << "--------------Task 2--------------" << endl;
    int userInput;

    cout << "Input: " << endl;
    cin >> userInput;

    cout << "Output: " << factorial(userInput) << endl;  //Output the result to console

    return 0;
}
