# include <bits/stdc++.h>

#define maxn 200010

using namespace std;

int n;
int a[maxn], b[maxn];
vector<int> times;
int mark[2*maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		times.push_back(a[i]);
		times.push_back(b[i]);
	}
	sort(times.begin(), times.end());
	for (int i = 1; i <= n; i++) {
		int a1 = lower_bound(times.begin(), times.end(), a[i]) - times.begin();	
		int b1 = lower_bound(times.begin(), times.end(), b[i]) - times.begin();
		mark[a1]++;
		mark[b1]--;
	}

	int guest = 0, ans = -INT_MAX;
	for (int i = 0; i < times.size(); i++) {
		guest += mark[i];
		ans = max(ans, guest);
	}
	cout << ans;
	return 0;
}