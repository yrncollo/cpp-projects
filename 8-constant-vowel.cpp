#include <cctype>
#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
	char character;
	cout << " Enter a character: ";
	cin >> character;
	if (character == 'a' || character =='e' || character =='i' || character =='o' || character =='u') {
		cout << character << " is a vowel.";	
	}
	else if (isdigit(character) ) {
		cout << " this is a number";
	}
	else {
		cout << character << " is a consonant";
	
	}
	return 0;
}
