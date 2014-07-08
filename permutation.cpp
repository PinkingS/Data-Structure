#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

// notice:
// 1. don't forget to include vector
// 2. put recurrence subroutine front of calling function
// 3. use vector when not must use array, don't mix them
// 4. remember to add comments


void permutationRe(vector<vector<char> > &ans, vector<char> &s, vector<char> &per, vector<bool> &used) {
	if(per.size() == s.size()) { // get a permutation
		ans.push_back(per);
		return;
	}

	for(int i = 0; i < s.size(); ++i) {
		if(!used[i]) {
			per.push_back(s[i]);
			used[i] = true;
			permutationRe(ans, s, per, used);
			per.pop_back();
			used[i] = false;
			while(s[i+1] == s[i]) ++i; // to avoid duplication permutations
		}
	}
}


// func: list all the unique permutations of string of alphabets
vector<vector<char> > permutation(vector<char> s) {
	vector<vector<char> > ans;
	if(s.empty()) return ans;
	vector<char> per;
	vector<bool> used(s.size(), false);
	sort(s.begin(), s.end());
	permutationRe(ans, s, per, used);
}



int main() {
	const int num = 3;
	char a[4] = {'a', 'a', 'b'};
	vector<char> string(a, a+num);
	vector<vector<char> > permutations= permutation(string);
	for(int i = 0; i < permutations.size(); ++i) {
		for(int j = 0; j < string.size(); ++j)
			cout << permutations[i][j];
		cout << endl;
	}
	return 0;
}
