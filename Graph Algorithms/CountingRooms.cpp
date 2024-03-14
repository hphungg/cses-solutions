#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1010][1010];
bool visited[1010][1010];

int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};

bool isInside(int i, int j) {
	return (i > 0 && i <= n && j > 0 && j <= m);
}

void visit(int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int _i = i + dirX[k];
		int _j = j + dirY[k];
		if (a[_i][_j] == '.' && !visited[_i][_j] && isInside(_i, _j)) {
			visit(_i, _j);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int rooms = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '.' && !visited[i][j]) {
				rooms++;
				visit(i, j);
			}
		}
	}
	cout << rooms;
	return 0;
}