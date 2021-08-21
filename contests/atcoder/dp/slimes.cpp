#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;
vector<ll> acc;
vector<vector<ll> > dp;

ll solve(int a, int b) {
	if (a == b) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	ll c = acc[b] - acc[a-1];
	dp[a][b] = c + solve(a+1, b);
	for (int i = a + 1; i < b; i++) {
		dp[a][b] = min(dp[a][b], c + solve(a, i) + solve(i+1, b));
	}
	return dp[a][b];
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	v = vector<ll>(n+1);
	acc = vector<ll>(n+1);
	dp = vector<vector<ll> >(n+1, vector<ll>(n+1, -1));
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		acc[i] = v[i] + acc[i-1];
	}
	cout << solve(1, n) << endl;
	
	return 0;
}
