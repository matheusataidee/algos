#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string expectation;
		cin >> n >> expectation;
		vector<vector<char>> grid(n, vector<char>(n, '='));
		
		vector<int> v;
		for (int i = 0; i < n; i++) {
			grid[i][i] = 'X';
			if (expectation[i] == '2') v.push_back(i);
		}
		int m = v.size();
		if (m && m <= 2) {
			cout << "NO" << endl;
		} else {
			for (int i = 0; i < m; i++) {
				grid[v[i]][v[(i+1) % m]] = '+';
				grid[v[(i+1) % m]][v[i]] = '-';
			}
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << grid[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
