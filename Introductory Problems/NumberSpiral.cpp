#include <bits/stdc++.h>
using namespace std;

int t;

void solve(long long y, long long x) {
	long long ans;
	if (x <= y) {
		if (y % 2 == 0) {
			ans = y*y - x + 1;
		} else {
			ans = (y-1)*(y-1) + x;
		}
		
	} else {
		if (x % 2 == 0) {
			ans = x*x - x + 1 - (x - y);
		} else {
			ans = x*x - y + 1;
		}
	}
	cout << ans;
}

int main() {
	cin >> t;
	while (t--) {
		long long x, y;
		cin >> y >> x;
		solve(y, x);
		cout << endl;
	}

	return 0;
}