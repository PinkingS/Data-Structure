#include <string>
#include <vector>
#include <iostream>
using namespace std;

void restoreIpAddress(string &s, string &ip, int deep, int start, vector<string> &res) {
	if(deep == 4 && start == s.size()) {
		res.push_back(ip);
		return;
	}
	if(deep == 4) return;

	int num = 0, origionSize = ip.size();
	if(start != 0) ip.push_back('.');
	for(int i = start; i < start+3 && i < s.size(); ++i) {
		num = num*10 + (s[i]-'0');
		if(num > 255) break;
		ip.push_back(s[i]);
		restoreIpAddress(s, ip, deep+1, i+1, res);
		if(num == 0) break;
	}
	ip.resize(origionSize);
}

vector<string> restoreIpAddress(string s) {
	vector<string> res;
	int len = s.length();
	if(len < 4 || len > 12) return res;
	string ip;
	restoreIpAddress(s, ip, 0, 0, res);
	return res;
}

int main() {
	string s = "25525511135";
	vector<string> res = restoreIpAddress(s);
	for(int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	return 0;
}
