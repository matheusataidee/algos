#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;

int solveDown(vector<string> grid, int n_moves) {
	int ret = m;
	for (int r = 0; r <= n_moves; r++) {
		int qnt = 0;
		for (int j = 0; j < m; j++) {
			if (grid[k][j] == 'X') qnt++;
		}
		ret = min(ret, qnt + r);
		
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'X') {
					if (grid[i+1][j] == '.') {
						grid[i+1][j] = 'X';
						grid[i][j] = '.';
					}
				}
			}
		}
	}
	return ret;
}

int solveUp(vector<string> grid, int n_moves) {
	int ret = m;
	for (int r = 0; r <= n_moves; r++) {
		int qnt = 0;
		for (int j = 0; j < m; j++) {
			if (grid[k][j] == 'X') qnt++;
		}
		ret = min(ret, qnt + r);
		
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'X') {
					if (grid[i-1][j] == '.') {
						grid[i-1][j] = 'X';
						grid[i][j] = '.';
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;
		k--;
		vector<string> grid(n);
		for (string& row : grid) cin >> row;
		
		int ans = m;
		ans = min(ans, solveDown(grid, min(n, m)));
		ans = min(ans, solveUp(grid, min(n, m)));
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
