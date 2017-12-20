#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s1, string s2);

int main() {
	string s1, s2;
	cout << "Input two strings." << endl;
	cin >> s1 >> s2;
	cout << s1 << " and " << s2;

	if (isAnagram(s1, s2))
		cout << " are anagrams." << endl;
	else
		cout << " are NOT anagrams." << endl;
	system("pause");
	return 0;

}

bool isAnagram(string s1, string s2) {
	char allChars[256] = { 0 };
	for (int i = 0; i < s1.length(); i++) allChars[s1[i]]++;
	for (int j = 0; j < s2.length(); j++) allChars[s2[j]]--;
	for (int k = 0; k < 256; k++) if (allChars[k] != 0) return false;
	return true;
}
