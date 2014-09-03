#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permuteUniqueRe(vector<int> &num, vector<vector<int> > &res, vector<int> &per, vector<bool> &used) {
	if(per.size() == num.size()) {
		res.push_back(per);
		return;
	}
	for(int i = 0; i < num.size(); ++i) {
		if(!used[i]) {
			per.push_back(num[i]);
			used[i] = true;
			permuteUniqueRe(num, res, per, used);
			used[i] = false;
			per.pop_back();
			while(i+1 < num.size() && num[i+1] == num[i]) i++;
		}
	}
}

vector<vector<int> > permuteUnique(vector<int> &num) {
	vector<vector<int> > res;
	if(num.empty())
		return res;
	vector<int> per;
	vector<bool> used(num.size(), false);
	sort(num.begin(), num.end());
	permuteUniqueRe(num, res, per, used);
	return res;
}

vector<vector<int> > permuteUnique_2(vector<int> &num) {
	vector<vector<int> > res;
	if(num.empty())	return res;
	sort(num.begin(), num.end());
	res.push_back(num);
	while(next_permutation(num.begin(), num.end()))
		res.push_back(num);
	return res;
}

bool noswap(vector<int> &num, int i, int step) {
	for(int j = step; j < i; ++j) {
		if(num[i] == num[j])
			return true;
	}
	return false;
}

void permuteUnique_3Re(vector<int> &num, int step, vector<vector<int> > &res) {
	if(step == num.size()) {
		res.push_back(num);
		return;
	}

	for(int i = step; i < num.size(); ++i) {
		if(noswap(num, i, step))
			continue;
		swap(num[i], num[step]);
		permuteUnique_3Re(num, step+1, res);
		swap(num[i], num[step]);
	}
}

vector<vector<int> > permuteUnique_3(vector<int> &num) {
	vector<vector<int> > res;
	permuteUnique_3Re(num, 0, res);
	return res;
}

int main() {
	int a[] = {1, 1, 2};
	vector<int> num(a, a+3);
	vector<vector<int> > res = permuteUnique_3(num);
	for(int i = 0; i < res.size(); ++i) {
		for(int j = 0; j < res[0].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
