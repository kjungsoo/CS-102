/*
Jung Kim
CS 102
Ch. 9 prob #2
*/

#include <iostream>
#include <cstring>

using namespace std;

class Uniqueness
{
public:
    void setSentence(),
         findUniq(),
         sortUniq(),
         findNumuniq();

private:
    char sentence[90], uniq_letter[26];
    int sent_len, wordcount, position, num_uniq[26];
};

void Uniqueness::setSentence()
{
    cout << "Enter a word or sentence: " << endl;
    cin.getline(sentence, 90);
    sent_len = strlen(sentence);
}

void Uniqueness::findUniq()
{
    position = 0;
    wordcount = 0;

    for (int letter = 0; letter < sent_len; letter++)
    {
        sentence[letter] = tolower(sentence[letter]);
        if (isalpha(sentence[letter]))
        {
            uniq_letter[position] = sentence[letter];
            position++;

            if(not isalpha(sentence[letter + 1]))
                wordcount++;
        }

        for (int letter2 = letter + 1; letter2 < sent_len; letter2++)
        {
            if (isalpha(sentence[letter2]))
                sentence[letter2] = tolower(sentence[letter2]);
            if (uniq_letter[position - 1] == sentence[letter2])
                position--;
        }
    }
    cout << "Number of words: " << wordcount << endl;
}

void Uniqueness::sortUniq()
{
    for (int i = 0; i < position - 1; i++)
        for (int j = i + 1; j < position; j++)
            if (uniq_letter[i] > uniq_letter[j])
                swap(uniq_letter[i], uniq_letter[j]);

    cout << "Letters:     ";
    for (int i = 0; i < position; i++)
        cout << uniq_letter[i] << " ";
    cout << "\n";
}

void Uniqueness::findNumuniq()
{
    cout << "Occurrences: ";
    for (int i = 0; i < position; i++)
    {
        num_uniq[i] = 0;
        for (int letter = 0; letter < sent_len; letter++)
            if (uniq_letter[i] == sentence[letter])
                num_uniq[i]++;
        cout << num_uniq[i] << " ";
    }
}

int main()
{
    Uniqueness test;
    test.setSentence();
    test.findUniq();
    test.sortUniq();
    test.findNumuniq();
    return 0;
}
