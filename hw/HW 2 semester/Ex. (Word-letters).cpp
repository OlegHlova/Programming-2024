#include <iostream>
#include <string>

using namespace std;

int main()
{
    // prompt user for string
    string input;
    cout << "Enter a string: " << endl;
    cout << "-> ";
    getline(cin, input);

    // initialize variables
    int currentLetter = 0;
    string* words = new string[input.size ()];
    int wordsIndex = 0;

    if (input[input.size() - 1] != '.')
    {
        input += ".";
    }

    for (int i = 0; i < input.size(); i++)
    {
       
        if (input[i] != ' ' && input[i] != '.')
        {
            currentLetter++;
            continue;
        }

      
        string previousWord;
        while (currentLetter != 0)
        {
            previousWord += input[i - currentLetter];
            currentLetter--;
        }

        // check if the number of letters 
        if (previousWord.size() != 0 && previousWord.size() % 2 != 0)
        {
            words[wordsIndex] = previousWord;
            wordsIndex++;
        }
    }

    cout << "\n------\n\n";

    // print the result
    cout << "Words with uneven number of letters: " << endl;
    for (int i = 0; i < wordsIndex; i++)
    {
        cout << "-" << words[i] << endl;
    }

    return 0;
