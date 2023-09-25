#include <bits/stdc++.h>
using namespace std;

bool onPath[10][10];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int p[50];

int tryPath(int indx, int x, int y) {

	if (x == 7 && y == 1) {
		if (indx == 48) return 1;
		return 0;
	}

	if ((onPath[x][y - 1] && onPath[x][y + 1]) && (!onPath[x - 1][y] && !onPath[x + 1][y])) {
		return 0;
	}

	if ((onPath[x - 1][y] && onPath[x + 1][y]) && (!onPath[x][y - 1] && !onPath[x][y + 1])) {
		return 0;
	}

	if (indx == 48) return 0;

	int ans = 0;
	onPath[x][y] = true;

	if (p[indx] < 4) {
		int new_x = x + dx[p[indx]];
		int new_y = y + dy[p[indx]];
		if (!onPath[new_x][new_y]) ans += tryPath(indx + 1, new_x, new_y);
	} else {
		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (onPath[new_x][new_y]) continue;
			ans += tryPath(indx + 1, new_x, new_y);
		}
	}

	onPath[x][y] = false;
	return ans;
}

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < 48; i++) {
		if (s[i] == 'U') p[i] = 0;
		else if (s[i] == 'R') p[i] = 1;
		else if (s[i] == 'D') p[i] = 2;
		else if (s[i] == 'L') p[i] = 3;
		else p[i] = 4;
	}

	for (int i = 0; i < 9; i++) {
		onPath[0][i] = onPath[8][i] = onPath[i][0] = onPath[i][8] = true;
	}

	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			onPath[i][j] = false;
		}
	}

	cout << tryPath(0, 1, 1);
	return 0;
}