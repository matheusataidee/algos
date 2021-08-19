#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(int p, vector<int>& dp, vector<int>& v) {
	if (p == 0) return 0;
	if (dp[p] != -1) return dp[p];
	dp[p] = solve(p-1, dp, v) + abs(v[p] - v[p-1]);
	if (p > 1) dp[p] = min(dp[p], solve(p-2, dp, v) + abs(v[p] - v[p-2]));
	return dp[p];
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n), dp(n, -1);
	for (int& x : v) cin >> x;
	cout << solve(n - 1, dp, v) << endl;
	return 0;
}
