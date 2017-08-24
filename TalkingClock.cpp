/*
Convert 24 hour numerical military time to words that people understand.
*/


#include <iostream>
#include <string>
using namespace std;

void clock(string s){
   int h = stoi(s.substr(0, 2));
   int m = stoi(s.substr(3));

   string ampm = "pm";
   if (h < 12) ampm = "am";

   string tens[] = {"oh ", "", "twenty ", "thirty ", "fourty ", "fifty "};
   string ones[] = {"twelve ", "one ", "two ", "three ", "four ", "five ",
                    "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ",
                    "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", 
                    "eighteen ", "nineteen "};

   if(m == 0){
       cout << "It's " << ones[h%12] << ampm << endl;
   }else if (m % 10 == 0){
       cout << "It's " << ones[h%12] << tens[m/10] << ampm << endl;
   }else if (m < 10 || m > 20){
        cout << "It's " << ones[h%12] << tens[m/10]<< ones[m%10] << ampm << endl;
   }else{
       cout << "It's " << ones[h%12] << ones[m] << ampm << endl;
   }
}

int main(){
     cout << "00:00" << clock("00:00") << endl;

}
