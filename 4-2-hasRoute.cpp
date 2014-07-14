#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>

using namespace std;

const int maxN = 10;
bool g[maxN][maxN], visited[maxN];
int n;

void initGraph() {
	memset(g, false, sizeof(g)); // memset needs <cstring>
	memset(visited, false, sizeof(visited));
}

bool route(int src, int des) {
	queue<int> q;
	q.push(src);
	visited[src] = true;
	while(!q.empty()) {
		int node = q.front(); q.pop();
		if(node == des)
			return true;
		for(int i = 0; i < n; ++i) {
			if(g[node][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return false;
}

int main() {
	freopen("4-2.in", "r", stdin); // freopen needs <cstdio>
	int m;
	int u, v;

	initGraph();

	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u][v] = true;
	}

	cout << route(0, n-1) << endl;

	return 0;
}
