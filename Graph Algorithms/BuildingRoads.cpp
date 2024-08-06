#include <bits/stdc++.h>

#define maxn 100010

using namespace std;

int n, m;
vector<int> adj[maxn];

int L[maxn], N[maxn];
int marker[maxn], t[maxn];

int cnt = 0;
int stplt = 0;
stack<int> s;

void tarzan(int u) {
	L[u] = N[u] = ++cnt;
	s.push(u);
	for (int v: adj[u]) {
		if (N[v]) {
			L[u] = min(L[u], N[v]);
		} else {
			tarzan(v);
			L[u] = min(L[u], L[v]);
		}
	}

	if (N[u] == L[u]) {
		stplt++;
		marker[u] = stplt;
		t[stplt] = u;
		int v;
		do {
			v = s.top();
			s.pop();
			N[v] = L[v] = INT_MAX;
		} while (v != u);
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

	for (int i = 1; i <= n; i++) {
		if (!N[i]) tarzan(i);
	}

	cout << stplt - 1 << endl;
	for (int i = 2; i <= stplt; i++) {
		cout << t[i-1] << " " << t[i] << endl;
	}

	return 0;
}