/*
Given a set of 7 letter tiles and a word, determine whether you can make the given word using the given tiles.

*/

#include <iostream>   
#include <string>  

using namespace std;  

bool scrabble(string first_string, string second_string);  
int main()  
{  
    string word1 = "pizza??";  
    string word2 = "pizzazz";  
    bool result;  

    result = scrabble(word1, word2);  

    if (result == true)  
        cout << "true" << endl;  
    else  
        cout << "false" << endl;  
    return 0;  
}  

bool scrabble(string first_string, string second_string) {  

    string first = first_string;  
    string second = second_string;  
    int count = 0;  
    int wildcard_count = 0;  

    for (size_t i = 0; i < second.length(); i++) {  
        for (size_t y = 0; y < first.length(); y++) {  
            if (first[y] == second[i])   
                first[y] = '0';  
            cout << first << endl;  
            }  
        }  
    for (size_t z = 0; z < first.length(); z++) {  
        if (first[z] == '0')  
            count++;  
        if (first[z] == '?')  
            wildcard_count++;  
    }  
    cout << count << endl;    

    if (count == second.length())  
        return true;  
    else if (wildcard_count + count >= second.length())  
        return true;  
    else  
        return false;  
    }  
