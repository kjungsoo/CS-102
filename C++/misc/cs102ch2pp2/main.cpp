#include <iostream>

using namespace std;

const double loaninterest = .015;
const double monthlypay = 50.00;

int main()
{
    double loanamt = 1000.00;
    double currentinterest = 0;
    double totalinterest = 0;
    int month = 0;
    while (loanamt > 0)
    {
        currentinterest = loanamt * loaninterest;
        totalinterest += currentinterest;
        loanamt = loanamt - (monthlypay - (loanamt * loaninterest));
        if (loanamt < 0)
            loanamt = 0;
        month++;
        cout << "Month " << month << endl;
        cout << "Current debt: " << loanamt << endl;
        cout << "Paid interest for this month: " << currentinterest << endl;
        cout << "Total interest paid " << totalinterest << endl;
    }
    return 0;
}
