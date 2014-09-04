#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
	bool used[10];
	for(int i = 0; i < 9; ++i) {
		memset(used, false, sizeof(used));
		for(int j = 0; j < 9; ++j) {
			if(board[i][j] != '.') {
				if(used[board[i][j]-'0'])
					return false;
				used[board[i][j]-'0'] = true;
			}
		}
	}

	for(int j = 0; j < 9; ++j) {
		memset(used, false, sizeof(used));
		for(int i = 0; i < 9; ++i) {
			if(board[i][j] != '.') {
				if(used[board[i][j]-'0'])
					return false;
				used[board[i][j]-'0'] = true;
			}
		}
	}

	for(int board_x = 0; board_x < 3; ++board_x)
		for(int board_y = 0; board_y < 3; ++board_y) {
			memset(used, false, sizeof(used));
			for(int i = board_x * 3; i < board_x * 3 + 3; ++i) {
				for(int j = board_y * 3; j < board_y * 3 + 3; ++j) {
					if(board[i][j] != '.') {
						if(used[board[i][j]-'0'])
							return false;
						used[board[i][j]-'0'] = true;
					}
				}
			}
		}
	return true;
}

int main() {	
	freopen("sudokuSolver.in", "r", stdin);
	int m,n;
	cin >> m >> n;
	vector<vector<char> > board;
	vector<char> row;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			char num;
			cin >> num;
			row.push_back(num);
		}
		board.push_back(row);
		row.clear();
	}

	cout << isValidSudoku(board) << endl;
	return 0;
}
