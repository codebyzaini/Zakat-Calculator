#include <iostream>
using namespace std;
class ZakatCalculator
{        // blueprint
private: // members It will not change
    float cash, gold, silver, business;
    float goldRate, silverRate;
    float Totalwealth, nisab;

public:
    void inputAsset()
    {
        cout << "Enter Total Cash (Digits):" << endl;
        while (!(cin >> cash) || cash < 0)
        {
            cout << "Invalid! Enter a positive number for cash:";
            cin.clear();            // cin dubara use krne keh liye clear it
            cin.ignore(1000, '\n'); /*if type abc it will stuck in memory
             called input buffer so it
             ignores all 10000characters*/
        }

        cout << "Enter gold (grams): ";
        while (!(cin >> gold) || gold < 0)
        {
            cout << "Invalid! Enter gold in grams (positive): ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "Enter silver (grams): ";
        while (!(cin >> silver) || silver < 0)
        {
            cout << "Invalid! Enter silver in grams (positive): ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cout << "Enter today's gold rate per gram: ";
        while (!(cin >> goldRate) || goldRate <= 0)
        {
            cout << "Invalid! Enter a valid gold rate: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter today's silver rate per gram: ";
        while (!(cin >> silverRate) || silverRate <= 0)
        {
            cout << "Invalid! Enter a valid Silver rate: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter total value of business assets (Rs): ";
        while (!(cin >> business) || business < 0)
        {
            cout << "Invalid! Please enter a positive number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    void CalculateWealth()
    {
        float goldval = gold * goldRate;
        float silverval = silver * silverRate;
        Totalwealth = cash + goldval + silverval + business;
        nisab = 87.48 * silverRate;
    }
    void result()
    {
        cout << "\n------------- ZAKAT CALCULATION RESULT -------------\n";
        cout << "Total Zakatable Wealth: Rs. " << Totalwealth << endl;
        cout << "Current Nisab (87.48g Silver): Rs. " << nisab << endl;

        if (Totalwealth >= nisab)
        {
            float zakat = Totalwealth * 0.025;
            cout << "You are eligible to pay Zakat." << endl;
            cout << "Your Zakat Amount (2.5%): Rs. " << zakat << endl;
            cout << "\nJazakAllah Khair for calculating your Zakat." << endl;
            cout << " May Allah accept your charity and bless you with more barakah." << endl;
        }
        else
        {
            cout << "You are NOT eligible to pay Zakat this year." << endl;
        }

        cout << "----------------------------------------------------\n";
    }
};
int main()
{
    ZakatCalculator zakat;
    zakat.inputAsset();
    zakat.CalculateWealth();
    zakat.result();
}