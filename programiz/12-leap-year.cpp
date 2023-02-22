#include <iostream>
using namespace std ;

int main(){
	int year;
	cout << "Kindly enter a year: ";
	cin >> year;
	if (year % 4 == 0) {
		cout << year << " is a leap year.";
	
	}
	else {
	cout << "The year ain't a leap year";
	}

	return 0;
}
