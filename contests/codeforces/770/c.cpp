#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (n % 2 == 1 && k != 1) {
			cout << "NO" << endl;
		} else {
			vector<vector<int>> grid(n, vector<int>(k));
			int val = 1;
			for (int j = 0; j < k; j++) {
				for (int i = 0; i < n; i++) {
					grid[i][j] = val++;
				}
			}
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < k; j++) {
					cout << grid[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}
