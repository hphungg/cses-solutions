#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cur = 5, ans = 0;
	while (cur <= n) {
		ans += n/cur;
		cur *= 5;
	}
	cout << ans;
	return 0;
}