#include <bits/stdc++.h>
using namespace std;

long long a[200010];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	long long res = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[i-1]) {
			res += (a[i-1] - a[i]);
			a[i] = a[i-1];
		}
	}
	cout << res;
	return 0;
}