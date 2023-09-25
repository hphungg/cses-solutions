#include <bits/stdc++.h>
#define maxn 200010
using namespace std;

int n, m;
multiset<int> tickets;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		tickets.insert(h);
	}
	for (int i = 1; i <= m; i++) {
		int t;
		cin >> t;
		auto j = tickets.upper_bound(t);
		if (j == tickets.begin()) {
			cout << "-1";
		} else {
			j--;
			cout << *j;
			tickets.erase(j);
		}
		cout << "\n";
	}
	return 0;
}