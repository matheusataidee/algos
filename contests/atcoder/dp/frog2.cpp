#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
vector<ll> dp, v;

ll solve(int p) {
	if (p == 0) return 0;
	if (dp[p] != -1) return dp[p];
	dp[p] = INT_MAX;
	for (int i = 1; i <= k; i++) {
		int from = p - i;
		if (from < 0) break;
		dp[p] = min(dp[p], solve(from) + abs(v[p] - v[from]));
	}
	return dp[p];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	dp = vector<ll>(n, -1);
	v = vector<ll>(n);
	for (ll& x : v) cin >> x;
	cout << solve(n - 1) << endl;
	
	return 0;
}
