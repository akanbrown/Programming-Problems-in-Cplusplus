/*
Program to check if the letters of a word are in order:
almost IN ORDER
hello NOT IN ORDER
boss IN ORDER
college NOT IN ORDER
big IN ORDER
*/

#include <string>
#include <iostream>

using namespace std;

bool leq(char a, char b) {
    return a <= b;
}

bool geq(char a, char b) {
    return a >= b;
}

bool ordered (string str, bool(*func)(char, char)) {
    for (unsigned int i = 0; i < str.size() - 1; ++i) {
        if (!func(str[i], str[i+1])) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;

    while(cin >> str) {

        if (ordered(str, leq)) {
            cout << str << " IN ORDER\n";
        }
        else if (ordered(str, geq)) {
            cout << str << " REVERSE ORDER\n";
        }
        else {
            cout << str << " NOT IN ORDER\n";
        }
    }
    return 0;
}
