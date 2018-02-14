/*
Jung Kim
CS 102
Ch.10 prob #2
*/

#include <iostream>

using namespace std;

class Polynomial
{
public:
    Polynomial();  //default - all 0's
    Polynomial(int degree);  //parameterized - user defined
    Polynomial(int degree, double coeff[]); //creating polynomials through operations
    Polynomial(const Polynomial& copyPoly);  //copy '=' operator

    void accessPoly(); //modify coefficients or remove terms in polynomial
    void displayPoly(); //a very lengthy code that displays polynomials nicely

    Polynomial& operator =(const Polynomial& rtside); //assigning a polynomial to another polynomial

    friend const Polynomial operator +(Polynomial& poly1, Polynomial& poly2); //adding with other polynomials and constants
    friend const Polynomial operator +(Polynomial& poly1, double constant);
    friend const Polynomial operator +(double constant, Polynomial& poly1);

    friend const Polynomial operator -(Polynomial& poly1, Polynomial& poly2); //subtracting
    friend const Polynomial operator -(Polynomial& poly1, double constant);
    friend const Polynomial operator -(double constant, Polynomial& poly1);

    friend const Polynomial operator *(Polynomial& poly1, Polynomial& poly2); //multiplying
    friend const Polynomial operator *(Polynomial& poly1, double constant);
    friend const Polynomial operator *(double constant, Polynomial& poly1);

    ~Polynomial(); //destructor

private:
    double* poly; //coefficients stored in dynamic array
    int polydegree; //the highest degree in the polynomial, also determines the size of the poly array
};

Polynomial& Polynomial::operator =(const Polynomial& rtside)
{
    if (this == &rtside)
        return *this;
    else
    {
        polydegree = rtside.polydegree;
        delete [] poly;
        poly = new double[polydegree + 1];
        for (int i = 0; i <= polydegree; i++)
            poly[i] = rtside.poly[i];

        return *this;
    }
}

const Polynomial operator +(Polynomial& poly1, Polynomial& poly2)
{
    int polymaxlength, polyminlength;
    if (poly1.polydegree > poly2.polydegree)
    {
        polymaxlength = poly1.polydegree;
        polyminlength = poly2.polydegree;
    }
    else
    {
        polymaxlength = poly2.polydegree;
        polyminlength = poly1.polydegree;
    }

    double coeff[polymaxlength];
    for (int i = 0; i <= polyminlength; i++)
        coeff[i] = poly1.poly[i] + poly2.poly[i];

    if (poly1.polydegree > poly2.polydegree)
        for (int i = polyminlength + 1; i <= polymaxlength; i++)
            coeff[i] = poly1.poly[i];
    else
        for (int i = polyminlength + 1; i <= polymaxlength; i++)
            coeff[i] = poly2.poly[i];

    return Polynomial(polymaxlength, coeff);
}

const Polynomial operator +(Polynomial& poly1, double constant)
{
    int polylength = poly1.polydegree;
    double coeff[polylength];

    for (int i = 0; i <= polylength; i++)
        coeff[i] = poly1.poly[i];
    coeff[0] += constant;

    return Polynomial(polylength, coeff);
}

const Polynomial operator +(double constant, Polynomial& poly1)
{
    int polylength = poly1.polydegree;
    double coeff[polylength];

    for (int i = 0; i <= polylength; i++)
        coeff[i] = poly1.poly[i];
    coeff[0] += constant;

    return Polynomial(polylength, coeff);
}

const Polynomial operator -(Polynomial& poly1, Polynomial& poly2)
{
    int polymaxlength, polyminlength;
    if (poly1.polydegree > poly2.polydegree)
    {
        polymaxlength = poly1.polydegree;
        polyminlength = poly2.polydegree;
    }
    else
    {
        polymaxlength = poly2.polydegree;
        polyminlength = poly1.polydegree;
    }

    double coeff[polymaxlength];
    for (int i = 0; i <= polyminlength; i++)
        coeff[i] = poly1.poly[i] - poly2.poly[i];

    if (poly1.polydegree > poly2.polydegree)
        for (int i = polyminlength + 1; i <= polymaxlength; i++)
            coeff[i] = poly1.poly[i];
    else
        for (int i = polyminlength + 1; i <= polymaxlength; i++)
            coeff[i] = poly2.poly[i];

    return Polynomial(polymaxlength, coeff);
}

