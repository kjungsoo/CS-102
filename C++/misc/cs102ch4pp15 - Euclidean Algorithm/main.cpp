#include <iostream>

using namespace std;

int EuclideanAlgorithm()
{
    int numerator, denominator, commondivisor;
    cout << "Enter two numbers to find the greatest common divisor between the two numbers: " << endl;
    cin >> numerator >> denominator;

    while ((numerator > 0) && (denominator > 0))
    {
        commondivisor = numerator % denominator;
        numerator = denominator;
        denominator = commondivisor;
    }
    cout << "The two reduced terms are: " << numerator << " and " << denominator << endl;
    return 0;
}

int main()
{
    EuclideanAlgorithm();
    return 0;
}
