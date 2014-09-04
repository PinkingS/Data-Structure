#include <iostream>
#include <vector>
using namespace std;

void combinationsRe(int n, int k, vector<int> &com, vector<vector<int> > &res, int start) {
	if(com.size() == k) {
		res.push_back(com);
		return;
	}
	for(int i = start; i <= n; ++i) {
		com.push_back(i);
		combinationsRe(n, k, com, res, i+1);
		com.pop_back();
	}
}

vector<vector<int> > combinations(int n, int k) {
	vector<vector<int> > res;
	if(n <= 0 || k > n) return res;
	vector<int> com;
	combinationsRe(n, k, com, res, 1);
	return res;
}

int main() {
	int n = 4, k = 2;
	vector<vector<int> > res = combinations(n, k);
	for(int i = 0; i < res.size(); ++i) {
		for(int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
