/*
Jung Kim
CS 102
Ch.9 prob#9
*/

#include <iostream>
#include <cstring>

using namespace std;

class CompareCstring
{
public:
    void setCstrings(),
         parseStrings(),
         compareStrings();
private:
    char cstring1[90], cstring2[90],
         compare_str1[90], compare_str2[90];
    int cstr1_len, cstr2_len,
        position, position2;
};

void CompareCstring::setCstrings()
{
    cout << "Enter a word or sentence: " << endl;
    cin.getline(cstring1, 90);
    cstr1_len = strlen(cstring1);

    cout << "Enter another word or sentence: " << endl;
    cin.getline(cstring2, 90);
    cstr2_len = strlen(cstring2);
}

void CompareCstring::parseStrings()
{
    position = 0;
    for (int letter = 0; letter < cstr1_len; letter++)
    {
        cstring1[letter] = tolower(cstring1[letter]);
        if (isalpha(cstring1[letter]))
        {
            compare_str1[position] = cstring1[letter];
            position++;
        }
    }
    compare_str1[position] = '\0';

    position2 = 0;
    for (int letter = 0; letter < cstr2_len; letter++)
    {
        cstring2[letter] = tolower(cstring2[letter]);
        if (isalpha(cstring2[letter]))
        {
            compare_str2[position2] = cstring2[letter];
            position2++;
        }
    }
    compare_str2[position2] = '\0';
}

void CompareCstring::compareStrings()
{
    if (strcmp(compare_str1, compare_str2))
        cout << "The C-strings are Not the same." << endl;
    else
        cout << "The C-strings are the same.";
}

int main()
{
    CompareCstring test;
    test.setCstrings();
    test.parseStrings();
    test.compareStrings();
    return 0;
}
