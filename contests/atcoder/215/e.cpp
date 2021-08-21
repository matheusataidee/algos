#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

typedef long long ll;

int n;
string s;
vector<vector<vector<ll> > > dp;

ll solve(int last, int mask, int p) {
	if (p == n) return 1;
	if (dp[last][mask][p] != -1) return dp[last][mask][p];
	int cur = s[p] - 'A';
	dp[last][mask][p] = solve(last, mask, p+1);
	if (cur == last) {
		dp[last][mask][p] += solve(last, mask, p+1);
	} else {
		if ((mask & (1 << cur)) == 0) {
			dp[last][mask][p] += solve(cur, mask | (1 << cur), p+1);
		}
	}
	dp[last][mask][p] %= MOD;
	return dp[last][mask][p];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> s;
	dp = vector<vector<vector<ll> > >(11, vector<vector<ll> >((1 << 10), vector<ll>(n, -1)));
	cout << (solve(10, 0, 0) + MOD - 1) % MOD << endl;
	return 0;
}
