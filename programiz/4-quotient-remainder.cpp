#include <iostream>
using namespace std;

int main(){
	int num, num2, reminder, quotient;
	cout << "Enter an integer: ";
	cin >> num >> num2;
	reminder = num % num2 ;
	quotient = num / num2;
	cout << "The reminder is: "<< reminder << " and the quotient is: " << quotient;
	return 0;
}
