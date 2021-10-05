#include <bits/stdc++.h>

using namespace std;

#define MAXN 5050

typedef long long ll;

const ll mod = 998244353;

vector<pair<ll, ll>> v;
vector<vector<ll>> dp;

ll solve(ll target, int p) {
	if (target < 0) return 0;
	if (p < 0) {
		return 1;
	}
	if (dp[target][p] != -1) return dp[target][p];
	return dp[target][p] = (solve(target - v[p].second, p - 1) + solve(target, p - 1)) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	v = vector<pair<ll, ll>>(n);
	for (int i = 0; i < n; i++) cin >> v[i].first;
	for (int i = 0; i < n; i++) cin >> v[i].second;
	
	dp = vector<vector<ll>>(MAXN, vector<ll>(MAXN, -1));
	
	sort(begin(v), end(v));
	
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += solve(v[i].first - v[i].second, i - 1);
		ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}
