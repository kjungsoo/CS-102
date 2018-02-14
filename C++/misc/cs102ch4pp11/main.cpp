#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    srand(time(0));
    int userinput, useranswer, correctdoor = rand() % 3 + 1;
    string door_1 = "Laundry Detergent", door_2 = "Laundry Detergent", door_3 = "Laundry Detergent", *playerchoice;

    if (correctdoor == 1)
        door_1 = "$1,000,000";

    else if (correctdoor == 2)
        door_2 = "$1,000,000";

    else
        door_3 = "$1,000,000";

    cout << "Which door would you like to pick? Enter the digit \"1\" for the first door, \"2\" for the second door and \"3\" for the third door: " << endl;
    cin >> userinput;

    int fake_prize = rand() % 3 + 1;

    if (userinput == correctdoor)
        while (fake_prize == correctdoor)
            fake_prize = rand() % 3 + 1;

    else
        fake_prize = 6 - correctdoor - userinput;

    if (fake_prize == 1 && door_1 == "Laundry Detergent")
        {
            cout << "One of the doors with Laundry Detergent is the first door." << endl << "Would you like to keep your choice or choose a different door?" << endl;
            cout << "You only have one chance to change your answer. " << "If you would like to keep your choice, please enter the digit \"1\" and \"0\" if otherwise: " << endl;
            cin >> useranswer;
            if (useranswer == 0)
            {
                cout << "Which door would you like to pick? Enter the digit \"1\" for the first door, \"2\" for the second door and \"3\" for the third door: " << endl;
                cin >> userinput;
            }

        }

    else if (fake_prize == 2 && door_2 == "Laundry Detergent")
        {
            cout << "One of the doors with Laundry Detergent is the second door." << endl << "Would you like to keep your choice or choose a different door?" << endl;
            cout << "You only have one chance to change your answer. " << "If you would like to keep your choice, please enter the digit \"1\" and \"0\" if otherwise: " << endl;
            cin >> useranswer;
            if (useranswer == 0)
            {
                cout << "Which door would you like to pick? Enter the digit \"1\" for the first door, \"2\" for the second door and \"3\" for the third door: " << endl;
                cin >> userinput;
            }

        }

    else
        {
            cout << "One of the doors with Laundry Detergent is the third door." << endl << "Would you like to keep your choice or choose a different door?" << endl;
            cout << "You only have one chance to change your answer. " << "If you would like to keep your choice, please enter the digit \"1\" and \"0\" if otherwise: " << endl;
            cin >> useranswer;
            if (useranswer == 0)
            {
                cout << "Which door would you like to pick? Enter the digit \"1\" for the first door, \"2\" for the second door and \"3\" for the third door: " << endl;
                cin >> userinput;
            }

        }

    if (userinput == 1)
        playerchoice = &door_1;

    else if (userinput == 2)
        playerchoice = &door_2;

    else
        playerchoice = &door_3;

    cout << "And..! The correct door is!" << endl;
    cout << "." << endl << ".." << endl << "..." << endl;

    if (correctdoor == 1)
        {
            cout << "The first door!" << endl;
            if (correctdoor == userinput)
                cout << "Congratulations! You\'ve won the grand prize: " << *playerchoice << "!" << endl;
            else
                cout << "Sorry! You didn\'t win the grand prize but here is a " << *playerchoice << " as a consolation prize!";
        }

    else if (correctdoor == 2)
        {
            cout << "The second door!" << endl;
            if (correctdoor == userinput)
                cout << "Congratulations! You\'ve won the grand prize: " << *playerchoice << "!" << endl;
            else
                cout << "Sorry! You didn\'t win the grand prize but here is a " << *playerchoice << " as a consolation prize!";
        }

    else
        {
            cout << "The third door!" << endl;
            if (correctdoor == userinput)
                cout << "Congratulations! You\'ve won the grand prize: " << *playerchoice << "!" << endl;
            else
                cout << "Sorry! You didn\'t win the grand prize but here is a " << *playerchoice << " as a consolation prize!";
        }

    return 0;
}
