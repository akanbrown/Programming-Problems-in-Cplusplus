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
