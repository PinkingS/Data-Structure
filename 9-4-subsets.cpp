#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > get_subset(int a[], int index, int n) {
	vector<vector<int> > subsets;
	if(index == n) {
		vector<int> sub;
		subsets.push_back(sub); // empty set
	}
	else {
		vector<vector<int> > small_sub = get_subset(a, index+1, n);
		int v = a[index];
		for(int i = 0; i < small_sub.size(); ++i) {
			vector<int> item = small_sub[i];
			subsets.push_back(item);
			item.push_back(v);
			subsets.push_back(item);
		}
	}
	return subsets;
}

void print_subset(vector<vector<int> > &sub) {
	for(int i = 0; i < sub.size(); ++i) {
		vector<int> item = sub[i];
		for(int j = 0; j < item.size(); ++j)
			cout << item[j] << " ";
		cout << endl;
	}
}

vector<vector<int> > get_subset_2(int a[], int n) {
	vector<vector<int> > subsets;
	int max = 1 << n;
	for(int i = 0; i < max; ++i) {
		vector<int> item;
		int index = 0;
		int j = i;
		while(j > 0) {
			if(j & 1)
				item.push_back(a[index]);
			j >>= 1;
			++index;
		}
		subsets.push_back(item);
	}
	return subsets;
}

int main() {
	int a[] = {1, 2, 3, 4};
	vector<vector<int> > sub = get_subset(a, 0, 4);
	print_subset(sub);

	vector<vector<int> > sub2 = get_subset_2(a, 4);
	print_subset(sub2);

	return 0;
}
