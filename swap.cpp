#include <iostream>
using namespace std;

int main(){
	cout << "Enter two numbers: ";
	int num1, num2, temp;
	cin >> num1 >> num2;
	cout << "Before change ";
	cout << "first number: "<< num1 << "\n Second number: "<< num2;

	temp = num1;
	num1 = num2;
	num2 = temp;
	cout << "\n\n After change ";
	cout << "first number: "<< num1 << "\n Second number: "<< num2;

	return 0;
}


	
