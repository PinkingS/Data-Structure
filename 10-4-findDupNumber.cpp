#include <iostream>

using namespace std;

class Bitmap {
public:
	Bitmap(int size = 32) {
		bits = new int[size/32 + 1];
	}
	~Bitmap() {
		delete[] bits;
	}
	bool get(int pos) {
		return (bits[pos/32] & (1<<(pos%32))); // pos%32 equals to pos&0x1f
	}
	void set(int pos) {
		bits[pos/32] |= (1<<(pos%32));
	}
private:
	int *bits;
};

void print_duplicate(int a[], int n, int bitsize) {
	Bitmap bm(bitsize);	
	for(int i = 0; i < n; ++i) {
		if(bm.get(a[i]-1))
			cout << a[i] << endl;
		else
			bm.set(a[i]-1);
	}
}

int main() {
	int a[] = {1, 2, 3, 4, 5, 456, 9045, 32000, 8, 9, 10, 11, 5, 8, 32000};
	print_duplicate(a, 15, 32000);
	return 0;
}
