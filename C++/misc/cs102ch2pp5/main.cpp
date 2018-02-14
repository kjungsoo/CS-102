#include <iostream>

using namespace std;

int main()
{
    int T = 0, O = 0, G = 0, D = 0;
    //TOO + TOO + TOO + TOO = GOOD
    for (T = 0; T <= 9; T++)
    {
        for (O = 0; O <= 9; O++)
        {
            for (G = 0; G <= 9; G++)
            {
                for (D = 0; D <= 9; D++)
                    if ((T * 100 + O * 10 + O) * 4 == G * 1000 + O * 100 + O * 10 + D)
                    {
                        if ( T != O && T != G && T != D && O != G && O != D && G != D)
                            cout << "Possible solutions: \n" << "T = " << T << ", O = " << O << ", G = " << G << ", D = " << D << endl;
                    }
            }
        }
    }
    return 0;
}
