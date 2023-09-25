#include <bits/stdc++.h>

#define maxn 200010
#define fi first
#define se second
#define pair_int pair<int, int>

using namespace std;

int n;
pair_int a[maxn];
int f[maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		int L = 1, R = ans, j = 0;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (a[i].fi >= a[f[mid]].se) {
				j = mid;
				L = mid + 1;
			} else {
				R = mid - 1;
			}
		}
		if (j == ans) f[++ans] = i;
		if (a[i].se < a[f[j+1]].se) f[j+1] = i;
	}
	cout << ans;
	return 0;
}