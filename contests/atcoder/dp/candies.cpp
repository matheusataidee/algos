#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll solve(vector<ll>& v, int k) {
	int n = v.size();
	vector<ll> dp(k+1);
	vector<ll> last(k+1);
	last[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) last[j] = (last[j] + last[j-1]) % MOD;
		for (int j = 0; j <= k; j++) {
			if (j <= v[i]) {
				dp[j] = last[j];
			} else {
				dp[j] = (last[j] - last[j - v[i] - 1] + MOD) % MOD;
			}
		}
		last = dp;
	}
	return dp[k];
}

int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (ll& x : v) cin >> x;
	cout << solve(v, k) << endl;
	return 0;
}
