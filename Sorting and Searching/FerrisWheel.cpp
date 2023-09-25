# include <bits/stdc++.h>
# define maxn 200010
using namespace std;

int n, x;
int p[maxn];

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	sort (p + 1, p + n + 1);
	int i = 1, j = n, ans = 0;
	while (i <= n && j >= i) {
		if (p[i] + p[j] <= x) {
			ans++;
			i++;
			j--;
		} else {
			ans++;
			j--;
		}
	}
	cout << ans;
	return 0;
}

