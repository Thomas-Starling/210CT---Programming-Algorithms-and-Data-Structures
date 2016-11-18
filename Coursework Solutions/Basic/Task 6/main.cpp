#include <iostream>
#include <string>

using namespace std;

/*
    The function below reverses a sentence so that the last word is at the front etc. it works by first reversing the string for instance hello becomes olleh, then
    finding the spaces in the reversed sentence and moves the end of the letter so in the hello example h to the front of the sentence and moving the front letter
    to the back where h was. If it was the second iteration then l will be moved with e until you have hello again. It creates a new char array and stores the values in
    that. The second for loop is the one which does the swapping, it starts by assigning j with the value of i - 1 so for the hello example j would be 5 since hello
    contains 5 letters, 6 with the string termination, puts h into the position of 0 in the new char array and repeats backwards, so h, e, l , l, 0. Until the string
    termination has been detected it breaks out of the loop and prints the answer.

    Each iteration of the second loop if it contains a space, the words counter gets incremented, lastl gets the value of i + 1 which holds the index of the last word it reversed
    back and the spaces are added from i to words in the new array. A visual representation below of how it works:

    Sentence = Hello World
    Reversed = dlroW olleH

    First iteration i = 0, lastl = 0...no space until i = 6, lastl = 0
    d   l   r   o   W   olleH
    ^   ^   ^   ^   ^ ^
    |   |   |   |   | |
    1   2   3   4   5 6
                      Found Space
    Comparison starts working...space found
    j = 5, j is more than 0
    str[0] = s[4] = W, repeat again so str[1] = o, str[2] = r.....
    Then after j = 0, j now become i + 1 = 7, strp[6] = a space, words = 7, then do the next word until string termination.

    The pre conditions are that the sentence is reversed by the loop in the main otherwise the algorithm wont be able to work
    and reverse the string again. The expected output is that the string will be reversed and readable, reversed Hello World =
    dlroW olleH, expected output = World Hello.

    The complexity of this algorithm is O(n^2), it grows exponentially.
 */

void reverseString(char *s, int len)
{
    int words = 0, last = 0;
    char str[len];

    //Reverse sentence
    for (int i = 0; i <= len; i++)   //O(n^2)
    {
        if (s[i] == ' ' || s[i] == '\0')    //If the index of i is a space, check \0 for the last word
        {
            for (int j = i - 1; j >= last; j--)    //Found space now decrement j until it meets with the last known word
            {
                str[words] = s[j];
                words++;
            }
            last = i + 1;  //Holds the value of the last known word
            str[words] = s[i];
            words++;
        }
        if (s[i] == '\0')
        {
            break;
        }
    }
    cout << "Output: " << str << endl;
}

/*
    The main function prints the word out, then reversed the word ready for the function above to pick out the letters and reassemble
    it all back together reversed. You need to reverse the word otherwise the function will not be able to pick out where the letters are
    if you passed the sentence without been reversed into the function then the function would just reverse the sentence.

    After the sentence has been reversed then it is passed to the function for computation.
*/

int main(int argc, const char * argv[]) {

    char sentence[] = ("This is awesome");
    int len = 0;

    cout << "Input: " << sentence << endl;

    //Work out length of string
    for (int i = 0; sentence[i] != '\0'; i++)   //O(n), find out the length of string until string termination
    {
        len++;
    }

    char reverse[len];  //new array for reversed sentence

    //Reverse words
    for (int j = len - 1, k = 0; j >= 0; j--)   //O(n)
    {
        reverse[k] = sentence[j];
        k++;
    }

    reverseString(reverse, len);

    return 0;
}

