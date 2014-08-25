#include <cstdlib>
#include <iostream>

using namespace std;

int rand5() {
	return rand()%5+1;
}

int rand7() {
	int x = ~(1 << 31);
	while(x > 21)
		x = 5 * (rand5()-1) + rand5();
	return x%7+1;
}

int main() {
	for(int i = 0; i < 10; ++i)
		cout << rand5() << endl;
	for(int i = 0; i < 10; ++i)
		cout << rand7() << endl;
	return 0;
}

