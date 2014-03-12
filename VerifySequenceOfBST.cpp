#include <cstdio>
#include <iostream>
using namespace std;

bool VerifySequenceOfBST(int sequence[], int length) {
	if(sequence == NULL || length <= 0)
		return false;
		
	int root = sequence[length-1];
//cout << "root: " << root<< endl;
	//find left part
	int i;
	for(i = 0; i < length-1; ++i) {
		if(sequence[i] > root)
			break;
	}
	
	//find right part
	int j;
	for(j = i; j < length-1; ++j) {
		if(sequence[j] < root)
			return false;
	}

	bool left = true;
	if(i > 0)
		left = VerifySequenceOfBST(sequence, i);
//cout << "left part from " << sequence[0] << " to " << sequence[i-1] << endl;
	bool right = true;
	if(i < length - 1)
		right = VerifySequenceOfBST(sequence + i, length - i -1);
//cout << "right part from " << sequence[i] << " to " << sequence[length-i-2] << endl;
	
	return left && right;
}

int main() {
	int A[7] = {5, 7, 6, 9, 11, 10, 8};
	int B[4] = {7, 4, 5, 6};
	printf("%d\n",VerifySequenceOfBST(A, 7));
	printf("%d\n",VerifySequenceOfBST(B, 4));
	return 0;
}
