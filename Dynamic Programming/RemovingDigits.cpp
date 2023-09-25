#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000010];

int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) dp[i] = INT_MAX;
	dp[n] = 0;
	while (n >= 0) {
		if (dp[n] == INT_MAX) {
			n--;
			continue;
		}
		int x = n;
		while (x > 0) {
			int r = x%10;
			x /= 10;
			dp[n - r] = min(dp[n - r], dp[n] + 1);
		}
		n--;
	}
	cout << dp[0];
	return 0;
}