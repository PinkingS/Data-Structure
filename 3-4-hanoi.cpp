#include <iostream>
#include <stack>

using namespace std;

struct op {
	int begin, end;
	char src, buf, des;
	op() {}
	op(int pbegin, int pend, int psrc, int pbuf, int pdes): begin(pbegin), end(pend), src(psrc), buf(pbuf), des(pdes) {}
};

void hanoi_re(int n, char src, char buf, char des) {
	if(n == 1)
		cout << "Move disk " << n << " from " << src << " to " << des << endl;
	else {
		hanoi_re(n-1, src, des, buf);
		cout << "Move disk " << n << " from " << src << " to " << des << endl;
		hanoi_re(n-1, buf, src, des);
	}
}

void hanoi_it(int n, char src, char buf, char des) {
	stack<op> st;
	op tmp;
	st.push(op(1, n, src, buf, des));
	while(!st.empty()) {
		tmp = st.top(); st.pop();
		if(tmp.begin != tmp.end) {
			st.push(op(tmp.begin, tmp.end-1, tmp.buf, tmp.src, tmp.des));
			st.push(op(tmp.end, tmp.end, tmp.src, tmp.buf, tmp.des));
			st.push(op(tmp.begin, tmp.end-1, tmp.src, tmp.des, tmp.buf));
		} else {
			cout << "Move disk " << tmp.begin << " from " << tmp.src << " to " << tmp.des << endl;
		}
	}
}

int main() {
	int n = 3;
	hanoi_it(n, 'A', 'B', 'C');
	return 0;
}
