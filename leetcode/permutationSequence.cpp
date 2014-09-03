#include <iostream>
#include <string>
using namespace std;

string getPermutation(int n, int k) {
	string num;
	int fact = 1;
	for(int i = 0; i < n; ++i) {
		num.push_back(i+1+'0');
		fact *= (i+1);
	}

	k--;
	string res;
	while(n) {
		fact /= n;
		int i = k/fact;
		k %= fact;
		res.push_back(num[i]);
		num.erase(i, 1);
		--n;
	}
	return res;
}

int main() {
	
	cout << getPermutation(3, 2) << endl;
	return 0;
}
