#include <bits/stdc++.h>

#define mask(x) (1 << (x))

using namespace std;

int a[66666];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "0";
	}
	cout << "\n";
	
	a[0] = 1;
	int x = 0;
	for (int i = 1; i <= mask(n); i++) {
		for (int j = 0; j < n; j++) {
			int y = x ^ mask(j);
			if (a[y] == 0) {
				x = y;
				a[y] = 1;
				string s;
				while (y) {
					if (y&1) s += '1';
					else s += '0';
					y >>= 1;
				}
				reverse(s.begin(), s.end());
				for (int i = 0; i < n - (int) s.size(); i++) {
					cout << "0";
				}
				cout << s << "\n";
				break;
			}
		}
	}
	return 0;
}


