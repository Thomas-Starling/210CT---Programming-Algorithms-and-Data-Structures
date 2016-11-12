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

    The pre conditions are that the user enters a number under the size of an int since I haven't accounted for large perfect square numbers using the manual
    method instead of SQRT. The function to work it all out contains two loops, one which checks to see if the user entered a prime number and the other that
    checks if the number if not a perfect square then check the closest prime to it as described above. The expected output is either going to be a message that the users
    input is a prime number or the users input isn't a perfect square and the closest one to it 10 = 9, 5 = 4.

    Complexity of O(n) because the loops are not nested it can't be n*n so instead it is n+n. The two for loops each represent N since they are loping through a certain amount
    of numbers, the complexity will grow at a linear rate for both loops.
*/

void perfect_square(int &n) //Use unsigned for larger numbers
{
    bool answer = false;    //No prime found?
    //Check for perfect square number
    for(int i = 0; i <= n; i++) //O(n)
    {
        if(round(i * i) == n)   //round i * i for accurate value
        {
            cout << "\nYour number is a perfect square" << endl
                 << "Number entered: " << n << endl;
            answer = true;  //The answer has been found
            break;  //Answer found break the loop
        }
    }

    if(answer == false) //Prime not found using the loop above
    {
        //Check for nearest perfect square
        for(int j = n; j > 0; j--)  //O(n)
        {
            if(round(j * j) <= n + 3)    //Use +3 to get better accurate nearest square
            {
                cout << "\nYour number is NOT a perfect square: " << endl
                     << "Number entered: " << n << endl
                     << "Perfect square estimation: " << j * j << endl; //Print the nearest prime to it
                break;  //Answer found break the loop
            }
        }
    }
}

/*
    The main function is where the user enters their input number and that checks whether it is positive or negative before it gets passed to the function,
    if the condition is false then the number is passed to the function for computation.
*/

int main(int argc, const char * argv[])
{
    cout << "--------------Task 3--------------" << endl;
    int num;   //Use unsigned for larger number

    cout << "Enter your number: ";
    cin >> num;

    if(num < 0)
    {
        cout << "Number isn't positive" << endl;
    }
    perfect_square(num);

    return 0;
}
