#include <iostream>
using namespace std;

int main(){
	int number;
	cout << "Enter an integer: ";	
	cin >> number;
	if (number % 2 == 0) {
		cout << number << " is an even number";
	}
	else {
		cout << number << " is an odd number";
	}

	return 0;
}

