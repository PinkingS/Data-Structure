#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateParenRe(vector<string> &res, int left, int right, string s) {
	if(left == 0 && right == 0) {
		res.push_back(s);
		return;
	}
	if(left > 0)
		generateParenRe(res, left-1, right, s+'(');
	if(right > left)
		generateParenRe(res, left, right-1, s+')');
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	if(n <= 0) return res;
	generateParenRe(res, n, n, "");
	return res;
}

int main() {
	int n = 3;
	vector<string> res = generateParenthesis(n);
	for(int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	return 0;
}
