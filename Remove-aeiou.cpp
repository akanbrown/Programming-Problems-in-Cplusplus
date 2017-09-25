/*
Remove, then display, the vowels in a user supplied string.

----------------------------------------------------------
For example:

Input: The quick brown fox jumps over the lazy dog.

Output: Thqckbrwnfxjmpsvrthlzydg. 
        euioouoeeao
----------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

char vowels[5] = {'a','e','i','o','u'};

bool isVowel(char letter){

    for(int i=0;i<5;i++){
        if(letter==vowels[i]){
            return true;
         }
     }
return false;
}  

int main(void){

    string str,consStr,vowelStr;
    getline(cin,str);

    for(int i=0;i<str.length();i++){

            if(!isVowel(str[i]) && str[i]!=' '){
                 consStr+=str[i];
            }
            if(isVowel(str[i])){
                 vowelStr+=str[i];
            }
    }

    cout << consStr<<"\n"<<vowelStr<<endl;

return 0;

}
