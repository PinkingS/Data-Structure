#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class MyQueue {
public:
	MyQueue() {}
	~MyQueue() {}
	void push(T val) {
		sin.push(val);
	}

	void pop() {
		move(sin, sout);
		sout.pop();
	}

	T back() {
		move(sout, sin);
		return sin.top();
	}

	T front() {
		move(sin, sout);
		return sout.top();
	}

	int size() {
		return sin.size() + sout.size();
	}

	bool empty() {
		return sin.empty() && sout.empty();
	}

	void move(stack<T> &sin, stack<T> &sout) {
		if(sout.empty()) {
			while(!sin.empty()) {
				sout.push(sin.top());
				sin.pop();
			}
		}
	}

	
private:
	stack<T> sin, sout; 
};

int main() {
	MyQueue<int> q;
	for(int i = 0; i < 10; ++i)
		q.push(i);
	cout << q.front() << endl;
	q.pop();
	q.push(22);
	q.push(33);
	cout << q.size() << " " << q.front() << endl;
	while(!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
