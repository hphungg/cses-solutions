#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b) {
	string ans;
	if (a > b) swap(a, b);
	if (a == 0 and b != 0) {
		ans = "NO";
	} else {
		int tmp = 2*a - b;
		if (tmp%3 == 0 and tmp >= 0) {
			ans = "YES";
		} else {
			ans = "NO";
		}
	}
	cout << ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		solve(a, b);
		cout << "\n";
	}
	return 0;
}

