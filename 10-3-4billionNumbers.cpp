#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	//freopen("10.3.in", "w", stdout);
	//int miss = 12345;
	//for(int i = 0; i < 20000; ++i) {
	//	if(i == miss)
	//		continue;
	//	cout << i << endl;
	//}
	//fclose(stdout);

	freopen("10.3.in", "r", stdin);

	int int_len = sizeof(int) * 8;
	int totalnum = 20000;
	int blocksize = 2000;
	int blocknum = totalnum / blocksize;
	int *block = new int[blocknum];
	int *bit = new int[blocksize/int_len+1];
	int v;
	while(scanf("%d", &v) != EOF) {
		++block[v/blocksize];
	}

	fclose(stdin);
	int start;
	for(int i = 0; i < blocknum; ++i) {
		if(block[i] < blocksize) {
			start = i * blocksize;
			break;
		}
	}

	freopen("10.3.in", "r", stdin);
	while(scanf("%d", &v) != EOF) {
		if(v >= start && v < start+blocksize) {
			v -= start;
			bit[v/int_len] |= 1 << (v%int_len);
		}
	}

	bool found = false;
	for(int i = 0; i < blocksize/int_len+1; ++i) {
		for(int j = 0; j < int_len; ++j) {
			if((bit[i] & (1 << j)) == 0) {
				cout << i * int_len + start + j << endl;
				found = true;
				break;
			}
		}
		if(found) break;
	}

	delete[] bit;
	delete[] block;
	fclose(stdin);
	return 0;
}
