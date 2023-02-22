//finding All Roots of a Quadratic Equation
//the formula is x = (-b ± √ (b2 - 4ac)) /2a
#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int a, b, c, xPositive, xNegative;
	cout << "Enter the values of a, b and c respectively: ";
	cin >> a >> b >> c;
	xPositive = (-b + sqrt(b*b -4*a*c)) / 2*a;
	xNegative = (-b - sqrt(b*b -4*a*c)) / 2*a;
	cout << xPositive << " and " << xNegative;

	return 0;
}
