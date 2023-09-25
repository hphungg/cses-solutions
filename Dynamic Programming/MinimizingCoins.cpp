#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int n, x;
int c[maxn];
int dp[1000010];

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= x; i++) dp[i] = INT_MAX;
	dp[0] = 0;
	for (int s = 1; s <= x; s++) {
		for (int i = 1; i <= n; i++) {
			if (s - c[i] >= 0 && dp[s - c[i]] != INT_MAX) {
				dp[s] = min(dp[s], dp[s - c[i]] + 1);
			}
		}
	}
	if (dp[x] == INT_MAX) {
		cout << -1;
	} else {
		cout << dp[x];
	}
	return 0;
}
