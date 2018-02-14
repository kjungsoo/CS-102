/*
Jung Kim
CS 102
Ch.9 prob#12
*/


#include <iostream>
#include <cmath>

using namespace std;

class StoIconversion
{
public:
    void setConvert(),
         convertConvert();

private:
    string convert;
    int converted;
};

void StoIconversion::setConvert()
{
    cout << "Type in a whole number to convert from string type to int type: " << endl;
    getline(cin, convert);
}

void StoIconversion::convertConvert()
{
    converted = 0;
    int i = 0;
    int convertlength = convert.length();
    for (int sint_index = convertlength - 1; sint_index >= 0; sint_index--)
    {
        if (isdigit(convert[sint_index]))
            converted += (convert[sint_index] - 48) * pow(10.0, i);
        i++;
    }
    cout << converted;
}

int main()
{
    StoIconversion test;
    test.setConvert();
    test.convertConvert();
    return 0;
}
