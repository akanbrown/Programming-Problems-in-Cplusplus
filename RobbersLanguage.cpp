/* Robber's Langauge */
/* Take an ordinary word and for each consonant 'x'
   in the word, replace the consonant with the following
   string: the consonant 'x' followed by the letter 'o' 
   followed by the consonant 'x'. 
   For example, the consonant b is replaced by the string 
   'bob' and the consonant 'r' is replaced by the string 'ror'.  */
   
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

/* list of consonants */
const string consonants = "bcsfghjklmnpqrstvwxyz";

bool isConsonant(const char c) {
    return consonants.find(c) != string::npos;
}

int main() {
    string line;
    getline(cin, line);

    for (const char c : line) {
        cout << c;

        const char l = tolower(c);

        if (isConsonant(l)) {
            cout << "o" << l;
        }
    }

    cout << endl;

    return 0;
}
