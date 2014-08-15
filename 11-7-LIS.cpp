#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 50;
struct person {
	int h,w;
};
person p[maxn];
int d[maxn];

bool cmp(person a, person b) {
	if(a.h == b.h) return a.w < b.w;
	else return a.h < b.h;
}

int lis(person p[], int n) {
	int len = 1;
	for(int i = 0; i < n; ++i) {
		d[i] = 1;
		for(int j = 0; j < i; ++j) {
			if(p[j].w <= p[i].w && d[j]+1>d[i])
				d[i] = d[j]+1;
		}
		if(d[i]>len) len = d[i];
	}
	return len;
}

int main() {
	freopen("11.7.in", "r", stdin);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> p[i].h >> p[i].w;
	sort(p, p+n, cmp);
	cout << lis(p, n) << endl;
	fclose(stdin);
	return 0;
}
