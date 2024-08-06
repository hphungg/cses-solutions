#include <bits/stdc++.h>
#define pairs pair<int, int>
#define inf 1000000000
using namespace std;

int n, m;
vector<int> adj[100010];
int dist[100010], child[100010];

void dijkstra(int s) {
	for(int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	priority_queue<pairs> pq;
	dist[1] = 1;
	pq.push(pairs(-1, s));

	while (!pq.empty()) {
		pairs top = pq.top();
		pq.pop();

		int u = top.second;
		int du = -top.first;

		if (du != dist[u]) {
			continue;
		}

		for (int v: adj[u]) {
			if (dist[v] > dist[u] + 1) {
				child[v] = u;
				dist[v] = dist[u] + 1;
				pq.push(pairs(-dist[v], v));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dijkstra(1);
	if (dist[n] == inf) {
		cout << "IMPOSSIBLE";
	} else {
		cout << dist[n] << endl;
		vector<int> path;
		int s = n;
		while (s != 1) {
			path.push_back(s);
			s = child[s];
		}
		path.push_back(1);
		for (int i = (int) path.size() - 1; i >= 0; i--) {
			cout << path[i] << " ";
		}
	}
	return 0;
}