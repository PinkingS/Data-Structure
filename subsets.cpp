#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subsetsRe(vector<vector<int> > &ans, vector<int> &S, vector<int> &sub, int start) {
	if(sub.size() > S.size())
		return;
	
	for(int i = start; i < S.size(); ++i) {
		sub.push_back(S[i]);
		ans.push_back(sub);
		subsetsRe(ans, S, sub, i+1);
		sub.pop_back();
	}
	
}

vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int> > ans;
	if(S.empty())
		return ans;
	sort(S.begin(), S.end());
	vector<int> sub;
	ans.push_back(sub);
	subsetsRe(ans, S, sub, 0);
	return ans;
}

int main() {
	int a[] = {3, 1, 2, 4};
	vector<int> num(a, a+4);
	vector<vector<int> > ans = subsets(num);

	for(int i = 0; i < ans.size(); ++i) {
		for(int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
