#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int n;
vector<ll> dp;
vector<vector<ll> > g;

ll solve(int mask) {
	int p = __builtin_popcount(mask);
	if (p == n) return 1;
	if (dp[mask] != -1) return dp[mask];
	dp[mask] = 0;
	for (int to : g[p]) {
		if ((mask & (1 << to)) == 0) {
			dp[mask] += solve(mask | (1 << to));
			dp[mask] %= MOD;
		}
	}
	return dp[mask];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	dp.assign((1 << n), -1);
	g.assign(n, vector<ll>());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;	cin >> x;
			if (x) g[i].push_back(j);
		}
	}
	cout << solve(0) << endl;
	
	return 0;
}
