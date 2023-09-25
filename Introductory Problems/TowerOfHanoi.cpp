#include <bits/stdc++.h>
using namespace std;

void move(int n, int from, int to, int mid) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	move(n - 1, from, mid, to);
	cout << from << " " << to << "\n"; 
	move(n - 1, mid, to, from);
}

int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	move(n, 1, 3, 2);
	return 0;
}