#include <iostream>

using namespace std;

void print_paren(int l, int r, char str[], int cnt) {
	if(l < 0 || r < l) return;
	if(l == 0 && r == 0) {
		for(int i = 0; i < cnt; ++i)
			cout << str[i];
		cout << endl;
	}
	else {
		if(l > 0) {
			str[cnt] = '(';
			print_paren(l-1, r, str, cnt+1);
		}
		if(r > l) {
			str[cnt] = ')';
			print_paren(l, r-1, str, cnt+1);
		}
	}
}

int main() {
	char str[6];
	print_paren(3, 3, str, 0);
	return 0;
}
