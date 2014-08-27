#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 20;
int matrix[MAX_N][MAX_N];

struct SubSquare {
	int col, row, size;
};

inline int max(int a, int b) {
	return a > b ? a : b;
}

bool isSquare(int row, int col, int size) {
	for(int i = 0; i < size; ++i) {
		if(matrix[row][col+i] == 1)
			return false;
		if(matrix[row+size-1][col] == 1)
			return false;
		if(matrix[row+i][col] == 1)
			return false;
		if(matrix[row+i][col+size-1] == 1)
			return false;
	}
	return true;
}

SubSquare findSubSquare(int n) {
	int max_size = 0;
	SubSquare sq;
	int col = 0;
	while(n - col > max_size) {
		for(int row = 0; row < n; ++row) {
			int size = n - max(col, row);
			while(size > max_size) {
				if(isSquare(row, col, size)) {
					max_size = size;
					sq.row = row;
					sq.col = col;
					sq.size = size;
					break;
				}
				--size;
			}
		}
		++col;
	}
	return sq;
}

int main() {
	freopen("18.11.in", "r", stdin);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> matrix[i][j];
	SubSquare sq = findSubSquare(n);
	cout << "top " << sq.row << endl;
	cout << "bottom " << sq.row+sq.size-1 << endl;
	cout << "left " << sq.col << endl;
	cout << "right " << sq.col+sq.size-1 << endl;
	fclose(stdin);
	return 0; 
}
