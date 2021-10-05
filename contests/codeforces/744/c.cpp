#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
vector<string> grid;
vector<vector<bool>> ok;

void solve(int y, int x, int d) {
	for (int i = 1; i <= d; i++) {
		if (y - i < 0 || x - i < 0 || x + i >= m) return;
		if (grid[y-i][x-i] != '*' || grid[y-i][x+i] != '*') return;
	}
	if (grid[y][x] != '*') return;
	
	ok[y][x] = true;
	for (int i = 1; i <= d; i++) {
		ok[y-i][x-i] = ok[y-i][x+i] = true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		
		ok.assign(n, vector<bool>(m, false));
		grid.assign(n, "");
		for (string& row : grid) cin >> row;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int d = k; d <= n; d++) {
					if (grid[i][j] == '*') {
						solve(i, j, d);
					} else {
						ok[i][j] = true;
					}
				}
			}
		}
		bool cond = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!ok[i][j]) cond = false;
			}
		}
		if (cond) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}
	return 0;
}
