#include <iostream>
#include <string>

using namespace std;

int waysToResult(string exp, bool result, int s, int e) {
	if(s == e) {
		if(exp[s] == '1' && result)
			return 1;
		else if(exp[s] == '0' && !result)
			return 1;
		else 
			return 0;
	}

	int c = 0;
	if(result) {
		for(int i = s+1; i <= e; i += 2) {
			char op = exp[i];
			if(op == '&')
				c += waysToResult(exp, true, s, i-1) * waysToResult(exp, true, i+1, e);
			else if(op == '|') {
				c += waysToResult(exp, true, s, i-1) * waysToResult(exp, true, i+1, e);
				c += waysToResult(exp, true, s, i-1) * waysToResult(exp, false, i+1, e);
				c += waysToResult(exp, false, s, i-1) * waysToResult(exp, true, i+1, e);
			} 
			else if(op == '^') {
				c += waysToResult(exp, true, s, i-1) * waysToResult(exp, false, i+1, e);
				c += waysToResult(exp, false, s, i-1) * waysToResult(exp, true, i+1, e);	
			}
		}
	} else {
			for(int i = s+1; i <= e; i += 2) {
			char op = exp[i];
			if(op == '|')
				c += waysToResult(exp, false, s, i-1) * waysToResult(exp, false, i+1, e);
			else if(op == '&') {
				c += waysToResult(exp, false, s, i-1) * waysToResult(exp, false, i+1, e);
				c += waysToResult(exp, true, s, i-1) * waysToResult(exp, false, i+1, e);
				c += waysToResult(exp, false, s, i-1) * waysToResult(exp, true, i+1, e);
			} 
			else if(op == '^') {
				c += waysToResult(exp, true, s, i-1) * waysToResult(exp, true, i+1, e);
				c += waysToResult(exp, false, s, i-1) * waysToResult(exp, false, i+1, e);	
			}
		}
	
	}
	return c;
}

int main() {
	string s = "1^0|0|1";
	cout << waysToResult(s, true, 0, 6) << endl;
	return 0;
}
