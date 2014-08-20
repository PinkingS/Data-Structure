#include <iostream>

using namespace std;

struct Result {
	int hits;
	int pseudo_hits;
};

int code(char c) {
	switch(c) {
		case 'B': return 0;
		case 'G': return 1;
		case 'R': return 2;
		case 'Y': return 3;
		default:  return -1;
	}
}

Result estimate(const char* solution, const char* guess) {
	Result res;
	res.hits = 0;
	res.pseudo_hits = 0;

	int frequency[4] = {0};
	for(int i = 0; i < 4; ++i) {
		if(solution[i] == guess[i])
			++res.hits;
		else {
			int idx = code(solution[i]);
			++frequency[idx];
		}
	}

	for(int i = 0; i < 4; ++i) {
		int idx = code(guess[i]);
		if(idx >= 0 && frequency[idx] > 0 && guess[i] != solution[i]) {
			++res.pseudo_hits;
			--frequency[idx];
		}
	}
	return res;
}

int main() {
	char solution[] = "RYGB";
	char guess[] = "YRGR";
	Result res = estimate(solution, guess);
	cout << res.hits << " hits, " << res.pseudo_hits << " pseudo_hits" << endl;
	return 0;
}
