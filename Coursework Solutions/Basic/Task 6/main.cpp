#include <iostream>
#include <string>

using namespace std;

/*
    Function header
*/

void reverseString(char *s)
{
    int i, j, len = 0, words = 0, k = 0;

    //Work out length of string
    for (i = 0; s[i] != '\0'; i++)
    {
        len++;
    }

    char reverse[len];

    //Reverse words
    for (j = len - 1; j >= 0; j--)
    {
        reverse[k] = s[j];
        k++;
    }

    char str[len];

    //Reverse sentence
    for (int l = 0, last_l = 0;; l++)
    {
        if (reverse[l] == ' ' || reverse[l] == '\0')
        {
            for (int m = l - 1; m >= last_l; m--)
            {
                str[words] = reverse[m];
                words++;
            }
            last_l = l + 1;

            str[words] = reverse[l];
            words++;
        }
        if (reverse[l] == '\0')
        {
            break;
        }
    }
    cout << "Reversed Sentance: " << str << endl;
    cout << endl;
}


int main(int argc, const char * argv[]) {

    char sentence[] = ("This is awesome");
    cout << "Original Sentence: " << sentence << endl;

    reverseString(sentence);

    return 0;
}
