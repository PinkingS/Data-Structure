#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

bool isValid(vector<vector<char> > &board, int a, int b) {
	int i, j;
	for(i = 0; i < 9; ++i)
		if(i != a && board[i][b] == board[a][b])
			return false;

	for(j = 0; j < 9; ++j)
		if(j != b && board[a][j] == board[a][b])
			return false;

	int x = a/3*3;
	int y = b/3*3;
	for(i = x; i < x+3; ++i)
		for(j = y; j < y+3; ++j)
			if(i != a && j != b && board[i][j] == board[a][b])
				return false;

	return true;
}

bool solveSudokuDFS(vector<vector<char> > &board, int start) {
	for(int i = start; i < 81; ++i) {
		int x = i/9;
		int y = i%9;
		if(board[x][y] == '.') {
			for(int k = 1; k <= 9; ++k) {
				board[x][y] = k+'0';
				if(isValid(board, x, y) && solveSudokuDFS(board, i+1))
					return true;
				board[x][y] = '.';
			}
			return false;
		}
	}
	return true;
}

void solveSudoku(vector<vector<char> > &board) {
	solveSudokuDFS(board, 0);
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

	solveSudoku(board);

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}	

	return 0;
}

