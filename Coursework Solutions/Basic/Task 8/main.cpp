#include <iostream>

using namespace std;

/*
    I have created two functions for the checking of the vowels in the string or char array, then the second
    function brings the letter together since I replace them with a space when found. You can cut down on the
    functions by comparing the index of the array != to one of the vowels then cout << s[i]; This will then
    print all the letters without having to replace it with a space. The second approach has been added in 
    comment form.
 
    My comparision takes into consideration capital letters in case the user inputs a word like Hello, this 
    algorithm will then remove e and o, becoming Hll. The user can input a sentence or word into the system
    as I have allocated 100 charecters for it, any more would cause error.
 
    The complexity of this algorithm is O(n) since I am using a recursive function the in my second function it
    also uses a for loop, since they are not nested the algorithm doesn't become n^2.
*/

void bringTogether(char *w)
{
    //Bring the sentence together
    cout << "Output: ";
    for(int i = 0; w[i] != '\0'; i++)   //O(n)
    {
        if(w[i] != ' ') //If the index of i is not equal to a space
        {
            cout << w[i];
        }
    }
    cout << endl;
}

/*
    Another appraoch to it
 
 void removeVocalAppraoch2(char *w, int p)   //O(n)
 {
    if(w[p] == '\0')
    {
        bringTogether(w);
    }
    else
    {
    if(w[p] != 'a' || w[p] != 'A' || w[p] != 'e' || w[p] != 'E' || w[p] != 'i' || w[p] != 'I' || w[p] != 'o' || w[p] != 'O' || w[p] != 'u' || w[p] != 'U')
    {
        cout << s[i];
    }
    removeVocal(w, p + 1);
    }
 }
*/

void removeVocal(char *w, int p)    //O(n)
{
    if(w[p] == '\0')    //If the index of p equals the termination character
    {
        bringTogether(w);
    }
    else
    {
        if(w[p] == 'a' || w[p] == 'A' || w[p] == 'e' || w[p] == 'E' || w[p] == 'i' || w[p] == 'I' || w[p] == 'o' || w[p] == 'O' || w[p] == 'u' || w[p] == 'U')  //Comparing the index of p with all possible vowels
        {
            w[p] = ' '; //If found then replace that char at index p with a space
        }
        removeVocal(w, p + 1);  //increment p and call the function again
    }
}

int main(int argc, const char * argv[])
{
    char word[100];

    cout << "Input: ";
    cin >> word;
    removeVocal(word, 0);

    return 0;
}
