//
//A Game of Threes
//
//First, you generate a large, random number. Then, If the number 
//is divisible by 3, divide it by 3. If the number is not divisible 
//by 3, you add or subtract 1 (to make it divisible by 3) and then 
//you divide it by 3. The game stops when you reach "1".
//

#include <iostream>
using namespace std;
int main()
{
    bool finished = false;
    int n;
    cin >> n;
    while (!finished)
    {
        if (n == 1)
        {
            finished = true;
        }
        else
        {
            cout << n << " ";

            if (n % 3 == 0)
            {
                n = n / 3;
                cout << "0";
            }
            else
            {
                if ((n + 1) % 3 == 0)
                {
                    n = n + 1;
                    n = n / 3;
                    cout << "1";
                }
                else
                {
                    n = n - 1;
                    n = n / 3;
                    cout << "-1";
                }
            }
            cout << endl;
        }
    }
    cout << n;
    return 0;
}
