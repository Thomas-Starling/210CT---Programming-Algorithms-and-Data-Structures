#include <iostream>

using namespace std;

/*
    Function header
*/

void bringTogether(char *w)
{
    //Bring the sentence together
    cout << "Output: ";
    for(int i = 0; w[i] != '\0'; i++)
    {
        if(w[i] != ' ')
        {
            cout << w[i];
        }
    }
    cout << endl;
}

void removeVocal(char *w, int p)
{
    if(w[p] == '\0')
    {
        bringTogether(w);
    }
    else
    {
        if(w[p] == 'a' || w[p] == 'A' || w[p] == 'e' || w[p] == 'E' || w[p] == 'i' || w[p] == 'I' || w[p] == 'o' || w[p] == 'O' || w[p] == 'u' || w[p] == 'U')
        {
            w[p] = ' ';
        }
        removeVocal(w, p + 1);
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
