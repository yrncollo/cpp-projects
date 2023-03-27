#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>

using namespace std;

class account
{
private:
    string name = "null";
    int balance = 0, withdraw, deposit;
    string pin = "";
    char ch;

public:
    void CreateAccount()
    {
        if (name != "null")
        {
            system("cls");
            cout << "-----------------------" << endl;
            cout << "\nAccount has Already been created" << endl;
            cout << "\n-----------------------" << endl;
            system("pause");
        }

        else
        {
            system("cls");
            cout << "-----------------------" << endl;

            cout << "\nEnter your Full Name :- ";
            getline(cin, name);

            cout << "\nSet a Pin :- ";
            while ((ch = getch()) != '\r')
            {
                if (ch == '\b')
                {
                    if (pin.length() > 0)
                    {
                        pin.pop_back();
                        cout << "\b \b";
                    }
                }
                else
                {
                    pin.push_back(ch);
                    cout << "*";
                }
            }

            cout << "\n\n***** Account has been created succesfully *****" << endl;
            cout << "\n-----------------------" << endl;
            system("pause");
        }
    }

    void ChangePin()
    {
        if (name != "null")
        {
            string extpin = "";
            system("cls");
            cout << "-----------------------" << endl;
            cout << "\nEnter your existing pin :- ";
            while ((ch = getch()) != '\r')
            {
                if (ch == '\b')
                {
                    if (extpin.length() > 0)
                    {
                        extpin.pop_back();
                        cout << "\b \b";
                    }
                }
                else
                {
                    extpin.push_back(ch);
                    cout << "*";
                }
            }

            if (extpin == pin)
            {
                cout << "\nEnter New Pin :- ";
                pin = "";
                while ((ch = getch()) != '\r')
                {
                    if (ch == '\b')
                    {
                        if (pin.length() > 0)
                        {
                            pin.pop_back();
                            cout << "\b \b";
                        }
                    }
                    else
                    {
                        pin.push_back(ch);
                        cout << "*";
                    }
                }

                cout << "\n***** Pin Changed succesfully *****" << endl;
                cout << "\n-----------------------" << endl;
                system("pause");
            }
            else
            {
                system("cls");
                cout << "-----------------------" << endl;
                cout << "\nPin does not match please try again" << endl;
                cout << "\n-----------------------" << endl;
                system("pause");
            }
        }
        else
        {
            system("cls");
            cout << "-----------------------" << endl;
            cout << "\nNo Account has been created yet \n First Create one account" << endl;
            cout << "\n-----------------------" << endl;
            system("pause");
        }
    }

    void PrintBalance()
    {
        if (name != "null")
        {
            system("cls");
            cout << "-----------------------" << endl;
            cout << "\nAccount Holder Name :- " << name << endl;
            cout << "Your Savings Account Balance is :- " << balance << " Rupees " << endl;
            cout << "\n-----------------------" << endl;
            system("pause");
        }
        else
        {
            system("cls");
            cout << "-----------------------" << endl;
            cout << "\nNo Account has been created yet \n First Create one account" << endl;
            cout << "\n-----------------------" << endl;
            system("pause");
        }
    }

    void AddMoney()
    {
        if (name != "null")
        {
            system("cls");
            cout << "-----------------------" << endl;
            cout << "\nHow much money do you want to add :- ";
            cin >> deposit;
            cin.ignore();
            balance = balance + deposit;

            cout << "\nRupees " << deposit << " has been added to your account " << endl;
            cout << "\n-----------------------" << endl;
            system("pause");
        }
        else
        {
            system("cls");
            cout << "-----------------------" << endl;
            cout << "\nNo Account has been created yet \n First Create one account" << endl;
            cout << "\n-----------------------" << endl;
            system("pause");
        }
    }

    void WithdrawMoney()
    {
        string extpin = "";

        if (name == "null")
        {
            system("cls");
            cout << "-----------------------" << endl;
            cout << "\nNo Account has been created yet \n First Create one account" << endl;
            cout << "\n-----------------------" << endl;
            system("pause");
        }

        else
        {
            system("cls");
            cout << "-----------------------" << endl;
            cout << "\n Enter your pin :- ";
            while ((ch = getch()) != '\r')
            {
                if (ch == '\b')
                {
                    if (extpin.length() > 0)
                    {
                        extpin.pop_back();
                        cout << "\b \b";
                    }
                }
                else
                {
                    extpin.push_back(ch);
                    cout << "*";
                }
            }
            cout << "\n-----------------------" << endl;

            if (name != "null" && extpin == pin)
            {
                system("cls");
                cout << "-----------------------" << endl;
                cout << "\nHow much money do you want to withdraw :- ";
                cin >> withdraw;
                cin.ignore();

                if (withdraw <= balance)
                {
                    balance = balance - withdraw;
                    cout << "\nRupees " << withdraw << " has been withdrawn from your account " << endl;
                }
                else
                {
                    cout << "\n***** Not Enough money in account ***** \nDo you want to take Loan :)" << endl;
                }
                cout << "\n-----------------------" << endl;
                system("pause");
            }
            if (name != "null" && extpin != pin)
            {
                system("cls");
                cout << "-----------------------" << endl;
                cout << "\nPin does not match please try again" << endl;
                cout << "\n-----------------------" << endl;
                system("pause");
            }
        }
    }
};

int main()
{
    int u;
    account obj;

    do
    {
        system("cls");

        cout << "-----------------------" << endl;
        cout << " Welcome to Kunal's ATM Banking" << endl;
        cout << "-----------------------" << endl;

        cout << "\n-----------------------" << endl;
        cout << "\nChoose option by pressing option number eg.1,2,3.." << endl;

        cout << "1.Open a Savings Account" << endl;
        cout << "2.Change Pin of your Savings Account" << endl;
        cout << "3.Show Balance in Savings Account" << endl;
        cout << "4.Add Money to Savings Account" << endl;
        cout << "5.Withdraw Money form Savings Account" << endl;

        cout << "6.Logout & Exit" << endl;
        cout << "\n-----------------------" << endl;

        cout << "\n>>";
        cin >> u;
        cin.ignore();

        if (u == 1)
        {
            obj.CreateAccount();
        }

        if (u == 2)
        {
            obj.ChangePin();
        }

        if (u == 3)
        {
            obj.PrintBalance();
        }

        if (u == 4)
        {
            obj.AddMoney();
        }

        if (u == 5)
        {
            obj.WithdrawMoney();
        }

    } while (u != 6);

    system("cls");
    cout << "-----------------------" << endl;
    cout << "\nThank you for trying this program" << endl;
    cout << "\n-----------------------" << endl;
    system("pause");
    return 0;
}
