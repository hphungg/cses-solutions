#include <bits/stdc++.h>
using namespace std;

int n;

long long c(int x, int r) {
    long long p = 1, k = 1;
    if (x - r < r) {
        r = x - r;
    }
    if (r != 0) {
        while (r != 0) {
            p *= x;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            x--;
            r--;
        }
    } else {
        p = 1;
    }
 
    return p;
}

int main() {
	cin >> n;
	long long tmp = 0;
	cout << 0 << endl;
	for (int i = 2; i <= n; i++) {
		tmp = tmp + 8*(i-2);
		cout << c(i*i, 2) - tmp << endl;
	}
	return 0;
}