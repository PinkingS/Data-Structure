#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

//reverse clock rotate image
// if for clock rotete image, row tranverse first, then diagonal tranverse
void rotateImage(int A[][4], int N) {
	for(int i = 0; i < N; ++i)
		for(int j = i+1; j < N; ++j)
			swap(A[i][j], A[j][i]);
	for(int i = 0; i < N/2; ++i)
		for(int j = 0; j < N; ++j)
			swap(A[i][j], A[N-1-i][j]);
}

int main(){
	int N = 4;
	int A[][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			cout << A[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	rotateImage(A, N);
	for(int i = 0; i < N; ++i){	
		for(int j = 0; j < N; ++j)
			cout << A[i][j] << " ";
		cout << endl;
	}
	return 0;
}
