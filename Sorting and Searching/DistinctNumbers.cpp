#include <bits/stdc++.h>

#define maxn 200010

using namespace std;

int a[maxn];

int main() {
	int n;
	cin >> n;
	set<int> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	cout << (int) s.size();
	return 0;
}