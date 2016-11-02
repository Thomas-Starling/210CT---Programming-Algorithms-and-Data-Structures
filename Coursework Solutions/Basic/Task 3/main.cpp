#include <iostream>
#include <cmath>

using namespace std;

/*
    Using two for loops to manually work out the perfect square number by seeing if any number under the value of N multiplied by itself
    is equal to N. Using the round() function to get a more accurate result, if the i * i is a match to N then we have found our perfect square.
    After we have found our perfect another loop begins trying to find the nearest perfect square by decrementing j which has the value of N,
    checking each value of j * j against n + 3. We are adding 3 to n so we can get the nearest perfect square otherwise it would just return the square below it.
    For example:
    Input: 8
    Output with + 3 = 9 (Closest Perfect Square number)
    Output without + 3 = 4

    8 is closer to 9 which is a perfect square but not 4.
*/

int perfect_square(unsigned &n) //Use unsigned for larger numbers
{
    //Check for perfect square number
    for(int i = 0; i <= n; i++)
    {
        if(round(i * i) == n)       //round i * i for accurate value
        {
            return 1;               //return 1 to the main function for comparison
            break;                  //Answer found break the loop
        }
    }

    //Check for nearest perfect square
    for(int j = n; j > 0; j--)
    {
        if(round(j * j) < n + 3)    //Use +3 to get better accurate nearest square
        {
            return round(j * j);    //Return value to main for output
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    cout << "--------------Task 3--------------" << endl;
    unsigned num;   //Use unsigned for larger number

    cout << "Enter your number: ";
    cin >> num;

    if(num < 0)
    {
        cout << "Number isn't positive" << endl;
    }

    int result = perfect_square(num);

    if(result == 1) //Compares the value from the functions return
    {
        cout << "\nYour number is a perfect square" << endl
             << "Number entered: " << num << endl;
    }
    else
    {
        cout << "\nYour number is NOT a perfect square: " << endl
             << "Number entered: " << num << endl
             << "Perfect square estimation: " << result << endl;
    }

    return 0;
}
