#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;

const int mod = 1000000007;

int f[maxn];

int main() {
	int n;
	cin >> n;
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= n; i++) {
		f[i] = 0;
		for (int j = 1; j <= min(i, 6); j++) {
			f[i] = (f[i] + f[i-j]) % mod;
		}
	}
	cout << f[n];
	return 0;
}
