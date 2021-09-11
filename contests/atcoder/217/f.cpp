#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

vector<vector<bool>> ok;
vector<vector<ll>> dp;
vector<vector<ll>> sec;

ll calc(ll a, ll b) {
	if (a < 0 || b < 0) return 0;
	if (b == 0) return 1;
	if (a == 0) return b + 1;
	if (sec[a][b] != -1) return sec[a][b];
	return sec[a][b] = (calc(a-1, b) + calc(a, b-1)) % mod;
}

ll solve(int a, int b) {
	if (a > b) return 1;
	if (dp[a][b] != -1) return dp[a][b];
	dp[a][b] = 0;
	for (int i = a + 1; i <= b; i+=2) {
		if (ok[a][i]) {
			ll num = calc((i - a - 1) / 2, (b - i) / 2);
			num *= solve(a+1, i-1);
			num %= mod;
			num *= solve(i+1, b);
			num %= mod;
			
			dp[a][b] += num;
			dp[a][b] %= mod;
		}
	}
	return dp[a][b];
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	ok = vector<vector<bool>>(2 * n + 1, vector<bool>(2 * n + 1, false));
	dp = vector<vector<ll>>(2 * n + 1, vector<ll>(2 * n + 1, -1));
	sec = vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		ok[a][b] = ok[b][a] = true;
	}
	cout << solve(1, 2 * n) << endl;
	
	return 0;
}
