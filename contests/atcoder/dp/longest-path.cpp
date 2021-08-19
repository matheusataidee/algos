#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int> > g;
vector<int> dp;

int solve(int p) {
	if (dp[p] != -1) return dp[p];
	dp[p] = 1;
	for (int to : g[p]) {
		dp[p] = max(dp[p], 1 + solve(to));
	}
	return dp[p];
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	g = vector<vector<int> >(n);
	dp = vector<int>(n, -1);
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		from--;	to--;
		g[from].push_back(to);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, solve(i));
	}
	cout << ans - 1<< endl;
	return 0;
}
