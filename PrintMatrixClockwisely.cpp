#include <cstdio>
#include <iostream>
using namespace std;

void PrintMatrixClockwisely(int** numbers, int column, int row) {
	int rowStart = 0, rowEnd = row-1;
	int colStart = 0, colEnd = column-1;

	for(int i = 0; i < row; ++i)
		for(int j = 0; j < column; ++j)
			printf("%d\t",numbers[i][j]);

	printf("\n");
	//cout << rowStart << "\t" << rowEnd << "\t" << colStart << "\t" << colEnd << endl;

	while((rowStart <= rowEnd) || (colStart <= colEnd)) {
		for(int i = colStart; i <= colEnd; ++i){
			printf("%d\t", numbers[rowStart][i]);
		}	
		rowStart++;
		for(int i = rowStart; i <= rowEnd; i++){
			printf("%d\t",numbers[i][colEnd]);
		}
		colEnd--;
		//break;
		for(int i = colEnd; i >= colStart; i--){
			printf("%d\t",numbers[rowEnd][i]);
		}
		rowEnd--;
		for(int i = rowEnd; i >= rowStart; i--){
			printf("%d\t", numbers[i][colStart]);
		}
		colStart++;
	//	cout << rowStart << "\t" << rowEnd << "\t" << colStart << "\t" << colEnd << endl;
	//	break;
	}
}

void Test(int column, int row) {
	if(column < 1 || row < 1)
		return;
	
	printf("Test(%d,%d) begins:\n",column, row);
	int** numbers = new int*[row];
	for(int i = 0; i < row; ++i) {
		numbers[i] = new int[column];
		for(int j = 0; j < column; ++j)
			numbers[i][j] = i * column + j + 1;
	}

	PrintMatrixClockwisely(numbers, column, row);
	printf("\n");
}

int main() {
	Test(4, 4);
	Test(1, 1);
	Test(2, 2);
	Test(1, 5);
	Test(4, 1);
	Test(2, 5);
	Test(5, 2);
	return 0;
}
