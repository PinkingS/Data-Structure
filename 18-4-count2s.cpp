#include <iostream>

using namespace std;

int has2(int n) {
	int count = 0;
	while(n > 0) {
		if(n % 10 == 2)
			++count;
		n /= 10;
	}
	return count;
}

int count2s(int n) {
	int sum = 0;
	for(int i = 0; i <= n; ++i) {
		sum += has2(i);
	}
	return sum;
}

int count2s_2(int n) {
	int count = 0;
	int factor = 1;
	int low = 0, high = 0, cur = 0;
	
	while(n / factor != 0) {
		low = n % factor; // low digits
		cur = (n / factor) % 10; // current digits
		high = n / (factor * 10); // high digits
	
		switch(cur) {
			case 0:
			case 1:
				count += high * factor;
				break;
			case 2:
				count += high * factor + low + 1;
				break;
			default:
				count += (high + 1) * factor;
				break;
		}
		factor *= 10;
	}
	return count;
}

int main() {
	int n = 34126780;
	cout << count2s(n) << endl;
	cout << count2s_2(n) << endl;
	return 0;
}
