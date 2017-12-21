/*
Implement an algorithm to determine if a string has all unique characters
*/
#include <iostream>
#include <string>

using namespace std;

//prototype
bool uniqueCharacters(string);

int main() {
	string str1;

	cout << "Enter a string: " << endl;
	cin >> str1;

	if (uniqueCharacters(str1)) {
		cout << "The String \"" << str1 << "\" has all unique characters\n";
	}
	else {
		cout << "The String \"" << str1 << "\" does not have all unique characters\n\n";
	}

	system("pause");
	return 0;
}

bool uniqueCharacters(string str) {
	//return false if two characters the same
	for (int i = 0; i < str.length(); i++) {
		for (int j = i + 1; j < str.length(); j++) {
			if (str[i] == str[j]) {
				return false;
			}
		}
	}

	return true; //no duplicates encountered
}

