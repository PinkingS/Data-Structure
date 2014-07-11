#include <iostream>
#include <stack>

using namespace std;

stack<int> sort(stack<int> s) {
	stack<int> t;
	while(!s.empty()) {
		int data = s.top();
		s.pop();
		while(!t.empty() && data < t.top()) {
			s.push(t.top());
			t.pop();
		}
		t.push(data);
	}
	return t;
}

int main() {
	stack<int> s;
	s.push(5);
	s.push(3);
	s.push(1);
	s.push(2);
	s.push(4);
	s = sort(s);
	while(!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
