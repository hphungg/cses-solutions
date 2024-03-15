#include <bits/stdc++.h>
using namespace std;

int n, x;
int h[1010], s[1010];

int dp[1010][100010];

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i <= x; i++) {
		dp[0][i] = 0;
	}

	for (int i = 2; i <= n+1; i++) {
		for (int j = 0; j <= x; j++) {
			if (h[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i-1]] + s[i-1]);
			}
		}
	}

	cout << dp[n+1][x];
	return 0;
}