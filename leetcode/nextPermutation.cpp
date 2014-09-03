#include <vector>
#include <iostream>
using namespace std;

void nextPermutation(vector<int> &num) {
	int excNum = 0, excIdx = 0;
	for(int i = num.size()-1; i > 0; --i) {
		if(num[i] > num[i-1]) {
			excNum = i-1;
			excIdx = i;
			break;
		}
	}
	
	for(int i = num.size()-1; i > excNum; --i) {
		if(num[i] > num[excNum]) {
			swap(num[i], num[excNum]);
			break;
		}
	}

	int i = excIdx, j = num.size()-1;
	while(i < j) {
		swap(num[i], num[j]);
		++i;
		--j;
	}
}

int main() {
	int a[] = {5, 2, 4, 3, 1};
	int b[] = {5, 4, 3, 2, 1};
	vector<int> num(b, b+5);
	nextPermutation(num);
	for(int i = 0; i < num.size(); ++i)
		cout << num[i] << " ";
	cout << endl;
	return 0;
}
