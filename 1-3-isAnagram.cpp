#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

bool isAnagram(string s1, string s2) {
	if(s1.length() != s2.length())
		return false;
	int len = s1.length();
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if(s1 == s2)
		return true;
	else
		return false;
}

bool isAnagram2(string s1, string s2) {
	if(s1.length() != s2.length())
		return false;

	int check[256];
	memset(check, 0, sizeof(check));

	int len = s1.length();
	for(int i = 0; i < len; ++i) {//calculate numbers of characters
		++check[(int)s1[i]];
		--check[(int)s2[i]];
	}

	for(int i = 0; i < 256; ++i) {
		if(check[i] != 0)
			return false;
	}
	return true;
}

int main() {
	string s1 = "aabcdett";
	string s2 = "etdctsba";
	cout << isAnagram2(s1, s2) << endl;
	cout << s1 << endl;
	cout << *s2.begin() << endl;
	return 0;
}
