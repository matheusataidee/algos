#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

int n, m;
vector<vector<ll>> dp;

ll solve(int p, int k) {
	if (k > p) return 0;
	if (k == 0 || p == 0) return 0;
	if (p == 1 && k == 1) return 1;
	if (dp[p][k] != -1) return dp[p][k];
	return dp[p][k] = (solve(p-1, k-1) + solve(p-1, k) * max(0, (k - ((p - 1) / m)))) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	dp = vector<vector<ll>>(n+1, vector<ll>(n+1, -1));
	for (int i = 1; i <= n; i++) {
		cout << solve(n, i) << endl;
	}
	return 0;
}
