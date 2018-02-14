#include <iostream>

using namespace std;

const double sugarinSoda = 0.001;

int main()
{
    cout << "How much does the mouse weigh?: ";
    double mouseWeight;
    cin >> mouseWeight;

    cout << "How much sugar does it take to kill the mouse?: ";
    double sugarAmt;
    cin >> sugarAmt;

    cout << "How much will you weigh after your diet?: ";
    double humanWeight;
    cin >> humanWeight;

    double sugarRatio = sugarAmt / mouseWeight;
    double deadlySugar = (humanWeight * sugarRatio) / sugarinSoda;

    cout << "It take's " << deadlySugar << " kilograms of diet soda to kill you.";

    return 0;
}
