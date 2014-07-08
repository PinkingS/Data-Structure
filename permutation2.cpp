#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void permutationRe(string &s, string &per, vector<bool> &used) {
	if(per.length() == s.length()) { // find a permutation
		cout << per << endl;
		return;
	}

	for(int i = 0; i < s.length(); ++i) {
		if(!used[i]) {
			int orignLen = per.length();
			per += s[i];
			used[i] = true;
			permutationRe(s, per, used);
			per.resize(orignLen);
			used[i] = false;

			while(s[i+1] == s[i]) // avoid duplicate permutation 
				++i;
		}
	}
}


void permutation(string s) {
	if(s.empty()) {
		cout << "the input string is empty" << endl;
		return;
	}
	string per = "";
	vector<bool> used(s.length(), false);
	sort(s.begin(), s.end());
	permutationRe(s, per, used);
	return;
}

int main() {
	string s = "";
	permutation(s);
	return 0;
}
