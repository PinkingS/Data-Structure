#include <iostream>
using namespace std;

bool Find(int* matrix, int rows, int columns, int num) {
	if(matrix == NULL)
		return false;
	if(num > matrix[rows*columns-1] || num < matrix[0])
		return false;
	int row = 0;
	int col = columns-1;
	int tmp;
	while(row != rows || col != 0) {
		tmp = matrix[row * columns + col];
		cout << "row: " << row << " col: " << col << " tmp: " << tmp << endl;
		if(tmp == num)
			return true;
		if(num > tmp)
			++row;
		else if(num < tmp)
			--col;
	}
	return false;
}

int main() {
	int a[16] = {	1, 2, 8, 9,
					2, 4, 9, 12,
					4, 7, 10, 13,
					5, 8, 11, 15};
	cout << Find(a, 4, 4, 9) << endl;
	cout << Find(a, 4, 4, 8) << endl;
	cout << Find(a, 4, 4, 6) << endl;
	return 0;
}
