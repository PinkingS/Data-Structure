#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

class Median {
private:
	priority_queue<int, vector<int>, less<int> > max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;
public:
	void insert(int v);
	int getValue();
};

void Median::insert(int v) {
	if(max_heap.empty() && min_heap.empty())
		max_heap.push(v);
	else if(!max_heap.empty() && min_heap.empty())
		max_heap.push(v);
	else if(max_heap.empty() && !min_heap.empty())
		min_heap.push(v);
	else{
		if(v < max_heap.top())
			max_heap.push(v);
		else
			min_heap.push(v);
	}

	while(max_heap.size() > min_heap.size()+1) {
		int data = max_heap.top();
		min_heap.push(data);
		max_heap.pop();
	}
	while(min_heap.size() > max_heap.size()+1) {
		int data = min_heap.top();
		max_heap.push(data);
		min_heap.pop();
	}
}

int Median::getValue() {
	if(max_heap.empty() && min_heap.empty())
		return (1<<31);
	if(max_heap.size() == min_heap.size())
		return (max_heap.top() + min_heap.top()) / 2;
	else if(max_heap.size() > min_heap.size())
		return max_heap.top();
	else
		return min_heap.top();
}

int main() {
	srand((unsigned)time(0));
	Median md;
	vector<int> vi;
	int num = rand() % 30;
	for(int i = 0; i < num; ++i) {
		int data = rand() % 100;
		vi.push_back(data);
		md.insert(data);
	}
	sort(vi.begin(), vi.end());
	for(int i = 0; i < num; ++i)
		cout << vi[i] << " ";
	cout << endl << md.getValue() << endl;
	return 0;
}
