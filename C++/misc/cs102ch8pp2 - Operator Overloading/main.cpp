/*
Jung Kim
CS-102 Programming II
Professor Charles Hamaker
Project: Overloading Operators
*/

#include <iostream>
#include <cmath>

using namespace std;

class Rational
{
public:
    Rational();
    Rational(int wholeNumb);
    Rational(int numVal, int denomVal);

    void euclidean(),
         simplification();

    friend istream& operator >>(istream& inputstream, Rational& rationalnum);
    friend ostream& operator <<(ostream& outputstream, const Rational& rationalnum);

    friend bool operator ==(const Rational& rational1, Rational& rational2);
    friend bool operator <(const Rational& rational1, Rational& rational2);
    friend bool operator <=(const Rational& rational1, Rational& rational2);
    friend bool operator >(const Rational& rational1, Rational& rational2);
    friend bool operator >=(const Rational& rational1, Rational& rational2);

    friend const Rational operator +(Rational& rational1, Rational& rational2);
    friend const Rational operator -(Rational& rational1, Rational& rational2);
    friend const Rational operator *(Rational& rational1, Rational& rational2);
    friend const Rational operator /(Rational& rational1, Rational& rational2);

private:
    int numerator,
        denominator;
};

istream& operator >>(istream& inputstream, Rational& rationalnum)
{
    char fractionbar;
    inputstream >> rationalnum.numerator;

    if (rationalnum.numerator == 0)
    {
        Rational();
        return inputstream;
    }
    else
    {
        inputstream >> fractionbar;
        if (fractionbar == '/')
        {
            inputstream >> rationalnum.denominator;
            rationalnum.simplification();
            rationalnum.euclidean();
            return inputstream;
        }
        else
        {
            Rational(rationalnum.numerator);
            rationalnum.euclidean();
            return inputstream;
        }
    }
}

ostream& operator <<(ostream& outputstream, const Rational& rationalnum) //return something
{
    outputstream << rationalnum.numerator << '/' << rationalnum.denominator;
    return outputstream;
}

bool operator ==(const Rational& rational1, Rational& rational2)
{
    rational2.simplification();
    rational2.euclidean();
    return ((rational1.numerator * rational2.denominator) == (rational2.numerator * rational1.denominator));
}

bool operator <(const Rational& rational1, Rational& rational2)
{
    rational2.simplification();
    rational2.euclidean();
    return ((rational1.numerator * rational2.denominator) < (rational2.numerator * rational1.denominator));
}

bool operator >(const Rational& rational1, Rational& rational2)
{
    rational2.simplification();
    rational2.euclidean();
    return ((rational1.numerator * rational2.denominator) > (rational2.numerator * rational1.denominator));
}

bool operator <=(const Rational& rational1, Rational& rational2)
{
    rational2.simplification();
    rational2.euclidean();
    return ((rational1.numerator * rational2.denominator) <= (rational2.numerator * rational1.denominator));
}

bool operator >=(const Rational& rational1, Rational& rational2)
{
    rational2.simplification();
    rational2.euclidean();
    return ((rational1.numerator * rational2.denominator) >= (rational2.numerator * rational1.denominator));
}

const Rational operator +(Rational& rational1, Rational& rational2)
{
    rational2.simplification();
    rational2.euclidean();
    int summed_num, summed_denom;
    if (rational1.denominator == rational2.denominator)
    {
        summed_num = rational1.numerator + rational2.numerator;
        summed_denom = rational1.denominator;
    }
    else
    {
        summed_num = (rational1.numerator * rational2.denominator) + (rational2.numerator * rational1.denominator);
        summed_denom = rational1.denominator * rational2.denominator;
    }
    return Rational(summed_num, summed_denom);
}

