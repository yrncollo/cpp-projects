#include <iostream>
#include <string>

#include "main.h"


void welcome()
{
	std::cout << "\t\t|-----------------------------------------------|" << "\n";
	std::cout << "\t\t|                                               |" << "\n"; 
	std::cout << "\t\t|     WELCOME TO YRNCOLLO BANKING SYSTEM        |" << "\n";
	std::cout << "\t\t|                                               |" << "\n"; 
	std::cout << "\t\t|-----------------------------------------------|" << "\n";
	std::cout << "\t\t|\t Choose your option:\t                |" << "\n"; 
	std::cout << "\t\t|-----------------------------------------------|" << "\n";
	std::cout << "\t\t|                                               |" << "\n"; 
	std::cout << "\t\t|\t\t 1) ADMINISTRATOR               |" << "\n"; 
	std::cout << "\t\t|                                               |" << "\n"; 
	std::cout << "\t\t|\t\t 2) LOGIN                       |" << "\n"; 
	std::cout << "\t\t|                                               |" << "\n"; 
	std::cout << "\t\t|\t\t 3) EXIT                        |" << "\n"; 
	std::cout << "\t\t|-----------------------------------------------|" << "\n";

	int choice;
	std::cout << "\n\nEnter: ";
	std::cin >> choice;
	
	switch (choice) {
		case 1:
			administrator();
	
	}
	
}

void administrator()
{
	std::string admPassword;
	std::string admUsername ;
	std::cout << "Enter Administrator Username: ";
	std::cin >> admUsername;
	std::cout << "Enter the password: ";
	std::cin >> admPassword;
	if (admPassword == "WelcomeAdmin" && admUsername == "admin") {
	
		std::cout << "\n Login successful";
	}
	else {
		std::cout << "\n Username or Password is invalid";
	}

}
