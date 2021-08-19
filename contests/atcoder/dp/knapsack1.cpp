#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Item {
	ll w, val;
};

vector<Item> v;
vector<vector<ll> > dp;

ll solve(int p, int w) {
	if (p < 0) return 0;
	if (dp[p][w] != -1) return dp[p][w];
	dp[p][w] = solve(p-1, w);
	if (v[p].w <= w) {
		dp[p][w] = max(dp[p][w], v[p].val + solve(p-1, w - v[p].w));
	}
	return dp[p][w];
}

int main() {
	ios::sync_with_stdio(false);
	int n, W;
	cin >> n >> W;
	v = vector<Item>(n);
	dp = vector<vector<ll> >(n, vector<ll>(W+1, -1));
	for (Item& item : v) cin >> item.w >> item.val;
	cout << solve(n - 1, W) << endl;
	return 0;
}
