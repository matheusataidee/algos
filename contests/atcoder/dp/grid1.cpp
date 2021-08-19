#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

vector<string> grid;
vector<vector<ll> > dp;

ll solve(int y, int x) {
	if (y < 0 || x < 0) return 0;
	if (grid[y][x] == '#') return 0;
	if (dp[y][x] != -1) return dp[y][x];
	return dp[y][x] = (solve(y-1, x) + solve(y, x-1)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	grid = vector<string>(h);
	dp = vector<vector<ll> >(h, vector<ll>(w, -1));
	for (string& s : grid) cin >> s;
	dp[0][0] = 1;
	cout << solve(h-1, w-1) << endl;
	
	return 0;
}
