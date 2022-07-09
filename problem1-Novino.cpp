/******************************************************************************
Project 01
Programmed by: Jolly Novino
Date Accomplished:

//This program involves features of ATM.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main()
{
    fstream iFile;
    iFile.open("jono.txt", ios::in);
    if (!iFile)
    {
        cout << "File not created!";
        return 0;
    }

    int withdrawAmount = 0;
    const float transCharge = 1.5;
    double accountBalance;
    int num = 0;
    int ctr = 0;

    //Set Numeric output formatting.
    cout << fixed << showpoint << setprecision(2);

    while (!iFile.eof()) {
        iFile >> num;


        if (ctr == 0) {
            withdrawAmount = num;
        }
        else {
            accountBalance = num;
        }
        ctr++;
    }

    if (withdrawAmount < 0 || accountBalance < 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    if (withdrawAmount % 5 != 0) {
        cout << "Incorrect Withdrawal Amount!" << endl;
        return 0;
    }

    if ((withdrawAmount + transCharge) > accountBalance) {
        cout << "Insufficient Funds!" << endl;
        cout << "Balance: " << accountBalance << endl;

        return 0;
    }

    accountBalance = accountBalance - (withdrawAmount + transCharge);

    cout << "Balance: " << accountBalance << endl;

    iFile.close();

    return 0;
}