#include <bits/stdc++.h>
using namespace std;

int res[1000010];

void solve_odd(int n) {
	int i = 1, L = n-1, R = 1;
	while (i <= n/2) {
		res[i] = L;
		res[n-i+1] = R;
		if (L > R) {
			swap(L, R);
			L++;
			R--;
		} else {
			swap(L, R);
			L--;
			R++;
		}
		i++;
	}
	res[n/2+1] = n;
}

int main() {
	int n;
	cin >> n;
	if (n == 3 or n == 2) {
		cout << "NO SOLUTION";
		return 0;
	}
	if (n == 4) {
		cout << "2 4 1 3";
		return 0;
	}
	if (n % 2 == 1) {
		solve_odd(n);
	} else {
		solve_odd(n-1);
		res[n] = n;
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}