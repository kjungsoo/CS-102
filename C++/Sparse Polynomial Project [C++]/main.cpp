/* _________________________________
| Jung Kim                          |
| Christine Nguyen                  |
| CS-102 Programming II             |
| Professor Hamaker                 |
| Project 2 - 'Sparse Polynomials'  |
------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Dlist.cpp"

using namespace std;

int cmp_int(Node<int> *cmp1, Node<int> *cmp2)
{
    int cmpBool = 0;
    if (cmp1 -> val > cmp2 -> val)
        cmpBool = 1;

    return cmpBool;
}

int cmp_poly(Node<monomial> *cmp1, Node<monomial> *cmp2)
{
    int cmpBool = 0;
    if (cmp1 -> val.degree < cmp2 -> val.degree)
        cmpBool = 1;

    else if (cmp1 -> val.degree > cmp2 -> val.degree)
        cmpBool = -1;

    else
    {
        if (cmp1 -> val.coefficient < cmp2 -> val.coefficient)
            cmpBool = 1;

        else if (cmp1 -> val.coefficient > cmp2 -> val.coefficient)
            cmpBool = -1;
    }

    return cmpBool;
}

void menu_interface()
{
    int intro_response, main_response, sub_response, sub2_response, sub3_response, response_override, sub_response_override, polysub_response_override,
        main_menu, mod_submenu, modcreate_submenu, modDel_submenu, modsort_submenu, math_submenu, poly1_submenu, poly2_submenu, poly3_submenu,
        add_submenu, subtract_submenu, mult_submenu,
        num_of_mono, num_of_mono2, num_of_mono3,
        deg_temp, delpos, startpos, finishpos, targ_pos, swap_pos;
    double coeff_temp, constant;

    cout << "SPARSE POLYNOMIAL" << endl
         << "A sparse polynomial is a polynomial that contain few (or sparse) number of terms but with large degrees." << endl
         << "For example: 3x^7000 + 15x^3500 + 30x^900 contains only 3 non-zero terms but are of very large powers (7000, 3500 and 900)." << endl
         << "This sparse polynomial class allows users to create sparse polynomials and perform simple manipulations of these polynomials" << endl
         << "such as changing the sparse polynomials by adding new terms and removing existing terms," << endl
         << "or by adding, subtracting and multiplying two sparse polynomials to make a new sparse polynomial." << endl
         << "To continue on, this program will require the user to enter the digit '1'." << endl
         << "If any other key is entered, the program will terminate." << endl;
    cout << "ENTER *1* HERE: "; cin >> intro_response;

    if (intro_response == 1)
        system("CLS");
    else
        exit(1);

    cout << "To create a polynomial, enter each term individually." << endl
         << "Initialize the polynomial by entering the number of non-zero terms in the polynomial" << endl << endl;

    cout << "Number of non-zero terms (If polynomial only contains the term 0, enter '1'): "; cin >> num_of_mono;

    if (num_of_mono == 0)
    {
        cout << "ERROR: Cannot have a polynomial with 0 terms." << endl
             << "NOTE: 0x^0, or 0, counts as a term."
             << "Polynomial defaulted to contain 1 term." << endl;
        num_of_mono++;
    }

    monomial poly[num_of_mono];
    cout << endl
         << "Enter the degree and coefficient for each term of the polynomial." << endl
         << "The order in which the terms are entered does not matter." << endl
         << "First enter the coefficient and then the degree of the term." << endl;
    for (int i = 0; i < num_of_mono; i++)
    {
        cout << "Coefficient: "; cin >> coeff_temp;
        cout << "Degree: "; cin >> deg_temp;
        poly[i] = monomial(coeff_temp, deg_temp);
    }
    Dlist<monomial> polynomial1(num_of_mono, poly);
    //end 1st polynomial

    //start 2nd polynomial
    cout << endl << "Initialize the second polynomial." << endl;
    cout << "Number of non-zero terms (If polynomial only contains the term 0, enter '1'): "; cin >> num_of_mono2;
    if (num_of_mono2 == 0)
    {
        cout << "ERROR: Cannot have a polynomial with 0 terms." << endl
             << "NOTE: 0x^0, or 0, counts as a term."
             << "Polynomial defaulted to contain 1 term." << endl;
        num_of_mono2++;
    }

    monomial poly2[num_of_mono2];
    cout << endl
         << "Enter the degree and coefficient for each term of the second polynomial." << endl;
    for (int i = 0; i < num_of_mono2; i++)
    {
        cout << "Coefficient: "; cin >> coeff_temp;
        cout << "Degree: "; cin >> deg_temp;
        poly2[i] = monomial(coeff_temp, deg_temp);
    }
    Dlist<monomial> polynomial2(num_of_mono2, poly2);
    //end 2nd polynomial

    //start 3rd polynomial
    cout << endl << "Initialize the third polynomial." << endl;
    cout << "Number of non-zero terms (If polynomial only contains the term 0, enter '1'): "; cin >> num_of_mono3;
    if (num_of_mono3 == 0)
    {
        cout << "ERROR: Cannot have a polynomial with 0 terms." << endl
             << "NOTE: 0x^0, or 0, counts as a term."
             << "Polynomial defaulted to contain 1 term." << endl;
        num_of_mono3++;
    }

    monomial poly3[num_of_mono3];
    cout << endl
         << "Enter the degree and coefficient for each term of the second polynomial." << endl;
    for (int i = 0; i < num_of_mono3; i++)
    {
        cout << "Coefficient: "; cin >> coeff_temp;
        cout << "Degree: "; cin >> deg_temp;
        poly3[i] = monomial(coeff_temp, deg_temp);
    }
    Dlist<monomial> polynomial3(num_of_mono3, poly3);
    //end 3rd polynomial

    system("CLS");

    do
    {
        main_menu = 0;
        cout << "MAIN MENU" << endl
             << "Enter the corresponding digit:" << endl
             << "1. MODIFY" << endl
             << "2. DISPLAY" << endl
             << "3. POLYNOMIAL ARITHMETIC" << endl
             << "5. EXIT" << endl;
        cin >> main_menu;

        switch (main_menu)
        {
            case 1:
                do
                {
                    sub_response = 0;
                    sub2_response = 0;
                    response_override = 0;
                    sub_response_override = 0;
                    mod_submenu = 0;

                    system("CLS");
                    cout << "MODIFICATION" << endl;
                    cout << "Enter the corresponding digit:" << endl
                         << "1. CREATE" << endl
                         << "2. DELETE" << endl
                         << "3. ORGANIZE" << endl
                         << "5. RETURN" << endl;
                    cin >> mod_submenu;

                    switch (mod_submenu)
                    {
                    case 1:
                        do
                        {
                            sub_response = 0;
                            sub2_response = 0;
                            sub3_response = 0;
                            response_override = 0;
                            sub_response_override = 0;
                            polysub_response_override = 0;
                            modcreate_submenu = 0;

                            system("CLS");
                            cout << "CREATION" << endl;
                            cout << "Enter the digit corresponding to the polynomial" << endl
                                 << "1. POLYNOMIAL 1" << endl
                                 << "2. POLYNOMIAL 2" << endl
                                 << "3. POLYNOMIAL 3" << endl
                                 << "5. RETURN" << endl;
                            cin >> modcreate_submenu;

                            switch (modcreate_submenu)
                            {
                            case 1:
                                do
                                {
                                    sub2_response = 0;
                                    sub3_response = 0;
                                    sub_response_override = 0;
                                    polysub_response_override = 0;
                                    poly1_submenu = 0;

                                    system("CLS");
                                    cout << "POLYNOMIAL 1 - CREATION" << endl
                                         << "Enter the corresponding digit:" << endl
                                         << "1. Add term to front" << endl
                                         << "2. Add term to back" << endl
                                         << "3. Insert term to a known location" << endl
                                         << "5. RETURN" << endl;
                                    cin >> poly1_submenu;

                                    switch (poly1_submenu)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Adding a term to the left end of POLYNOMIAL 1" << endl
                                             << "Enter the degree and coefficient for the new term." << endl;
                                        cout << "Coefficient: "; cin >> coeff_temp;
                                        cout << "Degree: "; cin >> deg_temp;
                                        system("CLS");
                                        cout << "The new term is: " << coeff_temp << "x^" << deg_temp << endl;
                                        polynomial1.push_f(monomial(coeff_temp, deg_temp));
                                        break;

                                    case 2:
                                        system("CLS");
                                        cout << "Adding a term to the right end of POLYNOMIAL 1" << endl
                                             << "Enter the degree and coefficient for the new term." << endl;
                                        cout << "Coefficient: "; cin >> coeff_temp;
                                        cout << "Degree: "; cin >> deg_temp;
                                        system("CLS");
                                        cout << "The new term is: " << coeff_temp << "x^" << deg_temp << endl;
                                        polynomial1.push_b(monomial(coeff_temp, deg_temp));
                                        break;

                                    case 3:
                                        system("CLS");
                                        cout << "Inserting a term into POLYNOMIAL 1"
                                             << "Enter the degree and coefficient for the new term." << endl;
                                        cout << "Coefficient: "; cin >> coeff_temp;
                                        cout << "Degree: "; cin >> deg_temp;
                                        system("CLS");
                                        cout << "The new term is: " << coeff_temp << "x^" << deg_temp << endl;
                                        polynomial1.ins_node(monomial(coeff_temp, deg_temp));
                                        break;

                                    case 5:
                                        system("CLS");
                                        polysub_response_override = 1;
                                        break;
                                    }

                                if (polysub_response_override == 1)
                                    sub3_response = 2;

                                else
                                {
                                    cout << "Create additional terms for POLYNOMIAL 1?" << endl;
                                    cout << "Enter the digit '1' to confirm: "; cin >> sub3_response;
                                    system("CLS");
                                }

                                } while (sub3_response == 1);
                                break;

                            case 2:
                                do
                                {
                                    sub2_response = 0;
                                    sub3_response = 0;
                                    sub_response_override = 0;
                                    polysub_response_override = 0;
                                    poly2_submenu = 0;

                                    system("CLS");
                                    cout << "POLYNOMIAL 2 - CREATION" << endl
                                         << "Enter the corresponding digit:" << endl
                                         << "1. Add term to front" << endl
                                         << "2. Add term to back" << endl
                                         << "3. Insert term to a known location" << endl
                                         << "5. RETURN" << endl;
                                    cin >> poly2_submenu;

                                    switch (poly2_submenu)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Adding a term to the left end of POLYNOMIAL 2" << endl
                                             << "Enter the degree and coefficient for the new term." << endl;
                                        cout << "Coefficient: "; cin >> coeff_temp;
                                        cout << "Degree: "; cin >> deg_temp;
                                        system("CLS");
                                        cout << "The new term is: " << coeff_temp << "x^" << deg_temp << endl;
                                        polynomial2.push_f(monomial(coeff_temp, deg_temp));
                                        break;

                                    case 2:
                                        system("CLS");
                                        cout << "Adding a term to the right end of POLYNOMIAL 2" << endl
                                             << "Enter the degree and coefficient for the new term." << endl;
                                        cout << "Coefficient: "; cin >> coeff_temp;
                                        cout << "Degree: "; cin >> deg_temp;
                                        system("CLS");
                                        cout << "The new term is: " << coeff_temp << "x^" << deg_temp << endl;
                                        polynomial2.push_b(monomial(coeff_temp, deg_temp));
                                        break;

                                    case 3:
                                        system("CLS");
                                        cout << "Inserting a term into POLYNOMIAL 2"
                                             << "Enter the degree and coefficient for the new term." << endl;
                                        cout << "Coefficient: "; cin >> coeff_temp;
                                        cout << "Degree: "; cin >> deg_temp;
                                        system("CLS");
                                        cout << "The new term is: " << coeff_temp << "x^" << deg_temp << endl;
                                        polynomial2.ins_node(monomial(coeff_temp, deg_temp));
                                        break;

                                    case 5:
                                        system("CLS");
                                        polysub_response_override = 1;
                                        break;
                                    }

                                if (polysub_response_override == 1)
                                    sub3_response = 2;

                                else
                                {
                                    cout << "Create additional terms for POLYNOMIAL 2?" << endl;
                                    cout << "Enter the digit '1' to confirm: "; cin >> sub3_response;
                                    system("CLS");
                                }

                                } while (sub3_response == 1);
                                break;

                            case 3:
                                do
                                {
                                    sub2_response = 0;
                                    sub3_response = 0;
                                    sub_response_override = 0;
                                    polysub_response_override = 0;
                                    poly3_submenu = 0;

                                    system("CLS");
                                    cout << "POLYNOMIAL 3 - CREATION" << endl
                                         << "Enter the corresponding digit:" << endl
                                         << "1. Add term to front" << endl
                                         << "2. Add term to back" << endl
                                         << "3. Insert term to a known location" << endl
                                         << "5. RETURN" << endl;
                                    cin >> poly3_submenu;

                                    switch (poly3_submenu)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Adding a term to the left end of POLYNOMIAL 3" << endl
                                             << "Enter the degree and coefficient for the new term." << endl;
                                        cout << "Coefficient: "; cin >> coeff_temp;
                                        cout << "Degree: "; cin >> deg_temp;
                                        system("CLS");
                                        cout << "The new term is: " << coeff_temp << "x^" << deg_temp << endl;
                                        polynomial3.push_f(monomial(coeff_temp, deg_temp));
                                        break;

                                    case 2:
                                        system("CLS");
                                        cout << "Adding a term to the right end of POLYNOMIAL 3" << endl
                                             << "Enter the degree and coefficient for the new term." << endl;
                                        cout << "Coefficient: "; cin >> coeff_temp;
                                        cout << "Degree: "; cin >> deg_temp;
                                        system("CLS");
                                        cout << "The new term is: " << coeff_temp << "x^" << deg_temp << endl;
                                        polynomial3.push_b(monomial(coeff_temp, deg_temp));
                                        break;

                                    case 3:
                                        system("CLS");
                                        cout << "Inserting a term into POLYNOMIAL 3"
                                             << "Enter the degree and coefficient for the new term." << endl;
                                        cout << "Coefficient: "; cin >> coeff_temp;
                                        cout << "Degree: "; cin >> deg_temp;
                                        system("CLS");
                                        cout << "The new term is: " << coeff_temp << "x^" << deg_temp << endl;
                                        polynomial3.ins_node(monomial(coeff_temp, deg_temp));
                                        break;

                                    case 5:
                                        system("CLS");
                                        polysub_response_override = 1;
                                        break;
                                    }

                                if (polysub_response_override == 1)
                                    sub3_response = 2;

                                else
                                {
                                    cout << "Create additional terms for POLYNOMIAL 3?" << endl;
                                    cout << "Enter the digit '1' to confirm: "; cin >> sub3_response;
                                    system("CLS");
                                }

                                } while (sub3_response == 1);
                                break;

                            case 5:
                                system("CLS");
                                sub_response_override = 1;
                                break;
                            }

                        if (polysub_response_override == 1)
                            sub2_response = 1;

                        else if (sub_response_override == 1)
                            sub2_response = 2;

                        else
                        {
                            cout << "Create additional terms for the polynomials?" << endl;
                            cout << "Enter the digit '1' to confirm: "; cin >> sub2_response;
                            system("CLS");
                        }

                        } while (sub2_response == 1);
                        break;

                    case 2:
                        do
                        {
                            sub_response = 0;
                            sub2_response = 0;
                            sub3_response = 0;
                            response_override = 0;
                            sub_response_override = 0;
                            polysub_response_override = 0;
                            modDel_submenu = 0;

                            system("CLS");
                            cout << "DELETION" << endl;
                            cout << "Enter the digit corresponding to the polynomial" << endl
                                 << "1. POLYNOMIAL 1" << endl
                                 << "2. POLYNOMIAL 2" << endl
                                 << "3. POLYNOMIAL 3" << endl
                                 << "5. RETURN" << endl;
                            cin >> modDel_submenu;

                            switch (modDel_submenu)
                            {
                            case 1:
                                do
                                {
                                    sub2_response = 0;
                                    sub3_response = 0;
                                    sub_response_override = 0;
                                    polysub_response_override = 0;
                                    poly1_submenu = 0;

                                    system("CLS");
                                    cout << "POLYNOMIAL 1 - DELETION" << endl
                                         << "Enter the corresponding digit:" << endl
                                         << "1. Remove term from front" << endl
                                         << "2. Remove term from back" << endl
                                         << "3. Delete a known term" << endl
                                         << "5. RETURN" << endl;
                                    cin >> poly1_submenu;

                                    switch (poly1_submenu)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Removing a term from the left end of POLYNOMIAL 1" << endl;
                                        cout << "POLYNOMIAL 1: "; polynomial1.display_poly(); cout << endl;
                                        if (polynomial1.listsize == 1)
                                        {
                                            cout << "ERROR: Cannot remove the only term in POLYNOMIAL 1" << endl;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Removing term: " << polynomial1[0] -> val.coefficient << "x^" << polynomial1[0] -> val.degree << endl;
                                            polynomial1.pop_f();
                                            break;
                                        }

                                    case 2:
                                        system("CLS");
                                        cout << "Removing a term from the right end of POLYNOMIAL 1" << endl;
                                        cout << "POLYNOMIAL 1: "; polynomial1.display_poly(); cout << endl;
                                        if (polynomial1.listsize == 1)
                                        {
                                            cout << "ERROR: Cannot remove the only term in POLYNOMIAL 1" << endl;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Removing term: " << polynomial1[polynomial1.listsize - 1] -> val.coefficient << "x^" << polynomial1[polynomial1.listsize - 1] -> val.degree << endl;
                                            polynomial1.pop_b();
                                            break;
                                        }

                                    case 3:
                                        system("CLS");
                                        cout << "Removing a term from POLYNOMIAL 1" << endl;
                                        cout << "POLYNOMIAL 1: "; polynomial1.display_poly(); cout << endl;
                                        if (polynomial1.listsize == 1)
                                        {
                                            cout << "ERROR: Cannot remove the only term in POLYNOMIAL 1" << endl;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Enter the position of the term for deletion" << endl
                                                 << "i.e. In the polynomial: 3x^3 + 5x^5 + 7x^7, to delete the term 5x^5, enter '2'" << endl;
                                            cin >> delpos;
                                            cout << "Removing term: " << polynomial1[delpos - 1] -> val.coefficient << "x^" << polynomial1[delpos - 1] -> val.degree << endl;
                                            polynomial1.del_node(polynomial1[delpos - 1]);
                                            break;
                                        }

                                    case 5:
                                        system("CLS");
                                        polysub_response_override = 1;
                                        break;
                                    }

                                if (polysub_response_override == 1)
                                    sub3_response = 2;

                                else
                                {
                                    cout << "Delete additional terms for POLYNOMIAL 1?" << endl;
                                    cout << "Enter the digit '1' to confirm: "; cin >> sub3_response;
                                    system("CLS");
                                }

                                } while (sub3_response == 1);
                                break;

                            case 2:
                                do
                                {
                                    sub2_response = 0;
                                    sub3_response = 0;
                                    sub_response_override = 0;
                                    polysub_response_override = 0;
                                    poly2_submenu = 0;

                                    system("CLS");
                                    cout << "POLYNOMIAL 2 - DELETION" << endl
                                         << "Enter the corresponding digit:" << endl
                                         << "1. Remove term from front" << endl
                                         << "2. Remove term from back" << endl
                                         << "3. Delete a known term" << endl
                                         << "5. RETURN" << endl;
                                    cin >> poly2_submenu;

                                    switch (poly2_submenu)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Removing a term from the left end of POLYNOMIAL 2" << endl;
                                        cout << "POLYNOMIAL 2: "; polynomial2.display_poly(); cout << endl;
                                        if (polynomial2.listsize == 1)
                                        {
                                            cout << "ERROR: Cannot remove the only term in POLYNOMIAL 2" << endl;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Removing term: " << polynomial2[0] -> val.coefficient << "x^" << polynomial2[0] -> val.degree << endl;
                                            polynomial2.pop_f();
                                            break;
                                        }

                                    case 2:
                                        system("CLS");
                                        cout << "Removing a term from the right end of POLYNOMIAL 2" << endl;
                                        cout << "POLYNOMIAL 2: "; polynomial2.display_poly(); cout << endl;
                                        if (polynomial2.listsize == 1)
                                        {
                                            cout << "ERROR: Cannot remove the only term in POLYNOMIAL 2" << endl;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Removing term: " << polynomial2[polynomial2.listsize - 1] -> val.coefficient << "x^" << polynomial2[polynomial2.listsize - 1] -> val.degree << endl;
                                            polynomial2.pop_b();
                                            break;
                                        }

                                    case 3:
                                        system("CLS");
                                        cout << "Removing a term from POLYNOMIAL 2" << endl;
                                        cout << "POLYNOMIAL 2: "; polynomial2.display_poly(); cout << endl;
                                        if (polynomial2.listsize == 1)
                                        {
                                            cout << "ERROR: Cannot remove the only term in POLYNOMIAL 2" << endl;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Enter the position of the term for deletion" << endl
                                                 << "i.e. In the polynomial: 3x^3 + 5x^5 + 7x^7, to delete the term 5x^5, enter '2'" << endl;
                                            cin >> delpos;
                                            cout << "Removing term: " << polynomial2[delpos - 1] -> val.coefficient << "x^" << polynomial2[delpos - 1] -> val.degree << endl;
                                            polynomial2.del_node(polynomial2[delpos - 1]);
                                            break;
                                        }

                                    case 5:
                                        system("CLS");
                                        polysub_response_override = 1;
                                        break;
                                    }

                                if (polysub_response_override == 1)
                                    sub3_response = 2;

                                else
                                {
                                    cout << "Delete additional terms for POLYNOMIAL 2?" << endl;
                                    cout << "Enter the digit '1' to confirm: "; cin >> sub3_response;
                                    system("CLS");
                                }

                                } while (sub3_response == 1);
                                break;

                            case 3:
                                do
                                {
                                    sub2_response = 0;
                                    sub3_response = 0;
                                    sub_response_override = 0;
                                    polysub_response_override = 0;
                                    poly3_submenu = 0;

                                    system("CLS");
                                    cout << "POLYNOMIAL 3 - DELETION" << endl
                                         << "Enter the corresponding digit:" << endl
                                         << "1. Remove term from front" << endl
                                         << "2. Remove term from back" << endl
                                         << "3. Delete a known term" << endl
                                         << "5. RETURN" << endl;
                                    cin >> poly3_submenu;

                                    switch (poly3_submenu)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Removing a term from the left end of POLYNOMIAL 3" << endl;
                                        cout << "POLYNOMIAL 3: "; polynomial3.display_poly(); cout << endl;
                                        if (polynomial3.listsize == 1)
                                        {
                                            cout << "ERROR: Cannot remove the only term in POLYNOMIAL 3" << endl;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Removing term: " << polynomial3[0] -> val.coefficient << "x^" << polynomial3[0] -> val.degree << endl;
                                            polynomial3.pop_f();
                                            break;
                                        }

                                    case 2:
                                        system("CLS");
                                        cout << "Removing a term from the right end of POLYNOMIAL 3" << endl;
                                        cout << "POLYNOMIAL 3: "; polynomial3.display_poly(); cout << endl;
                                        if (polynomial3.listsize == 1)
                                        {
                                            cout << "ERROR: Cannot remove the only term in POLYNOMIAL 3" << endl;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Removing term: " << polynomial3[polynomial3.listsize - 1] -> val.coefficient << "x^" << polynomial3[polynomial3.listsize - 1] -> val.degree << endl;
                                            polynomial3.pop_b();
                                            break;
                                        }

                                    case 3:
                                        system("CLS");
                                        cout << "Removing a term from POLYNOMIAL 3" << endl;
                                        cout << "POLYNOMIAL 3: "; polynomial3.display_poly(); cout << endl;
                                        if (polynomial3.listsize == 1)
                                        {
                                            cout << "ERROR: Cannot remove the only term in POLYNOMIAL 3" << endl;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Enter the position of the term for deletion" << endl
                                                 << "i.e. In the polynomial: 3x^3 + 5x^5 + 7x^7, to delete the term 5x^5, enter '2'" << endl;
                                            cin >> delpos;
                                            cout << "Removing term: " << polynomial3[delpos - 1] -> val.coefficient << "x^" << polynomial3[delpos - 1] -> val.degree << endl;
                                            polynomial3.del_node(polynomial3[delpos - 1]);
                                            break;
                                        }

                                    case 5:
                                        system("CLS");
                                        polysub_response_override = 1;
                                        break;
                                    }

                                if (polysub_response_override == 1)
                                    sub3_response = 2;

                                else
                                {
                                    cout << "Delete additional terms for POLYNOMIAL 3?" << endl;
                                    cout << "Enter the digit '1' to confirm: "; cin >> sub3_response;
                                    system("CLS");
                                }

                                } while (sub3_response == 1);
                                break;

                            case 5:
                                system("CLS");
                                sub_response_override = 1;
                                break;
                            }

                        if (polysub_response_override == 1)
                            sub2_response = 1;

                        else if (sub_response_override == 1)
                            sub2_response = 2;

                        else
                        {
                            cout << "Delete additional terms for the polynomials?" << endl;
                            cout << "Enter the digit '1' to confirm: "; cin >> sub2_response;
                            system("CLS");
                        }

                        } while (sub2_response == 1);
                        break;

                    case 3:
                        do
                        {
                            sub_response = 0;
                            sub2_response = 0;
                            sub3_response = 0;
                            response_override = 0;
                            sub_response_override = 0;
                            polysub_response_override = 0;
                            modsort_submenu = 0;

                            system("CLS");
                            cout << "ORGANIZATION" << endl;
                            cout << "Enter the digit corresponding to the polynomial" << endl
                                 << "1. POLYNOMIAL 1" << endl
                                 << "2. POLYNOMIAL 2" << endl
                                 << "3. POLYNOMIAL 3" << endl
                                 << "5. RETURN" << endl;
                            cin >> modsort_submenu;

                            switch (modsort_submenu)
                            {
                            case 1:
                                do
                                {
                                    sub2_response = 0;
                                    sub3_response = 0;
                                    sub_response_override = 0;
                                    polysub_response_override = 0;
                                    poly1_submenu = 0;

                                    system("CLS");
                                    cout << "POLYNOMIAL 1 - ORGANIZATION" << endl
                                         << "Enter the corresponding digit:" << endl
                                         << "1. Combine like terms" << endl
                                         << "2. Sort entire polynomial in descending order" << endl
                                         << "3. Sort a section of the polynomial in descending order" << endl
                                         << "5. Swap positions of two terms in the polynomial" << endl
                                         << "7. RETURN" << endl;
                                    cin >> poly1_submenu;

                                    switch (poly1_submenu)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Combining like terms for POLYNOMIAL 1" << endl;
                                        polynomial1.poly_cleanup();
                                        break;

                                    case 2:
                                        system("CLS");
                                        cout << "Sorting POLYNOMIAL 1 in descending order" << endl;
                                        polynomial1.sort_nodes(cmp_poly);
                                        break;

                                    case 3:
                                        system("CLS");
                                        cout << "Sorting fragment of POLYNOMIAL 1 in descending order" << endl
                                             << "POLYNOMIAL 1: "; polynomial1.display_poly(); cout << endl
                                             << "Enter start and finish positions for the section to sort" << endl
                                             << "i.e. In the polynomial: 3x^3 + 5x^5 + 7x^7 + 8x^8, to sort the section 3x^3 + 5x^5 + 7x^7 enter the position 1 then 3" << endl;
                                        cout << "Start: "; cin >> startpos;
                                        cout << "Finish: "; cin >> finishpos;
                                        polynomial1.sort_nodes(polynomial1[startpos - 1], polynomial1[finishpos - 1], cmp_poly);
                                        break;

                                    case 5:
                                        system("CLS");
                                        cout << "Swapping two terms in POLYNOMIAL 1" << endl
                                             << "POLYNOMIAL 1: "; polynomial1.display_poly(); cout << endl
                                             << "Enter the positions of the two terms to swap" << endl
                                             << "i.e. In the polynomial: 3x^3 + 5x^5 + 7x^7 + 8x^8, to swap 5x^5 and 7x^7 enter the position 2 then 3" << endl;
                                        cout << "Position of term to swap: "; cin >> targ_pos;
                                        cout << "Position of term to swap to: "; cin >> swap_pos;
                                        polynomial1.swap_nodes(targ_pos, swap_pos);
                                        break;

                                    case 7:
                                        system("CLS");
                                        polysub_response_override = 1;
                                        break;
                                    }

                                if (polysub_response_override == 1)
                                    sub3_response = 2;

                                else
                                {
                                    cout << "Make additional changes to POLYNOMIAL 1?" << endl;
                                    cout << "Enter the digit '1' to confirm: "; cin >> sub3_response;
                                    system("CLS");
                                }

                                } while (sub3_response == 1);
                                break;

                            case 2:
                                do
                                {
                                    sub2_response = 0;
                                    sub3_response = 0;
                                    sub_response_override = 0;
                                    polysub_response_override = 0;
                                    poly2_submenu = 0;

                                    system("CLS");
                                    cout << "POLYNOMIAL 2 - ORGANIZATION" << endl
                                         << "Enter the corresponding digit:" << endl
                                         << "1. Combine like terms" << endl
                                         << "2. Sort entire polynomial in descending order" << endl
                                         << "3. Sort a section of the polynomial in descending order" << endl
                                         << "5. Swap positions of two terms in the polynomial" << endl
                                         << "7. RETURN" << endl;
                                    cin >> poly2_submenu;

                                    switch (poly2_submenu)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Combining like terms for POLYNOMIAL 2" << endl;
                                        polynomial2.poly_cleanup();
                                        break;

                                    case 2:
                                        system("CLS");
                                        cout << "Sorting POLYNOMIAL 2 in descending order" << endl;
                                        polynomial2.sort_nodes(cmp_poly);
                                        break;

                                    case 3:
                                        system("CLS");
                                        cout << "Sorting fragment of POLYNOMIAL 2 in descending order" << endl
                                             << "POLYNOMIAL 2: "; polynomial2.display_poly(); cout << endl
                                             << "Enter start and finish positions for the section to sort" << endl
                                             << "i.e. In the polynomial: 3x^3 + 5x^5 + 7x^7 + 8x^8, to sort the section 3x^3 + 5x^5 + 7x^7 enter the position 1 then 3" << endl;
                                        cout << "Start: "; cin >> startpos;
                                        cout << "Finish: "; cin >> finishpos;
                                        polynomial2.sort_nodes(polynomial2[startpos - 1], polynomial2[finishpos - 1], cmp_poly);
                                        break;

                                    case 5:
                                        system("CLS");
                                        cout << "Swapping two terms in POLYNOMIAL 2" << endl
                                             << "POLYNOMIAL 2: "; polynomial2.display_poly(); cout << endl
                                             << "Enter the positions of the two terms to swap" << endl
                                             << "i.e. In the polynomial: 3x^3 + 5x^5 + 7x^7 + 8x^8, to swap 5x^5 and 7x^7 enter the position 2 then 3" << endl;
                                        cout << "Position of term to swap: "; cin >> targ_pos;
                                        cout << "Position of term to swap to: "; cin >> swap_pos;
                                        polynomial2.swap_nodes(targ_pos, swap_pos);
                                        break;

                                    case 7:
                                        system("CLS");
                                        polysub_response_override = 1;
                                        break;
                                    }

                                if (polysub_response_override == 1)
                                    sub3_response = 2;

                                else
                                {
                                    cout << "Make additional changes to POLYNOMIAL 2?" << endl;
                                    cout << "Enter the digit '1' to confirm: "; cin >> sub3_response;
                                    system("CLS");
                                }

                                } while (sub3_response == 1);
                                break;

                            case 3:
                                do
                                {
                                    sub2_response = 0;
                                    sub3_response = 0;
                                    sub_response_override = 0;
                                    polysub_response_override = 0;
                                    poly3_submenu = 0;

                                    system("CLS");
                                    cout << "POLYNOMIAL 3 - ORGANIZATION" << endl
                                         << "Enter the corresponding digit:" << endl
                                         << "1. Combine like terms" << endl
                                         << "2. Sort entire polynomial in descending order" << endl
                                         << "3. Sort a section of the polynomial in descending order" << endl
                                         << "5. Swap positions of two terms in the polynomial" << endl
                                         << "7. RETURN" << endl;
                                    cin >> poly3_submenu;

                                    switch (poly3_submenu)
                                    {
                                    case 1:
                                        system("CLS");
                                        cout << "Combining like terms for POLYNOMIAL 3" << endl;
                                        polynomial3.poly_cleanup();
                                        break;

                                    case 2:
                                        system("CLS");
                                        cout << "Sorting POLYNOMIAL 3 in descending order" << endl;
                                        polynomial3.sort_nodes(cmp_poly);
                                        break;

                                    case 3:
                                        system("CLS");
                                        cout << "Sorting fragment of POLYNOMIAL 3 in descending order" << endl
                                             << "POLYNOMIAL 3: "; polynomial3.display_poly(); cout << endl
                                             << "Enter start and finish positions for the section to sort" << endl
                                             << "i.e. In the polynomial: 3x^3 + 5x^5 + 7x^7 + 8x^8, to sort the section 3x^3 + 5x^5 + 7x^7 enter the position 1 then 3" << endl;
                                        cout << "Start: "; cin >> startpos;
                                        cout << "Finish: "; cin >> finishpos;
                                        polynomial3.sort_nodes(polynomial3[startpos - 1], polynomial3[finishpos - 1], cmp_poly);
                                        break;

                                    case 5:
                                        system("CLS");
                                        cout << "Swapping two terms in POLYNOMIAL 3" << endl
                                             << "POLYNOMIAL 3: "; polynomial3.display_poly(); cout << endl
                                             << "Enter the positions of the two terms to swap" << endl
                                             << "i.e. In the polynomial: 3x^3 + 5x^5 + 7x^7 + 8x^8, to swap 5x^5 and 7x^7 enter the position 2 then 3" << endl;
                                        cout << "Position of term to swap: "; cin >> targ_pos;
                                        cout << "Position of term to swap to: "; cin >> swap_pos;
                                        polynomial3.swap_nodes(targ_pos, swap_pos);
                                        break;

                                    case 7:
                                        system("CLS");
                                        polysub_response_override = 1;
                                        break;
                                    }

                                if (polysub_response_override == 1)
                                    sub3_response = 2;

                                else
                                {
                                    cout << "Make additional changes to POLYNOMIAL 3?" << endl;
                                    cout << "Enter the digit '1' to confirm: "; cin >> sub3_response;
                                    system("CLS");
                                }

                                } while (sub3_response == 1);
                                break;

                            case 5:
                                system("CLS");
                                sub_response_override = 1;
                                break;
                            }

                        if (polysub_response_override == 1)
                            sub2_response = 1;

                        else if (sub_response_override == 1)
                            sub2_response = 2;


                        else
                        {
                            cout << "Continue sorting the polynomials?" << endl;
                            cout << "Enter the digit '1' to confirm: "; cin >> sub2_response;
                            system("CLS");
                        }

                        } while (sub2_response == 1);
                        break;

                    case 5:
                        system("CLS");
                        response_override = 1;
                        break;
                    }

                if (sub_response_override == 1)
                    sub_response = 1;

                else if (response_override == 1)
                {
                    sub_response = 2;
                }
                else
                {
                    cout << "Continue modifying?" << endl;
                    cout << "Enter the digit '1' to confirm: "; cin >> sub_response;
                    system("CLS");
                }

                } while (sub_response == 1);
                break;

            case 2:
                response_override = 0;
                system("CLS");
                cout << "DISPLAYING" << endl;

                cout << "POLYNOMIAL 1:" << endl;
                polynomial1.display_poly();
                cout << endl;

                cout << endl << "POLYNOMIAL 2" << endl;
                polynomial2.display_poly();
                cout << endl;

                cout << endl << "POLYNOMIAL 3" << endl;
                polynomial3.display_poly();
                cout << endl;

                cout << endl;
                break;

            case 3:
                do
                {
                    sub_response = 0;
                    sub2_response = 0;
                    response_override = 0;
                    sub_response_override = 0;
                    math_submenu = 0;
                    system("CLS");

                    cout << "*ADD* *SUBTRACT* *MULTIPLY*" << endl;
                    cout << "Enter the corresponding digit:" << endl
                         << "1. ADDITION" << endl
                         << "2. SUBTRACTION" << endl
                         << "3. MULTIPLICATION" << endl
                         << "5. RETURN" << endl;
                    cin >> math_submenu;

                    switch (math_submenu)
                    {
                    case 1:
                        do
                        {
                            sub_response = 0;
                            sub2_response = 0;
                            response_override = 0;
                            sub_response_override = 0;
                            add_submenu = 0;
                            system("CLS");

                            cout << "ADDITION" << endl;
                            cout << "Select the digit for the corresponding operation: " << endl
                                 << "1. POLYNOMIAL 1 + POLYNOMIAL 2" << endl
                                 << "2. POLYNOMIAL 1 + POLYNOMIAL 3" << endl
                                 << "3. POLYNOMIAL 2 + POLYNOMIAL 3" << endl
                                 << "5. POLYNOMIAL 1 + constant" << endl
                                 << "7. POLYNOMIAL 2 + constant" << endl
                                 << "8. POLYNOMIAL 3 + constant" << endl
                                 << "9. RETURN" << endl;
                            cin >> add_submenu;

                            switch (add_submenu)
                            {
                            case 1:
                            {
                                system("CLS");
                                polynomial1.display_poly(); cout << " + "; polynomial2.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial1 + polynomial2;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 2:
                            {
                                system("CLS");
                                polynomial1.display_poly(); cout << " + "; polynomial3.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial1 + polynomial3;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 3:
                            {
                                system("CLS");
                                polynomial2.display_poly(); cout << " + "; polynomial3.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial2 + polynomial3;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 5:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                polynomial1.display_poly(); cout << " + " << constant << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial1 + constant;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 7:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                polynomial2.display_poly(); cout << " + " << constant << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial2 + constant;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 8:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                polynomial3.display_poly(); cout << " + " << constant << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial3 + constant;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 9:
                                system("CLS");
                                sub_response_override = 1;
                                break;
                            }

                        if (sub_response_override == 1)
                            sub2_response = 2;

                        else
                        {
                            cout << "Continue addition operation?" << endl;
                            cout << "Enter the digit '1' to confirm: "; cin >> sub2_response;
                            system("CLS");
                        }

                        } while (sub2_response == 1);
                        break;

                    case 2:
                        do
                        {
                            sub_response = 0;
                            sub2_response = 0;
                            response_override = 0;
                            sub_response_override = 0;
                            subtract_submenu = 0;
                            system("CLS");

                            cout << "SUBTRACTION" << endl;
                            cout << "Select the digit for the corresponding operation: " << endl
                                 << "1. POLYNOMIAL 1 - POLYNOMIAL 2" << endl
                                 << "2. POLYNOMIAL 1 - POLYNOMIAL 3" << endl
                                 << "3. POLYNOMIAL 2 - POLYNOMIAL 1" << endl
                                 << "5. POLYNOMIAL 2 - POLYNOMIAL 3" << endl
                                 << "7. POLYNOMIAL 3 - POLYNOMIAL 1" << endl
                                 << "8. POLYNOMIAL 3 - POLYNOMIAL 2" << endl
                                 << "9. POLYNOMIAL 1 - constant" << endl
                                 << "10. POLYNOMIAL 2 - constant" << endl
                                 << "11. POLYNOMIAL 3 - constant" << endl
                                 << "12. constant - POLYNOMIAL 1" << endl
                                 << "13. constant - POLYNOMIAL 2" << endl
                                 << "15. constant - POLYNOMIAL 3" << endl
                                 << "17. RETURN" << endl;
                            cin >> subtract_submenu;

                            switch (subtract_submenu)
                            {
                            case 1:
                            {
                                system("CLS");
                                polynomial1.display_poly(); cout << " - "; polynomial2.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial1 - polynomial2;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 2:
                            {
                                system("CLS");
                                polynomial1.display_poly(); cout << " - "; polynomial3.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial1 - polynomial3;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 3:
                            {
                                system("CLS");
                                polynomial2.display_poly(); cout << " - "; polynomial1.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial2 - polynomial1;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 5:
                            {
                                system("CLS");
                                polynomial2.display_poly(); cout << " - "; polynomial3.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial2 - polynomial3;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 7:
                            {
                                system("CLS");
                                polynomial3.display_poly(); cout << " - "; polynomial1.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial3 - polynomial1;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 8:
                            {
                                system("CLS");
                                polynomial3.display_poly(); cout << " - "; polynomial2.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial3 - polynomial2;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 9:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                polynomial1.display_poly(); cout << " - " << constant << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial1 - constant;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 10:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                polynomial2.display_poly(); cout << " - " << constant << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial2 - constant;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 11:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                polynomial3.display_poly(); cout << " - " << constant << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial3 - constant;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 12:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                cout << constant << " - "; polynomial1.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = constant - polynomial1;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 13:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                cout << constant << " - "; polynomial2.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = constant - polynomial2;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 15:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                cout << constant << " - "; polynomial3.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = constant - polynomial3;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 17:
                                system("CLS");
                                sub_response_override = 1;
                                break;
                            }

                        if (sub_response_override == 1)
                            sub2_response = 2;

                        else
                        {
                            cout << "Continue subtraction operation?" << endl;
                            cout << "Enter the digit '1' to confirm: "; cin >> sub2_response;
                            system("CLS");
                        }

                        } while (sub2_response == 1);
                        break;

                    case 3:
                        do
                        {
                            sub_response = 0;
                            sub2_response = 0;
                            response_override = 0;
                            sub_response_override = 0;
                            mult_submenu = 0;
                            system("CLS");

                            cout << "MULTIPLICATION" << endl;
                            cout << "Select the digit for the corresponding operation: " << endl
                                 << "1. POLYNOMIAL 1 * POLYNOMIAL 2" << endl
                                 << "2. POLYNOMIAL 1 * POLYNOMIAL 3" << endl
                                 << "3. POLYNOMIAL 2 * POLYNOMIAL 3" << endl
                                 << "5. POLYNOMIAL 1 * constant" << endl
                                 << "7. POLYNOMIAL 2 * constant" << endl
                                 << "8. POLYNOMIAL 3 * constant" << endl
                                 << "9. RETURN" << endl;
                            cin >> mult_submenu;

                            switch (mult_submenu)
                            {
                            case 1:
                            {
                                system("CLS");
                                polynomial1.display_poly(); cout << " * "; polynomial2.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial1 * polynomial2;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 2:
                            {
                                system("CLS");
                                polynomial1.display_poly(); cout << " * "; polynomial3.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial1 * polynomial3;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 3:
                            {
                                system("CLS");
                                polynomial2.display_poly(); cout << " * "; polynomial3.display_poly(); cout << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial2 * polynomial3;
                                polynomial5.display_poly();
                                cout << endl;
                                break;

                            }
                            case 5:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                polynomial1.display_poly(); cout << " * " << constant << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial1 * constant;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 7:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                polynomial1.display_poly(); cout << " * " << constant << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial2 * constant;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 8:
                            {
                                system("CLS");
                                cout << "Enter any real number: "; cin >> constant;
                                polynomial1.display_poly(); cout << " * " << constant << " =" << endl;
                                Dlist<monomial> polynomial5 = polynomial3 * constant;
                                polynomial5.display_poly();
                                cout << endl;
                                break;
                            }

                            case 9:
                                system("CLS");
                                sub_response_override = 1;
                                break;
                            }

                        if (sub_response_override == 1)
                            sub2_response = 2;

                        else
                        {
                            cout << "Continue multiplication operation?" << endl;
                            cout << "Enter the digit '1' to confirm: "; cin >> sub2_response;
                            system("CLS");
                        }

                        } while (sub2_response == 1);
                        break;

                    case 5:
                        system("CLS");
                        response_override = 1;
                        break;
                    }

                if (sub_response_override == 1)
                    sub_response = 1;

                else if (response_override == 1)
                    sub_response = 2;

                else
                {
                    cout << "Compute additional arithmetic?" << endl;
                    cout << "Enter the digit '1' to confirm: "; cin >> sub_response;
                    system("CLS");
                }

                } while (sub_response == 1);
                break;

            case 5:
                system("CLS");
                cout << "Farewell." << endl;
                exit(1);
                break;
        }

        if (response_override == 1)
            main_response = 1;

        else
        {
            cout << "Return to main menu?" << endl;
            cout << "Enter the digit '1' to confirm: "; cin >> main_response;
            system("CLS");
        }

    } while (main_response == 1);

    cout << "Thanks!" << endl;
}

int main()
{
    menu_interface();
    return 0;
}
