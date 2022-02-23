#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;
vector<vector<ll>> mex;
vector<vector<ll>> dp;

ll getMex(int a, int b) {
	if (mex[a][b] != -1) return mex[a][b];
	set<ll> exists;
	for (int i = 0; i < (b - a + 1); i++) {
		exists.insert(i);
	}
	for (int i = a; i <= b; i++) {
		if (exists.count(v[i])) {
			exists.erase(v[i]);
		}
	}
	if (exists.empty()) {
		return b - a + 1;
	}
	auto it = exists.begin();
	return mex[a][b] = *it;
}

ll solve(int a, int b) {
	if (a > b) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	dp[a][b] = 0;
	for (int i = a; i <= b; i++) {
		dp[a][b] = max(dp[a][b], 1 + getMex(a, i) + solve(i+1, b));
	}
	return dp[a][b];
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		v = vector<ll>(n);
		mex = vector<vector<ll>>(n, vector<ll>(n, -1));
		dp = vector<vector<ll>>(n, vector<ll>(n, -1));
		
		for (ll& val : v) cin >> val;
		
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				ans += solve(i, j);
			}
		}
		cout << ans << endl;
		
	}
	return 0;
}
