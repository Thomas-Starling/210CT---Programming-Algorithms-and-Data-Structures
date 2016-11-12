#include <iostream>

using namespace std;

/*
    Using a recursive function to check whether a a given number is a prime one, starting by passing the value of the input and 2, I use 2 instead of 1 since anything can be divisible
    by 1, so using 2 gives a starting point with a correct answer. Using an conditional statement to check whether i is less than n for example n is 1 and i is 2 then it would instantly break.
    This is used as the base case, if n is more than i then it would begin to check whether it is a prime number or not. using modulo to see if n is divisible by i, if the remainder if 1,
    then n is a prime number.

    The expected output is that the program will return if the number is prime or not to the user, example: Input: 3 Output: Number is prime.

    O(n) complexity since we are using recursion and it's basically a loop it will grow linearly.
*/

void primeNumberCheck(unsigned n, int i)    //Use unsigned for large numbers
{
    if (i < n)
    {
        if(n % i == 1 || i == n)    //Check if remainder of modulo is 1
        {
            cout << "Your number is a prime number" << endl;
        }
        else if(i < n && n % i == 0)    //Check if the remainder of modulo is 0
        {
            cout << "Your number is not a prime number" << endl;
        }
        else
        {
            primeNumberCheck(n , i++);  //Call the function again with incrementing i
        }
    }
    else
    {
       cout << "Your number is not a prime number" << endl; //Break out of the recursion
    }
}

int main(int argc, const char * argv[]) {
    unsigned n;

    cout << "------------Task 7 ------------" << endl
         << "Enter a Number: ";
    cin >> n;

    primeNumberCheck(n, 2); //Pass to the function

    return 0;
}
