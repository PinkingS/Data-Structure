#include <iostream>
#include <limits.h>

using namespace std;

struct node {
	int val, min;
	node() : val(0), min(0) {}
};

class stackWithMin {
public:
	stackWithMin(int size = 30) {
		buf = new node[size];
		buf[0].min = INT_MAX;
		cur = 0;
	}

	~stackWithMin() {
		delete [] buf;
	}

	void push(int val) {
		buf[++cur].val = val;
		if(buf[cur-1].min > val)
			buf[cur].min = val;
		else
			buf[cur].min = buf[cur-1].min;
	}

	int min() {
		return buf[cur].min;
	}
	
	void pop() {
		--cur;
	}
	
	int top() {
		return buf[cur].val;
	}

	bool empty() {
		return cur == 0;
	}

private:
	node *buf;
	int cur;
};

class stack {
public:
	stack(int size = 30) {
		buf = new int[size];
		cur = -1;
	}

	~stack() {
		delete [] buf;
	}

	void push(int val) {
		buf[++cur] = val;
	}

	void pop() {
		--cur;
	}

	int top() {
		return buf[cur];
	}

	bool empty() {
		return cur == -1;
	}
private:
	int *buf;
	int cur;
};

class stackWithMin_2 {
public:
	stackWithMin_2() {
		
	}
	
	~stackWithMin_2() {

	}
	
	void push(int val) {
		s1.push(val);
		if(val <= min())
			s2.push(val);
	}

	void pop() {
		if(s1.top() == min())
			s2.pop();
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int min() {
		if(s2.empty()) return INT_MAX;
		else return s2.top();
	}
private:
	stack s1, s2;
};

int main() {
	stackWithMin_2 mystack;
	for(int i = 0; i < 5; ++i)
		mystack.push(i);
	cout << mystack.min() << " " << mystack.top() << endl;
	mystack.push(-20);
	mystack.push(1);
	cout << mystack.min() << " " << mystack.top() << endl;
	mystack.pop();
	cout << mystack.min() << " " << mystack.top() << endl;
	return 0;
}
