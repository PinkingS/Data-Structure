#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> permutation(string s) {
	vector<string> res;
	if(s == "") {
		res.push_back("");
		return res;
	}

	string c = s.substr(0, 1);
	vector<string> per = permutation(s.substr(1));
	for(int i = 0; i < per.size(); ++i) {
		string tmp = per[i];
		for(int j = 0; j <= tmp.length(); ++j) {
			string u = tmp;
			u.insert(j, c);
			res.push_back(u);
		}
	}
	return res;
}

vector<string> permutation_2(string s) {
	vector<string> res;
	if(s == "") {
		res.push_back("");
		return res;
	}

	for(int i = 0; i < s.length(); ++i) {
		string c = s.substr(i, 1);
		string t = s;
		vector<string> per = permutation_2(t.erase(i, 1));
		for(int j = 0; j < per.size(); ++j) {
			res.push_back(c + per[j]);
		}
	}
	return res;
}

int main() {
	string s = "abc";
	vector<string> res = permutation_2(s);
	for(int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;

	return 0;
}
