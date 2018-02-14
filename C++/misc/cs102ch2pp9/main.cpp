#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Enter a positive number: ";
    double number;
    cin >> number;

    cout << "Enter a guess of the square root of the number you entered: ";
    double guess;
    cin >> guess;

    if (guess < sqrt(number))
        guess = number / 2;

    while (abs((sqrt(number) - guess)/sqrt(number)) > 0.001)
    {
        double r = number/guess;
        guess = (guess + r) / 2;
    }

    cout << guess;
    return 0;
}
