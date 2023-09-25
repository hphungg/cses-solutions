#include <bits/stdc++.h>

#define fi first
#define se second
#define pair_int pair<int, int>

using namespace std;

int n, x;
vector<pair_int> a;

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		int y;
		cin >> y;
		a.push_back({y, i});
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < (int) a.size(); i++) {
		int j = lower_bound(a.begin(), a.end(), pair_int(x - a[i].fi, 0)) - a.begin();
		if (j != n && j != i && a[i].fi + a[j].fi == x) {
			if (a[j].se < a[i].se) swap(a[j].se, a[i].se);
			cout << a[i].se << " " << a[j].se;
			return 0;
		}
	} 
	cout << "IMPOSSIBLE";
	return 0;
}