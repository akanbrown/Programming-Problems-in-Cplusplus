#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool customCompare(const string& a, const string& b) {
    int a_index = 0, b_index = 0;
    while(a[a_index] == b[b_index]) {
        a_index++;
        b_index++;
        if(a_index == a.size()) a_index = 0;
        if(b_index == b.size()) b_index = 0;
        if(a_index == 0 && b_index == 0)
            return(a < b);
    }
    return(a[a_index] < b[b_index]);
}


int main() {
    string line, buffer;

    while(getline(cin, line)) {

        vector<string> list;
        stringstream ss(line);
        while(ss >> buffer)
            list.push_back(buffer);
        sort(list.begin(), list.end(), customCompare);

        for(int i = 0; i < list.size(); i++)
            cout << list[i];
        cout << " - ";
        for(int i = list.size()-1; i >= 0; i--)
            cout << list[i];
        cout << endl;
    }
    return 0;
}
