#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
	return s1.length() > s2.length();
}

bool makeOfWords(string word, set<string> ss, int length) {
	int len = word.length();
	if(len == 0) return true;
	
	for(int i = 1; i <= len; ++i) {
		if(i == length) return false;
		string str = word.substr(0, i);
//cout << str << endl;
		if(ss.find(str) != ss.end()) {
			if(makeOfWords(word.substr(i), ss, length)) {
				//cout << word.substr(i) << endl;
				return true;
			}
		}
	}
	return false;
}

void printLongestWord(string text[], int len) {
	set<string> ss;
	for(int i = 0; i < len; ++i)
		ss.insert(text[i]);

	sort(text, text+len, cmp);

	for(int i = 0; i < len; ++i) {
		if(makeOfWords(text[i], ss, text[i].length())) {
			//cout << "true" << endl;
			cout << text[i] << endl;
			return;
		}
	}
}

int main() {
	string text[] = {
		"test", "tester", "testertest", "testing", "apple", 
		"banana", "seattle", "batting", "ngcat", "batti", 
		"bat", "testingtester", "testbattingaple" };
	int len = 13;
	printLongestWord(text, len);
	return 0;
}
