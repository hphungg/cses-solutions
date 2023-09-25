#include <bits/stdc++.h>

#define maxn 200010
#define ll long long

using namespace std;

int n;
ll s[maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	priority_queue<ll> queue;
	queue.push(-s[0]);
	ll ans = -1e18;
	for (int i = 1; i <= n; i++) {
		ll val = s[i] + queue.top();
		ans = max(ans, val);
		queue.push(-s[i]);
	}
	cout << ans;
	return 0;
}