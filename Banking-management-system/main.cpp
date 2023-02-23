#include <iostream>
void welcome();

int main()
{

	welcome();

	return 0;
}

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
	
	
}
