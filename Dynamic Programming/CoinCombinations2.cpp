#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;

const int mod = 1000000007;

int n, x;
int c[maxn];
int dp[maxn];

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int s = 1; s <= x; s++) {
			if (s - c[i] >= 0) dp[s] = (dp[s] + dp[s - c[i]]) % mod;
		}
	}
	cout << dp[x];
	return 0;
}