const Rational operator -(Rational& rational1, Rational& rational2)
{
    rational2.simplification();
    rational2.euclidean();
    int diff_num, diff_denom;
    if (rational1.denominator == rational2.denominator)
    {
        diff_num = rational1.numerator - rational2.numerator;
        diff_denom = rational1.denominator;
    }
    else
    {
        diff_num = (rational1.numerator * rational2.denominator) - (rational2.numerator * rational1.denominator);
        diff_denom = rational1.denominator * rational2.denominator;
    }

    return Rational(diff_num, diff_denom);
}

const Rational operator *(Rational& rational1, Rational& rational2)
{
    rational2.simplification();
    rational2.euclidean();

    int prod_num = rational1.numerator * rational2.numerator,
        prod_denom = rational1.denominator * rational2.denominator;

    return Rational(prod_num, prod_denom);
}

const Rational operator /(Rational& rational1, Rational& rational2)
{
    rational2.simplification();
    rational2.euclidean();

    int quot_num = rational1.numerator * rational2.denominator,
        quot_denom = rational1.denominator * rational2.numerator;

    return Rational(quot_num, quot_denom);
}

Rational::Rational(int numVal, int denomVal)
                : numerator(numVal), denominator(denomVal){}
Rational::Rational(int wholeNumb)
                : numerator(wholeNumb), denominator(1){}
Rational::Rational()
                : numerator(0), denominator(1){}

void Rational::euclidean()
{
    int commondivisor,
        init_num = numerator, init_denom = denominator,
        modified_num = abs(numerator), modified_denum = abs(denominator);

    while (modified_num > 0 && modified_denum > 0)
    {
        commondivisor = modified_num % modified_denum;
        modified_num = modified_denum;
        modified_denum = commondivisor;
    }
    if (modified_num == 0)
        numerator = 0;
    else
    {
        denominator = init_denom / modified_num;
        numerator = init_num / modified_num;
    }
}

void Rational::simplification()
{
    if (numerator > 0 && denominator < 0)
    {
        numerator = numerator * -1;
        denominator = denominator * -1;
    }
    else if (numerator < 0 && denominator < 0)
    {
        numerator = numerator * -1;
        denominator = denominator * -1;
    }
    else if (denominator == 0)
    {
        cout << "Illegal division attempted." << endl;
        denominator = 1;
    }
}

int main()
{
    Rational rationalnum, rationalnum2(7, 49);
    cout << "The class Rational will take fraction numbers and return them in their simplest form." << endl
         << "Input the numbers in fraction form: i.e. inputting 9/81 will return 1/9." << endl
         << "Inputting 0 followed by anything will return a zero fraction: i.e. 0/10 will return 0/1." << endl
         << "Inputting a whole number followed by any symbol other than '/' will return the number itself divided by 1." << endl
         << "\nEnter a fraction: ";
    cin >> rationalnum;
    if (rationalnum > rationalnum2)
        cout << rationalnum << " is greater than " << rationalnum2 << endl;

    else if (rationalnum == rationalnum2)
        cout << rationalnum << " is equal to " << rationalnum2 << endl;

    else if (rationalnum < rationalnum2)
        cout << rationalnum << " is lesser than " << rationalnum2 << endl;

    Rational rationalnum3 = rationalnum + rationalnum2;
    rationalnum3.simplification();
    rationalnum3.euclidean();
    cout << rationalnum << " + " << rationalnum2 << " = " << rationalnum3 << endl;

    Rational rationalnum5 = rationalnum - rationalnum2;
    rationalnum5.simplification();
    rationalnum5.euclidean();
    cout << rationalnum << " - " << rationalnum2 << " = " << rationalnum5 << endl;

    Rational rationalnum7 = rationalnum * rationalnum2;
    rationalnum7.simplification();
    rationalnum7.euclidean();
    cout << rationalnum << " * " << rationalnum2 << " = " << rationalnum7 << endl;

    Rational rationalnum8 = rationalnum / rationalnum2;
    rationalnum8.simplification();
    rationalnum8.euclidean();
    cout << rationalnum << " / " << rationalnum2 << " = " << rationalnum8 << endl;

    return 0;
}
