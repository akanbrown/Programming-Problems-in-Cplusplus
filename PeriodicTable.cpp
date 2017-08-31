/*
Convert a normal word into a list of abbreviations from the periodic table, for example,
"ticklish" corresponds to "TiCKLiSH (titanium, carbon, potassium, lithium, sulfur, hydrogen)"
another example,
"poison" corresponds to "POISON (phosphorus, oxygen, iodine, sulfur, oxygen, nitrogen)"
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<string> atomicSymbols = { "Ac", "Al", "Am", "Sb", "Ar", "As",
        "At", "Ba", "Bk", "Be", "Bi", "B", "Br", "Cd", "Ca", "Cf", "C",
        "Ce", "Cs", "Cl", "Cr", "Co", "Cu", "Cm", "Dy", "Es", "Er", "Eu",
        "Fm", "F", "Fr", "Gd", "Ga", "Ge", "Au", "Hf", "He", "Ho", "H",
        "In", "I", "Ir", "Fe", "Kr", "La", "Lr", "Pb", "Li", "Lu", "Mg",
        "Mn", "Md", "Hg", "Mo", "Nd", "Ne", "Np", "Ni", "Nb", "N", "No",
        "Os", "O", "Pd", "P", "Pt", "Pu", "Po", "K", "Pr", "Pm", "Pa",
        "Ra", "Rn", "Re", "Rh", "Rb", "Ru", "Rf", "Sm", "Sc", "Se", "Si",
        "Ag", "Na", "Sr", "S", "Ta", "Tc", "Te", "Tb", "Tl", "Th", "Tm",
        "Sn", "Ti", "W", "U", "V", "Xe", "Y", "Yb", "Zn", "Zr" };

    string userInput;
    cout << "Enter a word to try to spell: ";
    getline(cin, userInput);

    //spelling logic
    string spellingAttempt = "";

    //two char logic
    for (unsigned int counter = 0; counter < userInput.length(); counter++) {
        char firstChar = userInput[counter];
        firstChar = toupper(firstChar);
        char secondChar;
        if (counter + 1 < userInput.length()) {
            secondChar = userInput[counter + 1];
        }
        else{
            secondChar = ' ';
        }
        string twoCharTest = string() + firstChar + secondChar;

        if (find(atomicSymbols.begin(), atomicSymbols.end(), twoCharTest) != atomicSymbols.end()) {
            spellingAttempt += string() + twoCharTest;
            counter++;
        }
        else{ //it does not match two char, try one char
            string oneCharTest = string() + firstChar;
            if (find(atomicSymbols.begin(), atomicSymbols.end(), oneCharTest) != atomicSymbols.end()) {
                spellingAttempt += string() + oneCharTest;
            }
        }
    }

    if (spellingAttempt.length() == userInput.length()) {
        cout << spellingAttempt << endl;
    }
    else{
        cout << "ERROR: Word cannot be made" << endl;
    }
}
