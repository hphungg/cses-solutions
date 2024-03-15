#include <bits/stdc++.h>
using namespace std;
 
int n;
char c[1010][1010];
int f[1010][1010];
const int mod = 1000000007;
 
bool isInside(int i, int j) {
	return (i > 0 && j > 0 && i <= n && j <= n);
}
 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	if (c[1][1] == '*') {
		cout << 0;
		return 0;
	}
	f[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			if (c[i][j] == '.') {
				if (isInside(i-1, j) && c[i-1][j] == '.') {
					f[i][j] = (f[i][j] + f[i-1][j])%mod;
				}
				if (isInside(i, j-1) && c[i][j-1] == '.') {
					f[i][j] = (f[i][j] + f[i][j-1])%mod;
				}
			}
		}
	}
 
	cout << f[n][n];
	return 0;
}
