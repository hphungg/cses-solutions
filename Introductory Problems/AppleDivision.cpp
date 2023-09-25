#include <bits/stdc++.h>

#define ll long long
#define mask(n) (1 << (n))

using namespace std;

int n, p[25];
ll total_sum;

int main() {
	cin >> n;
	total_sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		total_sum += p[i];
	}

	ll ans = 1e18;
	for (int i = 1; i <= mask(n); i++) {
		ll cur_sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & mask(j)) {
				cur_sum += p[j + 1];
			}
		}
		ans = min(ans, abs(total_sum - 2*cur_sum));
	}
	cout << ans;
	return 0;
}