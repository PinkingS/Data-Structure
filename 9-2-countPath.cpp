#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct point {
	int x,y;
};

stack<point> sp;

const int MAXN = 20;
int g[MAXN][MAXN];
point path_array[MAXN+MAXN];

int path(int m, int n) {
	if(m == 1 || n == 1) return 1;
	else return path(m-1, n) + path(m, n-1);
}

long long fact(int n) {
	if(n == 0) return 1;
	else return (long long)fact(n-1)*n;
}

long long path_1(int m, int n) {
	return fact(m-1+n-1)/(fact(m-1)*fact(n-1));
}

bool get_path(int m, int n) {
	point p;
	p.x = m;
	p.y = n;
	sp.push(p);
	if(m == 1 && n == 1) return true;
	bool suc = false;
	if(m > 1 && g[m-1][n])
		suc = get_path(m-1, n);
	if(!suc && n > 1 && g[m][n-1])
		suc = get_path(m, n-1);
	if(!suc) sp.pop();
	return suc;
}

void get_all_path(int m, int n, int M, int N, int len) {
	if(g[m][n] == 0) return;
	point p;
	p.x = m;
	p.y = n;
	path_array[len++] = p;
	if(m == M && n == N) {
		for(int i = 0; i < len; ++i)
			cout << "(" << path_array[i].x << "," << path_array[i].y << ") ";
		cout << endl;
	}
	else {
		get_all_path(m, n+1, M, N, len);
		get_all_path(m+1, n, M, N, len);
	}
}

int main() {
	freopen("9.2.in", "r", stdin);
	cout << path(10, 10) << endl;
	cout << path_1(10, 10) << endl;

	int m,n;
	cin >> m >> n;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> g[i][j];
	cout << "one of the paths : " << endl;
	get_path(m, n);
	while(!sp.empty()) {
		point p = sp.top();
		cout << "(" << p.x << "," << p.y << ")" << " ";
		sp.pop();	
	}

	get_all_path(1, 1, m, n, 0);

	return 0;
}
