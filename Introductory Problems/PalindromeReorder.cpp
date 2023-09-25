#include <bits/stdc++.h>
using namespace std;

int cnt[30];

int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'A']++;
	}
	int check = 0;
	for (int i = 0; i < 26; i++) {
		check += (cnt[i] % 2);
	}
	if (check > 1) {
		cout << "NO SOLUTION";
		return 0;
	}
	string ans = "";
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 == 0) {
			for (int j = 0; j < cnt[i]/2; j++) {
				ans.push_back(i + 'A');
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 == 1) {
			for (int j = 0; j < cnt[i]; j++) {
				ans.push_back(i + 'A');
			}
		}
	}
	for (int i = 25; i >= 0; i--) {
		if (cnt[i] % 2 == 0) {
			for (int j = 0; j < cnt[i]/2; j++) {
				ans.push_back(i + 'A');
			}
		}
	}
	cout << ans;

	return 0;
}