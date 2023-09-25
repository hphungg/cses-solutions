#include <bits/stdc++.h>

#define ll long long
#define maxn 200010

using namespace std;

int n;
int a[maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll sums = 0;
	for (int i = 1; i <= n; i++) {
		if (sums + 1 < a[i]) {
			cout << sums + 1;
			return 0;
		}
		sums += a[i];
	}
	cout << sums + 1;
	return 0;
}