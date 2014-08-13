#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxN = 50;
bool g[maxN][maxN];
int visited[maxN];
bool found;
int n;

void dfs(int v) {
	visited[v] = -1;
	for(int i = 0; i < n; ++i) {
		if(g[v][i] && !visited[i]) {
			dfs(i);
			visited[i] = 1;
		}
		if(g[v][i] && visited[i] == -1) {
			cout << "YES!" << endl;
			found = true;
			return;
		}
	}
	return;
}

int main() {
	memset(g, false, sizeof(g));
	memset(visited, 0, sizeof(visited));
	found = false;

	freopen("10.5.in", "r", stdin);
	int c;
	cin >> n >> c;
	int src, des;
	for(int i = 0; i < c; ++i) {
		cin >> src >> des;
		g[src][des] = true;
	}
	dfs(1);
	if(!found)
		cout << "NO!" << endl;
	return 0;
}
