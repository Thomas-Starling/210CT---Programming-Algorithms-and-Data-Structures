#include <iostream>
#include <cmath>

using namespace std;

/*
    Function to work out the trailing zero's on a factorial number, using division we divide the user input by 5,
    to get a multiple of 5, but then the function is left with left over numbers so we divide it again by 25.
*/

int factorial(int &f, int trailingZeros)
{
    trailingZeros = (f/5) + (f/25);
    return trailingZeros;
}

int main()
{
    cout << "--------------Task 2--------------" << endl;
    int userInput;

    cout << "Input: " << endl;
    cin >> userInput;

    cout << "Output: " << factorial(userInput, 0) << endl;

    return 0;
}
