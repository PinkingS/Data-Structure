#include <string>
#include <iostream>
#include <vector>
using namespace std;

	string mapping[] = {
		"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};



void letterCombinationsRe(string &digits, string &com, int start, vector<string> &res) {
	if(start == digits.length()) {
		res.push_back(com);
		return;
	}
	string numbers = mapping[digits[start] - '2'];
	for(int i = 0; i < numbers.length(); ++i) {
		com.push_back(numbers[i]);
		letterCombinationsRe(digits, com, start+1, res);
		com = com.substr(0, com.length()-1);
	} 
}

vector<string> letterCombinations(string digits) {
	vector<string> res;
	if(digits.length() == 0) return res;
	string com;
	letterCombinationsRe(digits, com, 0, res);
}

int main() {
	string digits = "23";
	vector<string> res = letterCombinations(digits);
	for(int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	return 0;
}
