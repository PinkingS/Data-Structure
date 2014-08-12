#include <iostream>

using namespace std;

int c[8], n=8, cnt = 0;

void print() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			if(j == c[i])
				cout << "1";
			else
				cout << "0";
		cout << endl;
	}
	cout << endl;
}

void placeQueen(int r) {
	if(r == n) {
		print();
		++cnt;
		return;
	}

	for(int i = 0; i < n; ++i) {
		c[r] = i;
		bool ok = true;
		for(int j = 0; j < r; ++j) {
			if(c[r] == c[j] || r-j == c[r]-c[j] || r-j == c[j]-c[r]) {
				ok = false;
				break;
			}
		}
		if(ok) placeQueen(r+1);
	}
}

int main() {
	placeQueen(0);
	cout << cnt << endl;
	return 0;
}
