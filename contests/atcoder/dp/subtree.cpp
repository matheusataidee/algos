#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll mod;
vector<vector<int>> g;
vector<vector<int>> where;
vector<vector<ll>> dp;
vector<vector<ll>> inc;
vector<vector<ll>> dcc;

ll solve(int y, int x);

ll getDec(int y, int x) {
	if (x < 0) return 1;
	if (dcc[y][x] != -1) return dcc[y][x];
	dcc[y][x] = getDec(y, x-1);
	dcc[y][x] *= solve(y, x);
	dcc[y][x] %= mod;
	return dcc[y][x];
}

ll getInc(int y, int x) {
	if (x >= (int)g[y].size()) return 1;
	if (inc[y][x] != -1) return inc[y][x];
	inc[y][x] = getInc(y, x+1);
	inc[y][x] *= solve(y, x);
	inc[y][x] %= mod;
	return inc[y][x];
}

ll solve(int y, int x) {
	if (dp[y][x] != -1) return dp[y][x];
	int to = g[y][x];
	if (g[to].size() == 1) return 2 % mod;
	dp[y][x] = getDec(to, where[y][x]-1) * getInc(to, where[y][x] + 1);
	dp[y][x]++;
	dp[y][x] %= mod;
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> mod;
	g.assign(n, vector<int>());
	where.assign(n, vector<int>());
	dp.assign(n, vector<ll>());
	inc.assign(n, vector<ll>());
	dcc.assign(n, vector<ll>());
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;	b--;
		where[a].push_back(g[b].size());
		where[b].push_back(g[a].size());
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		dp[i] = vector<ll>(g[i].size(), -1);
		inc[i] = vector<ll>(g[i].size(), -1);
		dcc[i] = vector<ll>(g[i].size(), -1);
	}
	for (int i = 0; i < n; i++) {
		ll total = 1;
		for (int j = 0; j < (int)g[i].size(); j++) {
			total *= solve(i, j);
			total %= mod;
		}
		cout << total << endl;
	}
	return 0;
}
