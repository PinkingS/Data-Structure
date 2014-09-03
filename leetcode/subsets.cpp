#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int> > res;
	if(S.empty()) return res;
	sort(S.begin(), S.end());	
	int n = 1 << S.size();
	for(int i = 0; i < n; ++i) {
		int j = i;
		int cnt = 0;
		vector<int> elem;
		while(j) {
			if(j & 1) elem.push_back(S[cnt]);
			j >>= 1;
			++cnt;
		}
		res.push_back(elem);
	}
	return res;
}

void subsets_2Re(vector<int> &S, int level, vector<int> &tmp, vector<vector<int> > &res) {
	if(level == S.size()) {
		res.push_back(tmp);
		return;
	}
	
	subsets_2Re(S, level+1, tmp, res);
	tmp.push_back(S[level]);
	subsets_2Re(S, level+1, tmp, res);
	tmp.pop_back();
}

vector<vector<int> > subsets_2(vector<int> &S) {
	vector<int> tmp;
	vector<vector<int> > res;
	sort(S.begin(), S.end());
	subsets_2Re(S, 0, tmp, res);
	return res;
}

int main() {
	int a[] = {1, 2, 3};
	vector<int> S(a, a+3);
	vector<vector<int> > res = subsets_2(S);
	for(int i = 0; i < res.size(); ++i) {
		for(int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
