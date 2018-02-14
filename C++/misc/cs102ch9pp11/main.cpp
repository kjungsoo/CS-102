/*
Jung Kim
CS 102
Ch.9 prob#11
*/

#include <iostream>
#include <string>

using namespace std;

class Anagram
{
public:
    void setStrings(),
         parseStrings(),
         sortStrings(),
         compareStrings();

private:
    string string1, string2,
           cleaned_string1, cleaned_string2,
           delimitters;
};

void Anagram::setStrings()
{
    cout << "Enter a word or sentence to check for anagrams: " << endl;
    getline(cin, string1);

    cout << "Enter the word or sentence you would like to check against: " << endl;
    getline(cin, string2);
}

void Anagram::parseStrings()
{
    delimitters = "`1234567890-=~!@#$%^&*()_+[]\\{}|;\':\",./<>?";
    int punc_scan = delimitters.length(),
        string_scan1 = string1.length(),
        string_scan2 = string2.length(),
        punc_index1, punc_index2;

    for (int i = 0; i < string_scan1; i++)
    {
        string1[i] = tolower(string1[i]);
        string alphacheck1 = string1.substr(i, 1);
        punc_index1 = delimitters.find(alphacheck1);

        if (punc_index1 < 0 || punc_index1 >= punc_scan)
            cleaned_string1 += alphacheck1;
    }

    for (int j = 0; j < string_scan2; j++)
    {
        string2[j] = tolower(string2[j]);
        string alphacheck2 = string2.substr(j, 1);
        punc_index2 = delimitters.find(alphacheck2);

        if (punc_index2 < 0 || punc_index2 >= punc_scan)
            cleaned_string2 += alphacheck2;
    }
}

void Anagram::sortStrings()
{
    int cleanstring_len1 = cleaned_string1.length(),
        cleanstring_len2 = cleaned_string2.length();


    for (int i = 0; i < cleanstring_len1 - 1; i++)
        for (int j = i + 1; j < cleanstring_len1; j++)
            if (cleaned_string1[i] > cleaned_string1[j])
                swap(cleaned_string1[i], cleaned_string1[j]);

    for (int i = 0; i < cleanstring_len2 - 1; i++)
        for (int j = i + 1; j < cleanstring_len2; j++)
            if (cleaned_string2[i] > cleaned_string2[j])
                swap(cleaned_string2[i], cleaned_string2[j]);
}

void Anagram::compareStrings()
{
    if (cleaned_string1 == cleaned_string2)
        cout << string2 << " is an anagram of " << string1 << "." << endl;
}

int main()
{
    Anagram test;
    test.setStrings();
    test.parseStrings();
    test.sortStrings();
    test.compareStrings();
    return 0;
}
