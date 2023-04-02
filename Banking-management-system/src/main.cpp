#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>

void clear_screen();

struct details
{
	std::string Fname, Lname;
	int Day,Month,Year; //dob
	std::string city, country;
	int contact;
	std::string password, confrm_pass;
	char gender;

};


class account
{
private:
    std::string name = "null";
    int balance = 0, withdraw, deposit;
    std::string pin = "";
    char ch;

public:

    void CreateAccount();
    void ChangePin();
    void PrintBalance();
    void AddMoney();
    void WithdrawMoney();

};


void account::CreateAccount()
    {
	    details Det;
	    int month_check, numdays;



	    // Should rewrite this function
	    std::cout << "Create New account" << std::endl; 
	    std::cout << "Enter first name: ";
	    std::cin >> Det.Fname; 
	    std::cout << "Enter last name: ";
	    std::cin >> Det.Lname;
	    std::cout << "Enter mobile No: +254 7";
	    std::cin >> Det.contact;
	    std::cout << "Date of Birth: \n";
Y:
	    std::cout << "\t      Year: ";
	    std::cin >> Det.Year;
	    if (Det.Year >= 1923 && Det.Year <= 2013) {
M:
		    std::cout << "\t      Month: ";
		    std::cin >> Det.Month;

		    if (Det.Month <= 12 && Det.Month > 0) {
D:
			    std::cout << "\t      Day: ";
			    std::cin >> Det.Day;



		    switch (Det.Month) {
			    case 2:
				    if (Det.Year % 4 == 0 && (Det.Year % 100 != 0 || Det.Year % 400 == 0)) {
					numdays = 29; // Leap year
				    } else {
					numdays = 28;
				    }
				  break;
			    case 4:
			    case 6:
			    case 9:
			    case 11:
				    numdays = 30;
				    break;
			    default:
				    numdays = 31;
				    break;
		    }


		    if (Det.Day <= numdays ) {
		    
		    }else {
			    goto D;
		    }

	    }else {
		    goto M;
	    }
	} else {
		goto Y;
	}



    }

void account::ChangePin()
    {
        if (name != "null")
        {
            std::string extpin = "";
            clear_screen();
            std::cout << "-----------------------" << std::endl;
            std::cout << "\nEnter your existing pin :- ";
            while ((ch = getch()) != '\r')
            {
                if (ch == '\b')
                {
                    if (extpin.length() > 0)
                    {
                        extpin.pop_back();
                        std::cout << "\b \b";
                    }
                }
                else
                {
                    extpin.push_back(ch);
                    std::cout << "*";
                }
            }

            if (extpin == pin)
            {
                std::cout << "\nEnter New Pin :- ";
                pin = "";
                while ((ch = getch()) != '\r')
                {
                    if (ch == '\b')
                    {
                        if (pin.length() > 0)
                        {
                            pin.pop_back();
                            std::cout << "\b \b";
                        }
                    }
                    else
                    {
                        pin.push_back(ch);
                        std::cout << "*";
                    }
                }

                std::cout << "\n***** Pin Changed succesfully *****" << std::endl;
                std::cout << "\n-----------------------" << std::endl;
                system("pause");
            }
            else
            {
                clear_screen();
                std::cout << "-----------------------" << std::endl;
                std::cout << "\nPin does not match please try again" << std::endl;
                std::cout << "\n-----------------------" << std::endl;
                system("pause");
            }
        }
        else
        {
            clear_screen();
            std::cout << "-----------------------" << std::endl;
            std::cout << "\nNo Account has been created yet \n First Create one account" << std::endl;
            std::cout << "\n-----------------------" << std::endl;
            system("pause");
        }
    }

void account::PrintBalance()
    {
        if (name != "null")
        {
            clear_screen();
            std::cout << "-----------------------" << std::endl;
            std::cout << "\nAccount Holder Name :- " << name << std::endl;
            std::cout << "Your Savings Account Balance is :- " << balance << " Rupees " << std::endl;
            std::cout << "\n-----------------------" << std::endl;
            system("pause");
        }
        else
        {
            clear_screen();
            std::cout << "-----------------------" << std::endl;
            std::cout << "\nNo Account has been created yet \n First Create one account" << std::endl;
            std::cout << "\n-----------------------" << std::endl;
            system("pause");
        }
    }

