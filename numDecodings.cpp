#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int numDecodings(string s) {
	if(s.empty()) return 0;
	if(s.length() == 1) return 1;
	int len = s.length();
	int tt = 0;
	if((s[len-2]-'0') * 10 + (s[len-1]-'0') <= 26) {
		tt = numDecodings(s.substr(0, len-2));
		if(tt == 0)
			++tt;
	}
	int ss = numDecodings(s.substr(0, len-1));
	cout << s << ": " << tt << " " << ss << endl;
	return tt > 0 ? tt+ss : ss;
}

int numDecodings2(string s) {
	int n = s.length();
	if(n <= 0 || s[0] == '0') return 0;
	int d[n+1];
	memset(d, 0, sizeof(d));
	d[0] = d[1] = 1;
	for(int i = 1; i < n; ++i) {
		if(s[i] != '0')
			d[i+1] += d[i];
		if(s[i-1]=='1' || (s[i-1]=='2' && s[i] <= '6'))	
			d[i+1] += d[i-1];
	}
	return d[n];
}

int main() {
	string s = "123";
	cout << numDecodings2(s) << endl;
	return 0;
}
