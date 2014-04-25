#include <iostream>
#include <cstring>
using namespace std;


// O(N2) complexity
bool isUnique1(string s) {
	int length = s.length();
	for(int i = 0; i < length-1; ++i) {
		for(int j = i+1; j < length; ++j) {
			if(s[i] == s[j])
				return false;
		}
	}
	return true;
}

// O(N) complexity
// O(1) extra space -- 256B
bool isUnique2(string s) {
	bool check[256];
	memset(check, 0, sizeof(check));
	for(int i = 0; i < s.length(); ++i) {
		int value = (int)s[i];
		if(check[value])
			return false;
		else
			check[value] = true;
	}
	return true;
}

// O(N) complexity
// O(1) extra space -- 32B
bool isUnique3(string s) {
	int check[8];
	int bitNum = sizeof(int) * 8;
	memset(check, 0, sizeof(check));
	for(int i = 0; i < s.length(); ++i) {
		int value = (int)s[i];
		int index = value / bitNum;
		int shift = value % bitNum;
		if(check[index] & (1 << shift))
			return false;
		check[index] |= (1 << shift);
	}
	return true;
}

int main() {
	string s1 = "hello world";
	string s2 = "abcdefg 1-+2356789";
	cout << "s1---method1: " << isUnique1(s1) << " method2: " << isUnique2(s1) << " method3: "  << isUnique3(s1) << endl;
	cout << "s2---method1: " << isUnique1(s2) << " method2: " << isUnique2(s2) << " method3: " << isUnique3(s2) << endl;
	return 0;
}
