/*
Write a program to find the quickest path down the pyramid, for example:
  1
 2 3
4 5 6
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> layer(int remaining) {
    // read line, transform into a vector of ints representing the current row
    vector<int> cur;
    string input;
    int n;
    getline(cin, input);
    stringstream stream(input);
    while(stream >> n)
        cur.push_back(n);

    // retrieve the next row recursively if any are remaining
    if(remaining > 0) {
        vector<int> below = layer(remaining-1);
        // update curent row to include the least cost path
        for(int i = 0; i < cur.size(); i++) {
            if(below[i] < below[i+1])
                cur[i] += below[i];
            else
                cur[i] += below[i+1];
        }
    }
    /* prints out solved current row
    cout << "Remaining: " << remaining << "  [";
    for(int i = 0; i < cur.size(); i++) {
        cout << cur[i];
        if(i + 1 < cur.size())
            cout << ", ";
    }
    cout << "]" << endl;
    */
    return cur;
}

int main() {
    while(true) {
        // get rows in pyramid
        int n;
        string input;
        getline(cin, input);
        istringstream stream(input);
        stream >> n;

        if(n == 0) break;

        // call recursive function to get rows, parse, and solve
        vector<int> answer = layer(n-1);
        cout << answer[0] << endl << endl;
    }
    return 0;
}
