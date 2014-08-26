#include <iostream>
#include <climits>
#include <string>

using namespace std;

// caution: watch out for the initial value of pos1 pos2 min
int shortestDistance(string text[], int len, string word1, string word2) {
	int pos1 = -len, pos2 = -len;
	int min = len+1;

	for(int i = 0; i < len; ++i) {
		if(text[i] == word1) {
			pos1 = i;
			int dist = pos1 - pos2;
			if(dist < min)
				min = dist;
		} else if(text[i] == word2) {
			pos2 = i;
			int dist = pos2 - pos1;
			if(dist < min)
				min = dist;
		}
	}
	return min;
}

int main() {
	string text[] = {"what", "is", "your", "name", "my", "name","is", "hi"};
	int len = 8;
	cout << shortestDistance(text, len, "is", "name") << endl;
	return 0;
}
