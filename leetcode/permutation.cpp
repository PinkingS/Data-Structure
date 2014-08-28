#include <iostream>
#include <vector>
using namespace std;

void permuteRe(vector<int> &num, vector<vector<int> > &res, vector<int> per, vector<bool> &used) {
	if(per.size() == num.size()) {
		res.push_back(per);
		return;
	}

cout << "used : ";
for(int i = 0; i < used.size(); ++i)
	cout << used[i] << endl;
cout << endl;
	
	for(int i = 0; i < num.size(); ++i) {
		if(!used[i]) {
			per.push_back(num[i]);
			used[i] = true;
			permuteRe(num, res, per, used);
			used[i] = false;
			per.pop_back();
		}
	}
}

vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> >  res;
	if(num.empty()) return res;
	int n = num.size();
	vector<bool> used(num.size(), false);
	vector<int> per;
	permuteRe(num, res, per, used);
	return res;
}



int main() {
	int a[] = {1, 2, 3};
	vector<int> num(a, a+3);
	vector<vector<int> > res = permute(num);
	for(int i = 0; i < res.size(); ++i) {
		for(int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