const Polynomial operator -(Polynomial& poly1, double constant)
{
    int polylength = poly1.polydegree;
    double coeff[polylength];

    for (int i = 0; i <= polylength; i++)
        coeff[i] = poly1.poly[i];
    coeff[0] -= constant;

    return Polynomial(polylength, coeff);
}

const Polynomial operator -(double constant, Polynomial& poly1)
{
    int polylength = poly1.polydegree;
    double coeff[polylength];

    for (int i = 0; i <= polylength; i++)
        coeff[i] = -1 * poly1.poly[i];
    coeff[0] = constant + coeff[0];

    return Polynomial(polylength, coeff);
}

const Polynomial operator *(Polynomial& poly1, Polynomial& poly2)
{
    int product_length = poly1.polydegree + poly2.polydegree, some_num = 0;
    double coeff[product_length], temp[poly2.polydegree];

    for (int i = 0; i <= product_length; i++)
        coeff[i] = 0;

    for (int i = 0; i <= poly1.polydegree; i++)
    {
        for (int j = 0; j <= poly2.polydegree; j++)
            temp[j] = poly1.poly[i] * poly2.poly[j];

        for (int k = 0; k <= poly2.polydegree; k++)
            coeff[k + some_num] += temp[k];

        some_num++;
    }

    return Polynomial(product_length, coeff);
}

const Polynomial operator *(Polynomial& poly1, double constant)
{
    int polylength = poly1.polydegree;
    double coeff[polylength];

    for (int i = 0; i <= polylength; i++)
        coeff[i] = poly1.poly[i] * constant;

    return Polynomial(polylength, coeff);
}

const Polynomial operator *(double constant, Polynomial& poly1)
{
    int polylength = poly1.polydegree;
    double coeff[polylength];

    for (int i = 0; i <= polylength; i++)
        coeff[i] = poly1.poly[i] * constant;

    return Polynomial(polylength, coeff);
}

Polynomial::Polynomial(int degree)
                    : polydegree(degree)
    {
        poly = new double[polydegree + 1];
        cout << "Enter the coefficient for each term starting with the 0th power:" << endl;
        for (int i = 0; i <= polydegree; i++)
            cin >> poly[i];
    }

Polynomial::Polynomial(int degree, double coeff[])
                    : polydegree(degree)
    {
        poly = new double[polydegree + 1];
        for (int i = 0; i <= polydegree; i++)
            poly[i] = coeff[i];
    }

Polynomial::Polynomial()
                    :polydegree(0)
    {
        poly = new double[1];
        poly[0] = 0;
        cout << poly[0] << "x^0" << endl;
    }

Polynomial::Polynomial(const Polynomial& copyPoly)
                    :polydegree(copyPoly.polydegree)
    {
        poly = new double[polydegree];
        for (int i = 0; i <= polydegree; i++)
            poly[i] = copyPoly.poly[i];
    }

Polynomial::~Polynomial()
    {
        delete [] poly;
    }

void Polynomial::accessPoly()
{
    int tgt_coeff_index, user_input1, user_input2;
    double temp_coeff;
    cout << "Modifying polynomial: "; displayPoly(); cout << endl;
    do
    {
        cout << "Enter a term in the polynomial to modify the coefficient:" << endl;
        cin >> tgt_coeff_index;
        if (tgt_coeff_index <= polydegree)
        {
            cout << "The coefficient for x^" << tgt_coeff_index << " is " << poly[tgt_coeff_index] << endl;
            cout << "To change the value of this coefficient, enter the digit '1'. To make no changes press any key and enter." << endl;
            cin >> user_input1;

            if (user_input1 == 1)
            {
                cout << "Enter new coefficient value to replace old value:" << endl
                     << "To remove this term, enter the coefficient '0'" << endl;
                cin >> temp_coeff;
                poly[tgt_coeff_index] = temp_coeff;
                cout << "The new polynomial is:" << endl;
                displayPoly();
                if (poly[tgt_coeff_index] == 0)
                    polydegree--;
            }
        }
        else
            cout << "The term " << tgt_coeff_index << " does not exist in the polynomial";

        cout << endl
             << "To make further changes, enter the digit '1'. Press any key and enter to exit." << endl;
        cin >> user_input2;
    } while (user_input2 == 1);
}

