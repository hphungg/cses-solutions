#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;
	if (n%4 == 0) {
		vector<int> a, b;
		for (int i = 1; i <= n; i++) {
			if (i%4 == 1 || i%4 == 0) a.push_back(i);
			else b.push_back(i);
		}
		cout << "YES\n";
		cout << (int) a.size() << "\n";
		for (int x: a) cout << x << " ";
		cout << "\n" << (int) b.size() << "\n";
		for (int x: b) cout << x << " ";
	} else if (n%4 == 3) {
		vector<int> a, b;
		for (int i = 1; i < n; i++) {
			if (i%4 == 1 || i%4 == 2) a.push_back(i);
			else b.push_back(i);
		}
		b.push_back(n);
		cout << "YES\n";
		cout << (int) a.size() << "\n";
		for (int x: a) cout << x << " ";
		cout << "\n" << (int) b.size() << "\n";
		for (int x: b) cout << x << " ";
	} else {
		cout << "NO\n";
	}
	return 0;
}