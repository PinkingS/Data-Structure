#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsetsRe(vector<int> &S, int level, vector<int> &tmp, vector<vector<int> > &res) {
	if(level == S.size()) {
		if(find(res.begin(), res.end(), tmp) == res.end())
			res.push_back(tmp);
		return;
	}
	
	subsetsRe(S, level+1, tmp, res);
	tmp.push_back(S[level]);
	subsetsRe(S, level+1, tmp, res);
	tmp.pop_back();
}

void subsetsRe_2(vector<int> &S, int level, vector<int> &tmp, vector<vector<int> > &res) {
	res.push_back(tmp);
	for(int i = level; i < S.size(); ++i) {
		if(i != level && S[i] == S[i-1])
			continue;
		tmp.push_back(S[i]);
		subsetsRe_2(S, i+1, tmp, res);
		tmp.pop_back();
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
	vector<vector<int> > res;
	if(S.empty()) return res;
	vector<int> tmp;
	sort(S.begin(), S.end());
	subsetsRe_2(S, 0, tmp, res);
	return res;
}

int main() {
	int a[] = {1, 2, 2};
	vector<int> S(a, a+3);
	vector<vector<int> > res = subsetsWithDup(S);
	for(int i = 0; i < res.size(); ++i) {
		for(int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
