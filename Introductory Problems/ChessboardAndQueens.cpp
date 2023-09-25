#include <bits/stdc++.h>

using namespace std;

int ans = 0;
char c[10][10];
int col[10], ld[10], rd[10];

void place(int i) {
	if (i == 8) {
		ans++;
		return;
	}
	for (int j = 0; j < 8; j++) {
		if (c[i][j] == '.' && col[j] == 0 && ld[j-i+7] == 0 && rd[j+i] == 0) {
			col[j] = ld[j-i+7] = rd[j+i] = 1;
			place(i + 1);
			col[j] = ld[j-i+7] = rd[j+i] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> c[i][j];
		}
	}

	place(0);
	cout << ans;

	return 0;
}