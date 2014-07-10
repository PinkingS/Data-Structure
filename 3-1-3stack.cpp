#include <iostream>
#include <limits.h>

using namespace std;

class stack3 {
public:
	stack3(int size = 20) {
		buf = new int[size * 3];
		ptop[0] = ptop[1] = ptop[2] = -1;
		this->size = size;		
	}

	~stack3() {
		delete [] buf;
	}

	void push(int stackNum, int value) {
		if(ptop[stackNum] + 1 >= size) {
			cout << "stack " << stackNum << " out of space !" << endl;
			return;
		}
		int idx = stackNum * size + ptop[stackNum] + 1;
		buf[idx] = value;
		ptop[stackNum]++;
	}

	void pop(int stackNum) {
		if(empty(stackNum)) {
			cout << "try to pop an empty stack !" << endl;
			return;
		}
		--ptop[stackNum];
	}
	
	int top(int stackNum) {
		if(empty(stackNum)) {
			cout << "empty stack !" << endl;
			return INT_MIN;
		}
		return buf[size * stackNum + ptop[stackNum]];
	}

	bool empty(int stackNum) {
		return ptop[stackNum] == -1;
	}

private:
	int *buf;
	int ptop[3];
	int size;
};

struct node {
	int val;
	int prev;
	node() : val(0), prev(-1) {}
};

class stack_3 {
public:
	stack_3(int totalsize = 60) {
		buf = new node[totalsize];
		ptop[0] = ptop[1] = ptop[2] = -1;
		this->totalsize = totalsize;
		cur = 0;
	}
	
	~stack_3() {
		delete [] buf;
	}
	
	void push(int stackNum, int val) {
		if(full()) {
			cout << "stack is full !" << endl;
			return;
		}
		buf[cur].val = val;
		buf[cur].prev = ptop[stackNum];
		ptop[stackNum] = cur;
		int i = cur+1;
		for(; i < totalsize; ++i) {
			if(buf[i].prev == -1)
				break;
		}
		cur = i;
	}

	void pop(int stackNum) {
		if(empty(stackNum)) {
			cout << "try to pop an empty stack !" << endl;
			return;
		}
		if(ptop[stackNum] < cur)
			cur = ptop[stackNum];
		ptop[stackNum] = buf[ptop[stackNum]].prev;
	}
	
	int top(int stackNum) {
		if(empty(stackNum)) {
			cout << "stack is empty !" << endl;
			return INT_MIN;
		}
		return buf[ptop[stackNum]].val;
	}

	bool empty(int stackNum) {
		return ptop[stackNum] == -1;
	}
	
	bool full() {
		return cur == totalsize;
	}

private:
	node *buf;
	int ptop[3];
	int totalsize;
	int cur;
};

int main() {
	stack_3 mystack;
	for(int i = 0; i < 10; ++i)
		mystack.push(0, i);
	for(int i = 10; i < 20; ++i)
		mystack.push(1, i);
//	for(int i = 100; i < 110; ++i)
//		mystack.push(2, i);
	for(int i = 0; i < 3; ++i)
		cout << mystack.top(i) << " ";

	cout << endl;
	for(int i = 0; i < 3; ++i) {
		mystack.pop(i);
		cout << mystack.top(i) << " ";
	}
	cout << endl;

	mystack.push(0, 111);
	mystack.push(1, 222);
	mystack.push(2, 333);
	for(int i = 0; i < 3; ++i)
		cout << mystack.top(i) << " ";
	cout << endl;

	return 0;
}
