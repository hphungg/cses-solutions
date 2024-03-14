#include <bits/stdc++.h>
using namespace std;

int n, a[200010];

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<int> towers;

	towers.push_back(INT_MAX);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(towers.begin(), towers.end(), a[i]) - towers.begin();
		if (j >= 0 && j < (int) towers.size()) {
			towers[j] = a[i];
		} else {
			towers.push_back(a[i]);
			ans++;
		}
	}

	cout << ans;
	return 0;
}