void Polynomial::displayPoly()
{
    if (polydegree == 0 && poly[0] == 0)
        cout << "0";
    else
        for (int j = polydegree; j >= 0; j--)
        {
            if (poly[0] == 0) //constant == 0
            {
                if (j == 1) //end of polynomial expression
                {
                    if (poly[1] == 1) //if coeff == 1
                        cout << " + x";
                    else if (poly[1] != 0)
                        cout << " + " << poly[j] << "x";
                }
                else if (j == polydegree) //start of poly expression
                {
                    if (poly[j] == 1) //if coeff == 1
                        cout << "x^" << j;
                    else if (poly[j] != 0)
                        cout << poly[j] << "x^" << j;
                }
                else if (j != 0) //rest of polynomial
                {
                    if (poly[j] == 1) //if coeff == 1
                    {
                        if (poly[polydegree] == 0) //and if the start of poly expression was 0
                            cout << "x^" << j;
                        else
                            cout << " + " << "x^" << j; //otherwise
                    }
                    else if (poly[j] != 0) //as long as coeff is not 0
                    {
                        if (poly[polydegree] == 0)
                            cout << poly[j] << "x^" << j;
                        else
                            cout << " + " << poly[j] << "x^" << j;
                    }
                }
            }
            else //with constant
            {
                if (j == 0) //the constant
                    cout << " + " << poly[j];
                else if (j == polydegree) //the start of the polynomial
                {
                    if (poly[j] == 1) //if the coeff is 1
                        cout << "x^" << j;
                    else if (poly[j] != 0)
                        cout << poly[j] << "x^" << j;
                }
                else if (j == 1) //the first term of poly
                {
                    if (poly[1] == 1)
                        cout << " + x"; //if coeff is 1
                    else if (poly[1] != 0)
                        cout << " + " << poly[j] << "x";
                }
                else //the rest of poly
                {
                    if (poly[j] == 1)
                    {
                        if (poly[polydegree] == 0) //and if the start of poly expression was 0
                            cout << "x^" << j;
                        else
                            cout << " + " << "x^" << j;
                    }
                    else if (poly[j] != 0)
                    {
                        if (poly[polydegree] == 0)
                            cout << poly[j] << "x^" << j;
                        else
                            cout << " + " << poly[j] << "x^" << j;
                    }
                }
            }
        }
}

int main() //basic operations with polynomials
{
    int degree, degree2, userinput, pickpoly;

    cout << "Enter the degree for the first polynomial:" << endl;
    cin >> degree;
    cout << "Enter the degree for the second polynomial:" << endl;
    cin >> degree2;

    Polynomial poly1(degree), poly2(degree2);

    cout << "\nThe degree " << degree << " polynomial is:" << endl;
    poly1.displayPoly();

    cout << endl << endl << "The degree " << degree2 << " polynomial is:" << endl;
    poly2.displayPoly();

    cout << endl << endl
         << "To modify these polynomials, enter the digit '1'. Enter any other key to continue: " << endl;
    cin >> userinput;
    if (userinput == 1)
    {
        cout << "To change the first polynomial, enter the digit '1'. To change the second, enter the digit '2'" << endl;
        cin >> pickpoly;
        if (pickpoly == 1)
            poly1.accessPoly();
        else
            poly2.accessPoly();
    }

    cout << endl << endl; poly1.displayPoly(); cout << " + "; poly2.displayPoly(); cout << " = ";
    Polynomial poly3 = poly1 + poly2;
    poly3.displayPoly();

    cout << endl << endl; poly1.displayPoly(); cout << " - "; poly2.displayPoly(); cout << " = ";
    Polynomial poly5 = poly1 - poly2;
    poly5.displayPoly();

    cout << endl << endl << "("; poly1.displayPoly(); cout << ") * ("; poly2.displayPoly(); cout << ") = ";
    Polynomial poly7 = poly1 * poly2;
    poly7.displayPoly();

    cout << endl << endl << "Equating the second polynomial to the first gives:" << endl;
    Polynomial poly8 = poly1;
    poly8.displayPoly();
    cout << endl;

    return 0;
}
