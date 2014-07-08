#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void duplicateSubString(string s) {
	if(s.empty()) {
		cout << "the input string is empty" << endl;
		return;
	}
	
	int maxLen = 0;
	int startIndex = 0;
	for(int inc = 1; inc < s.length(); ++inc) {
		int len = 0;
		for(int i = 0; i < s.length() - inc; ++i) {
			if(s[i] == s[i+inc])
				++len;
			else
				len = 0;
			if(len > maxLen) {
				maxLen = len;
				startIndex = i - len + 1;
			}
		}
	}
	
	for(int i = 0; i < maxLen; ++i)
		cout << s[startIndex + i];
	cout << endl;
	return ;
}

int compareStr(string a, string b) {
	return a < b;
}

int commonLen(string a, string b) {
	int len = 0;
	int i = 0;
	while(a[i] && b[i] && a[i] == b[i]) {
		++len;
		++i;
	}
	return len;
}

void longestRepeatSubstring(string s) {
	vector<string> suffix;

	for(int i = 0; i < s.length(); ++i) {
		string substr = s.substr(i);
		suffix.push_back(substr);
	}
	sort(suffix.begin(), suffix.end(), compareStr);
	int maxLen = 0, startIndex = 0;
	for(int i = 0; i < s.length()-1; ++i) {
		int len = commonLen(suffix[i], suffix[i+1]);
		if(len > maxLen) {
			maxLen = len;
			startIndex = i;
		}
	}
	cout << suffix[startIndex].substr(0, maxLen) << endl;
}


int main() {
	string test1 = "ababa";
	longestRepeatSubstring(test1);
	string test2 = "abcdabcabcdeff";
	longestRepeatSubstring(test2);

	string a = "1234";
	string b = "2345";
	
	cout << (a>b) << endl;

	string ss = "12345";
	cout << ss.substr(1) << endl;
	return 0;
}
