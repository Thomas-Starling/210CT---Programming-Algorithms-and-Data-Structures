#include <iostream>
#include <string>

using namespace std;

/*
 Function header
 */

void reverseString(char *r, int len)
{
    int words = 0;
    
    char str[len];
    
    //Reverse sentence
    for (int l = 0, lastl = 0;; l++)   //O(n^2)
    {
        if (r[l] == ' ' || r[l] == '\0')
        {
            for (int m = l - 1; m >= lastl; m--)
            {
                str[words] = r[m];
                words++;
            }
            lastl = l + 1;
            
            str[words] = r[l];
            words++;
        }
        if (r[l] == '\0')
        {
            break;
        }
    }
    cout << "Output: " << str << endl;
    cout << endl;
}


int main(int argc, const char * argv[]) {
    
    char sentence[] = ("This is awesome");
    int len = 0;
    
    cout << "Input: " << sentence << endl;
    
    //Work out length of string
    for (int i = 0; sentence[i] != '\0'; i++)   //O(n)
    {
        len++;
    }
    
    char reverse[len];
    
    //Reverse words
    for (int j = len - 1, k = 0; j >= 0; j--)   //O(n)
    {
        reverse[k] = sentence[j];
        k++;
    }
    
    reverseString(reverse, len);
    
    return 0;
}