void account::AddMoney()
    {
        if (name != "null")
        {
            clear_screen();
            std::cout << "-----------------------" << std::endl;
            std::cout << "\nHow much money do you want to add :- ";
            std::cin >> deposit;
            std::cin.ignore();
            balance = balance + deposit;

            std::cout << "\n$ " << deposit << " has been added to your account " << std::endl;
            std::cout << "\n-----------------------" << std::endl;
            system("pause");
        }
        else
        {
            clear_screen();
            std::cout << "-----------------------" << std::endl;
            std::cout << "\nNo Account has been created yet \n First Create one account" << std::endl;
            std::cout << "\n-----------------------" << std::endl;
            system("pause");
        }
    }

void account::WithdrawMoney()
    {
        std::string extpin = "";

        if (name == "null")
        {
            clear_screen();
            std::cout << "-----------------------" << std::endl;
            std::cout << "\nNo Account has been created yet \n First Create one account" << std::endl;
            std::cout << "\n-----------------------" << std::endl;
            system("pause");
        }

        else
        {
            clear_screen();
            std::cout << "-----------------------" << std::endl;
            std::cout << "\n Enter your pin :- ";
            while ((ch = getch()) != '\r')
            {
                if (ch == '\b')
                {
                    if (extpin.length() > 0)
                    {
                        extpin.pop_back();
                        std::cout << "\b \b";
                    }
                }
                else
                {
                    extpin.push_back(ch);
                    std::cout << "*";
                }
            }
            std::cout << "\n-----------------------" << std::endl;

            if (name != "null" && extpin == pin)
            {
                clear_screen();
                std::cout << "-----------------------" << std::endl;
                std::cout << "\nHow much money do you want to withdraw :- ";
                std::cin >> withdraw;
                std::cin.ignore();

                if (withdraw <= balance)
                {
                    balance = balance - withdraw;
                    std::cout << "\nRupees " << withdraw << " has been withdrawn from your account " << std::endl;
                }
                else
                {
                    std::cout << "\n***** Not Enough money in account ***** \nDo you want to take Loan :)" << std::endl;
                }
                std::cout << "\n-----------------------" << std::endl;
                system("pause");
            }
            if (name != "null" && extpin != pin)
            {
                clear_screen();
                std::cout << "-----------------------" << std::endl;
                std::cout << "\nPin does not match please try again" << std::endl;
                std::cout << "\n-----------------------" << std::endl;
                system("pause");
            }
        }
    }


int main()
{
    int choice;
    account obj;

    do
    {
        clear_screen();

        std::cout << "-----------------------" << std::endl;
        std::cout << " Welcome to OpenSource's ATM Banking" << std::endl;
        std::cout << "-----------------------" << std::endl;

        std::cout << "\n-----------------------" << std::endl;
        std::cout << "\nChoose option by pressing option number eg.1,2,3.." << std::endl;

        std::cout << "1.Open a Savings Account" << std::endl;
        std::cout << "2.Change Pin of your Savings Account" << std::endl;
        std::cout << "3.Show Balance in Savings Account" << std::endl;
        std::cout << "4.Add Money to Savings Account" << std::endl;
        std::cout << "5.Withdraw Money form Savings Account" << std::endl;

        std::cout << "6.Logout & Exit" << std::endl;
        std::cout << "\n-----------------------" << std::endl;

        std::cout << "\n>>";
        std::cin >> choice;
        std::cin.ignore();

	switch (choice) {
	
		case 1:
		    obj.CreateAccount();
		    break;
		case 2:
		    obj.ChangePin();
		    break;

		case 3:
		    obj.PrintBalance();
		    break;

		case 4:
		    obj.AddMoney();
		    break;
		case 5:
		    obj.WithdrawMoney();
		    break;
		default:
		    std::cout << "Choose from 1-5";

	}

    } while (choice == 0);

    clear_screen();
    std::cout << "-----------------------" << std::endl;
    std::cout << "\nThank you for trying this program" << std::endl;
    std::cout << "\n-----------------------" << std::endl;
    system("pause");
    return 0;
}


void clear_screen()
{
#ifdef WINDOWS
	std::system ("cls");
#else 
	std::system("clear");
#endif
}
