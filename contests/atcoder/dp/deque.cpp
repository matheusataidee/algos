#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;
vector<ll> acc;
vector<vector<ll> > dp;

ll solve(int a, int b) {
	if (a == b) return v[a];
	if (dp[a][b] != -1) return dp[a][b];
	return dp[a][b] = max(v[a] + (acc[b] - acc[a]) - solve(a+1, b), 
				          v[b] + (acc[b-1] - acc[a-1]) - solve(a, b-1));
}

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	v.assign(n+1, 0);
	acc.assign(n+1, 0);
	dp.assign(n+1, vector<ll>(n+1, -1));
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		acc[i] = acc[i-1] + v[i];
	}
	cout << 2 * solve(1, n) - acc[n] << endl;
	return 0;
}
