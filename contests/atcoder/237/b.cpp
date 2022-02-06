#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (auto& row : g) {
		for (auto& element : row) {
			cin >> element;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j) cout << " ";
			cout << g[j][i];
		}
		cout << endl;
	}
	return 0;
}
