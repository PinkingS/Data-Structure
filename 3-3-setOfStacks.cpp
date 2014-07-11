#include <iostream>
#include <limits.h>

using namespace std;

const int STACK_SIZE = 5;
const int STACK_NUM = 5;

class stack {
public:
	stack(int capa = STACK_SIZE) {
		buf = new int[capa];
		cur = 0;
		capacity = capa;
	}
	
	~stack() {
		delete [] buf;
	}

	void push(int val) {
		if(isFull()) {
			cout << "stack is full !" << endl;
			return;
		}
		buf[cur++] = val;
	}

	void pop() {
		if(isEmpty()) {
			cout << "try to pop an empty stack !" << endl;
			return;
		}
		--cur;
	}

	int top() {
		if(isEmpty()) {
			cout << "the stack is empty !" << endl;
			return INT_MIN;
		}
		return buf[cur-1];
	}

	bool isFull() {
		return cur == capacity;
	}

	bool isEmpty() {
		return cur == 0;
	}
private:
	int *buf;
	int cur;
	int capacity;
};

class setOfStacks { // without popAt()
public:
	setOfStacks(int capa = STACK_NUM) {
		st = new stack[capa];
		cur = 0;
		capacity = capa;
	}

	~setOfStacks() {
		delete [] st;
	}

	void push(int val) {
		if(full()) {
			cout << "stack is full !" << endl;
			return;
		}
		if(st[cur].isFull()) ++cur;
		st[cur].push(val);
	}

	void pop() {
		if(empty()) {
			cout << "try to pop an empty stack !" << endl;
			return;
		}
		if(st[cur].isEmpty()) --cur;
		st[cur].pop();
	}

	int top() {
		if(st[cur].isEmpty()) --cur;
		return st[cur].top();
	}

	bool empty() {
		if(cur == 0) return st[cur].isEmpty();
		else return false;
	}

	bool full() {
		if(cur == capacity-1) return st[cur].isFull();
		else return false;
	}
private:
	stack *st;
	int cur;
	int capacity;
};

class setOfStacks_2 { // with popAt()
public:
	setOfStacks_2(int capa = STACK_NUM) {
		st = new stack[capa];
		cur = 0;
		capacity = capa;
	}

	~setOfStacks_2() {
		delete [] st;
	}

	void push(int val) {
		if(full()) {
			cout << "stack is full !" << endl;
			return;
		}
		if(st[cur].isFull()) ++cur;
		st[cur].push(val);
	}

	void pop() {
		if(empty()) {
			cout << "try to pop an empty stack !" << endl;
			return;
		}
		while(st[cur].isEmpty()) --cur;
		st[cur].pop();
	}

	void popAt(int idx) {
		if(empty()) {
			cout << "try to pop an empty stack !" << endl;
			return;
		}
		while(st[idx].isEmpty()) --idx;
		st[idx].pop();
	}

	int top() {
		while(st[cur].isEmpty()) --cur;
		return st[cur].top();
	}

	bool empty() {
		while(cur != -1 && st[cur].isEmpty()) --cur;
		if(cur == -1) return true;
		else return false;
	}

	bool full() {
		if(cur == capacity-1) return st[cur].isFull();
		else return false;
	}
private:
	stack *st;
	int cur;
	int capacity;
};

int main() {
	setOfStacks_2 ss;
	for(int i = 0; i < 7; ++i)
		ss.push(i);
	ss.popAt(0);
	ss.popAt(0);
	while(!ss.empty()) {
		cout << ss.top() << " ";
		ss.pop();
	}
	cout << endl;
	ss.pop();

	return 0;
}
