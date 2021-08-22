#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> cost;
vector<ll> dp;
vector<bool> used;
vector<vector<ll>> g;

void calcCost() {
	for (int i = 0; i < (1 << n); i++) {
		vector<int> members;
		for (int member = 0; member < n; member++) if ((i & (1 << member))) members.push_back(member);
		int m = members.size();
		for (int j = 0; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				cost[i] += g[members[j]][members[k]];
			}
		}
	}
}

ll solve(int mask) {
	if (__builtin_popcount(mask) == n) return 0;
	if (used[mask]) return dp[mask];
	int nei_mask = ((1 << n) - 1) ^ mask;
	dp[mask] = -1e12;
	for (int sub = nei_mask; sub; sub = (sub-1) & nei_mask) {
		dp[mask] = max(dp[mask], cost[sub] + solve(mask | sub));
	}
	used[mask] = true;
	return dp[mask];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	cost.assign((1 << n), 0);
	dp.assign((1 << n), 0);
	used.assign((1 << n), false);
	g.assign(n, vector<ll>(n));
	for (auto& v : g) for (auto& val : v) cin >> val;
	calcCost();
	
	cout << solve(0) << endl;
	return 0;
}
