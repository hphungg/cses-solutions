#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n);
	if (a[1] != 1) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= n-1; i++) {
		if (a[i] != a[i-1] + 1) {
			cout << a[i-1] + 1;
			return 0;
		}
	}
	cout << a[n-1]+1;
	return 0;
}