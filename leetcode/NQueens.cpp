#include <iostream>
#include <vector>
#include <string>
using namespace std;

void NQueensRe(int n, int row, int ld, int rd, vector<string> &sol, vector<vector<string> > &res) {
	if(row == (1 << n)-1) {
		res.push_back(sol);
		return;
	}

	int avail = ~(row | ld | rd);
	for(int i = n-1; i >= 0; --i) {
		string s(n, '.');
		int pos = 1 << i;
		if(pos & avail) {
			s[n-1-i] = 'Q';
			sol.push_back(s);
			NQueensRe(n, row|pos, (ld|pos)<<1, (rd|pos)>>1, sol, res);
			sol.pop_back();
		}
	}
}

vector<vector<string> > NQueens(int n) {
	vector<vector<string> > res;
	if(n <= 0) return res;
	vector<string> sol;
	NQueensRe(n, 0, 0, 0, sol, res);
	return res;
}

int main() {
	vector<vector<string> > res = NQueens(4);
	for(int i = 0; i < res.size(); ++i) {
		for(int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << endl;
		cout << endl;
	}
	return 0;
}
