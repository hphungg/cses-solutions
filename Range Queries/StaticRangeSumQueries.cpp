#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[200010];
long long s[200010];

int main() {
	cin >> n >> q;
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	while (q--) {
		int L, R;
		cin >> L >> R;
		cout << s[R] - s[L-1] << endl;
	}
	return 0;
}