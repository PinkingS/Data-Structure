#include <iostream>
using namespace std;

void totalNQueensRe(int n, int row, int ld, int rd, int &res) {
	if(row == (1 << n)-1) {
		++res;
		return;
	}

	int avail = ~(row | ld | rd);
	for(int i = n-1; i >= 0; --i) {
		int pos = 1 << i;
		if(avail & pos) {
			totalNQueensRe(n, row|pos, (ld|pos)>>1, (rd|pos)<<1, res);
		}
	}
}

int totalNQueens(int n) {
	int res = 0;
	totalNQueensRe(n, 0, 0, 0, res);
	return res;	
}

int main() {
	int n = 4;
	cout << totalNQueens(n) << endl;
	return 0;
}
