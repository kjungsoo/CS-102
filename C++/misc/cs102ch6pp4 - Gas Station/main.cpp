#include <iostream>

using namespace std;

struct CAavgGas
{
    double regular = 2.35, //$ per gallon, gall per cent = 0.01 / regular or midgrade or premium
           midgrade = 2.47,
           premium = 2.55;
    string diesel = "Not offered at this station.";
};

class GasPump
{
public:
    void setPayoption(),
         setgasDispensed_auto(),
         setgasDispensed_manual();

    double getTotalCharge(),
           getTotalDispensed();

private:
    CAavgGas gasprices;
    int payOption;
    double flatpayCASH,
           flatpayCARD,
           totalgas,
           totalpaid,
           selectedprice,
           gaspercent;
};

void GasPump::setPayoption()
{
    int userResponse;
    cout << "Payment options: CARD (DEBIT/CREDIT) or CASH" << endl
         << "Enter \"1\" for CARD and \"2\" for CASH: ";
    cin >> payOption;
    if (payOption == 2)
    {
        cout << "\nSelect grade:\n(1)REGULAR (2)MIDGRADE  (3)PREMIUM" << endl
             << "Enter \"0\" to see current gas prices: ";
        cin >> userResponse;
        if (userResponse == 0)
        {
            cout << "Current gas prices are: " << endl
                 << "REGULAR: " << gasprices.regular << endl
                 << "MIDGRADE " << gasprices.midgrade << endl
                 << "PREMIUM " << gasprices.premium << endl
                 << "\nSelect grade:\n(1)REGULAR (2)MIDGRADE  (3)PREMIUM" << endl;
            cin >> userResponse;
        }

        if (userResponse == 2)
        {
            cout << "Gas option >> MIDGRADE" << endl;
            selectedprice = gasprices.midgrade;
        }
        else if (userResponse == 3)
        {
            cout << "Gas option >> PREMIUM" << endl;
            selectedprice = gasprices.premium;
        }
        else
        {
            cout << "Gas option >> REGULAR" << endl;
            selectedprice = gasprices.regular;
        }
        cout << "Enter cash amount: ";
        cin >> flatpayCASH;
        setgasDispensed_auto();
    }

    else
    {
        cout << "\nSelect grade:\n(1)REGULAR (2)MIDGRADE  (3)PREMIUM" << endl
             << "Enter \"0\" to see current gas prices: ";
        cin >> userResponse;
        if (userResponse == 0)
        {
            cout << "Current gas prices are: " << endl
                 << "REGULAR: " << gasprices.regular << endl
                 << "MIDGRADE " << gasprices.midgrade << endl
                 << "PREMIUM " << gasprices.premium << endl
                 << "\nSelect grade:\n(1)REGULAR (2)MIDGRADE  (3)PREMIUM" << endl;
            cin >> userResponse;
        }

        if (userResponse == 2)
        {
            cout << "Gas option >> MIDGRADE" << endl;
            selectedprice = gasprices.midgrade;
        }
        else if (userResponse == 3)
        {
            cout << "Gas option >> PREMIUM" << endl;
            selectedprice = gasprices.premium;
        }
        else
        {
            cout << "Gas option >> REGULAR" << endl;
            selectedprice = gasprices.regular;
        }
        cout << "Specify charge amount" << endl
             << "***Enter \"0\" to manually fill tank***" << endl
             << "***ONLY ENTER BILL AMOUNT -- DO NOT ENTER CENTS"
             << "ENTER AMOUNT HERE: ";
        cin >> userResponse;
        if (userResponse == 0)
            setgasDispensed_manual();
        else
        {
            flatpayCARD = (userResponse * 1.0);
            setgasDispensed_auto();
        }
    }
}

void GasPump::setgasDispensed_manual()
{
    double gasdispensed = 0.00, paidmoney = 0.00;
    gaspercent = 0.01 / selectedprice;
    string dispenser;

    do
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "GAS: " << gasdispensed << "     $$$: " << paidmoney << endl;
        gasdispensed += gaspercent;
        paidmoney += 0.01;
        cin >> dispenser;
    } while (dispenser == ".");
    totalgas = gasdispensed;
    totalpaid = paidmoney;
}

void GasPump::setgasDispensed_auto()
{
    double gasdispensed = 0.00, paidmoney = 0.00;

    if (payOption == 1)
        totalgas = flatpayCARD / selectedprice;
    else
        totalgas = flatpayCASH / selectedprice;

    gaspercent = 0.01 / selectedprice;
    while (gasdispensed < totalgas)
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "GAS: " << gasdispensed << "     $$$: " << paidmoney << endl;
        gasdispensed += gaspercent;
        paidmoney += 0.01;
    }
    totalgas = gasdispensed;
    totalpaid = paidmoney;
}

double GasPump::getTotalDispensed()
{
    return totalgas;
}

double GasPump::getTotalCharge()
{
    return totalpaid;
}

int main()
{
    GasPump cs102gasStation;
    cs102gasStation.setPayoption();
    cout << "Total gas: " << cs102gasStation.getTotalDispensed() - 0.01 << endl
         << "Total paid: " << cs102gasStation.getTotalCharge() - 0.01;
    return 0;
}
