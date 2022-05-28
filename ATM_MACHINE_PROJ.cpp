#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
/* Mini Project - ATM
   -> Check Balance
   -> Cash withdraw
   -> User Details
   -> Update Mobile No.
*/

class atm
{
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:
    void setdata(long int account_no_a, int PIN_a,
                 double balance_a, string name_a,
                 string mobile_no_a)
    {

        account_no = account_no_a;
        PIN = PIN_a;
        name = name_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }
    //set data function sets value in private variav\ble so that no vcan access data

    //get function
    long int getAccountNo()
    {
        return account_no;
    }

    int getPIN()
    {
        return PIN;
    }

    double getbalance()
    {
        return balance;
    }

    string getMobile_no()
    {
        return mobile_no;
    }

    string getName()
    {
        return name;
    }

    void cashwithDraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balance) //check validity
        {
            balance -= amount_a;
            cout << endl
                 << "please collect your cash";
            cout << endl
                 << "Availble balance: " << balance;
            cout << endl
                 << "Thank for using Free atm";
        }

        else
        {
            cout << endl
                 << "Invalid input or insufficient balance";
        }
    }

    void setMobileNo(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_no)
        {
            mobile_no = mob_new;
            cout << endl
                 << "successfully updated mobile no : ";
            _getch();
        }

        else
        {
            cout << endl
                 << "incorect mobile no ";
            getch();
        }
    }

};

    int main()
    {
        int choice = 0, enterPIN;
        //enter pin for user  authenciation

        long int enterAccountNo;

        atm user1; // object created
        user1.setdata(1234567, 1234, 50000.70, "Manoj ALladawar", "8545958645");

        do
        {
            system("cls");
            cout << "******WELCOME TO FREE ATM******" << endl;
            cout << "Enter your Account no: ";
            cin >> enterAccountNo;

            cout << "enter your PIN: " << endl;
            cin >> enterPIN;

            //check whehter enter values are correct or not

            if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
            {
                do
                {
                    int amount = 0;
                    string newmobileno, oldmobileno;

                    system("cls");

                    cout << endl
                         << "**** Welcome to ATM *****" << endl;
                    cout << endl
                         << "Select Options ";
                    cout << endl
                         << "1. Check Balance";
                    cout << endl
                         << "2. Cash withdraw";
                    cout << endl
                         << "3. Show User Details";
                    cout << endl
                         << "4. Update Mobile no.";
                    cout << endl
                         << "5. Exit" << endl;
                    cin >> choice; // taking user choice

                    switch (choice)
                    {
                    case 1:

                        cout << "your account balance is: " << user1.getbalance();
                        // getting balanc from user

                        _getch();
                        break;

                    case 2:

                        cout << "enter the amount : ";
                        cin >> amount;
                        user1.cashwithDraw(amount);
                        _getch();
                        break;

                    case 3:

                        cout << endl
                             << "*****user details****** ";
                        cout << endl
                             << "-> account no" << user1.getAccountNo();
                        cout << endl
                             << "-> name" << user1.getName();
                        cout << endl
                             << "->Balance :" << user1.getbalance();

                        cout << endl
                             << "-> Mobile no: " << user1.getMobile_no();
                        _getch();
                        break;

                    case 4:
                        cout << endl
                             << "enter your old monbile no:";
                        cin >> oldmobileno;

                        cout << endl
                             << "enter your new mobile no: ";
                        cin >> newmobileno;

                        user1.setMobileNo(oldmobileno, newmobileno);
                        break;

                    case 5:

                        exit(0);

                    default: // handle invalid user inputs

                        cout << endl
                             << "Enter Valid Data !!!";
                        _getch();
                    }
                } while (1);
            }

            else
            {

                cout << endl
                     << "User Details are Invalid !!! ";
                _getch();
            }
        } while (1);

        return 0;
    }
