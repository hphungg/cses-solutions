#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll count(ll n) {
	ll x = n, tmp = 1;
	int cnt = 0;
	while (x > 0) {
		cnt++;
		x /= 10;
	}
	for (int i = 2; i <= cnt; i++) tmp *= 10;
	ll ans = 0;
	ans += (n - tmp + 1)*cnt;
	cnt--;
	n = tmp;
	while (n > 0) {
		ans += (n - n/10)*cnt;
		cnt--;
		n /= 10;
	}
	return ans;
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		ll k;
		cin >> k;
		ll L = 0, R = 1e18;
		while (L < R) {
			ll mid = (L + R) / 2;
			if (count(mid) >= k) R = mid;
			else L = mid + 1;
		}
		k -= count(L - 1);
		vector<int> nums;
		while (L > 0) {
			nums.push_back(L%10);
			L /= 10;
		}
		reverse(nums.begin(), nums.end());
		cout << nums[k - 1] << "\n";
	}

	return 0;
}