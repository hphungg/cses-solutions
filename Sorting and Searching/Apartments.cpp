#include <bits/stdc++.h>
#define maxn 200010
using namespace std;

int n, m, k;
int a[maxn], b[maxn];

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];	
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	int j = 1, ans = 0;
	for(int i = 1; i <= n; i++) {
		if (a[i] - k <= b[j] && a[i] + k >= b[j]) {
			ans++;
			j++;
		} else {
			while (b[j] < a[i] - k && j <= m) j++;
			if (j > m) break;
			if (b[j] > a[i] + k) continue;
			ans++;
			j++;
		}
		if (j > m) break;
	}
	cout << ans;
	return 0;
}