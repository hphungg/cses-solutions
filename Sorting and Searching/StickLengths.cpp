#include <bits/stdc++.h>

#define maxn 200010
#define ll long long

using namespace std;

int n;
int p[maxn];

ll calc_cost(int x) {
	ll cost = 0;
	for (int i = 1; i <= n; i++) {
		cost += abs(p[i] - x);
	}
	return cost;
}

int main() {
	cin >> n;
	ll avg = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		avg += p[i];
	}
	avg /= n;
	ll ans = calc_cost(avg);
	sort(p + 1, p + n + 1);
	if (n % 2 == 1) {
		ans = min(ans, calc_cost(p[n/2 + 1]));
	} else {
		int x = (p[n/2] + p[n/2 + 1]) / 2;
		ans = min(ans, calc_cost(x));
	}
	cout << ans;

	return 0;
}