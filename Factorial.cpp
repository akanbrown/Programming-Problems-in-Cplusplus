#include <iostream>
#include <string>
using namespace std;

int factorial(int num){
    if ((num == 0) || (num == 1)) return 1;
    else {
        return (num * factorial(num - 1));
    }
}

int main()
{
	
	string number, userContinue;
	int userContinueInt;
	userContinueInt = 1;
	
	while (userContinueInt == 1)
	{
		cout << "Enter a number: " << endl;
		getline(cin, number);
		cout << "The factorial of " << number << " is " << factorial(stoi(number)) << endl;
		

		cout << "\nWould you like to compute another factorial? Enter \"yes\" or \"no\"\n" << endl;
		
		getline(cin, userContinue);

		if (userContinue == "yes") {
			userContinueInt = 1;
		}
		else if (userContinue == "no"){
			userContinueInt = 0;
		}
		else {
			cout << "Please enter \"yes\" or \"no\"" << endl;
		}

  	} 
		
	cout << "Thanks for playing." << endl;

	return 0;

}
