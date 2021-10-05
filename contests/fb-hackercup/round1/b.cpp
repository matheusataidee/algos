#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;

		bool possible = true;
		if (n + m - 1 > a || n + m - 1 > b) possible = false;
		
		cout << "Case #" << z << ": ";
		if (possible) {
			cout << "Possible" << endl;
			vector<vector<int>> grid(n, vector<int>(m, 1));
			grid[0][0] += a - (n + m - 1);
			grid[0][m-1] += b - (n + m - 1);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (j) cout << " ";
					cout << grid[i][j];
				}
				cout << endl;
			}
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
