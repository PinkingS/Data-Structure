#include <string>
#include <iostream>

using namespace std;

void longestConSeq(string s) {
	if(s.empty()) {
		cout << "the input string is empty" << endl;
		return;
	}
	
	int maxLen = 0, startIndex = 0;
	int curLen = 1, curStart = 0;
	for(int i = 0; i < s.length()-1; ++i) {
		if(s[i+1] == (s[i]+1)) { // continuous here
			++curLen;
			if(maxLen < curLen) {
				maxLen = curLen;
				startIndex = curStart;
			} 
			else if(maxLen == curLen && s[curStart] > s[startIndex]) { // of the same length but latter is larger
				startIndex = curStart;
			}
		}
		else {
			curLen = 1;
			curStart = i+1;
		}
	}
	cout << startIndex << " " << maxLen << endl;
	cout << s.substr(startIndex, maxLen) << endl;
}

int main() {
	string test1 = "12348";
	longestConSeq(test1);

	string test2 = "678901234";
	longestConSeq(test2);

	return 0;
}
