#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 1, res = 1;
	for (int i = 1; i < (int) s.size(); i++) {
		if (s[i] == s[i-1]) {
			cnt++;
		} else {
			res = max(res, cnt);
			cnt = 1;
		}
	}
	res = max(res, cnt);
	cout << res;
	return 0;
}