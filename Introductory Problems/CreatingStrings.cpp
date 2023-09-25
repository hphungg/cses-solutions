#include <bits/stdc++.h>
using namespace std;

string s;
bool mark[10];
int x[10];

map<string, int> check;
vector<string> ans;

void process(int n) {
	string new_s = "";
	for (int i = 1; i <= n; i++) {
		new_s.push_back(s[x[i] - 1]);
	}
	if (!check[new_s]) {
		check[new_s] = 1;
		ans.push_back(new_s);
	}
}

void backtrack(int k, int n) {
	for (int i = 1; i <= n; i++) {
		if (mark[i] == false) {
			x[k] = i;
			if (k == n) {
				process(n);
			} else {
				mark[i] = true;
				backtrack(k + 1, n);
				mark[i] = false;
			}
		}
	}
}

int main() {
	cin >> s;
	int n = (int) s.size();
	backtrack(1, n);

	cout << (int) ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}