#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

vector<int> pred;
vector<vector<int> > g;
vector<ll> white;
vector<ll> black;

ll getWhite(int p);
ll getBlack(int p);

void dfs(int p) {
	for (int to : g[p]) {
		if (to == pred[p]) continue;
		pred[to] = p;
		dfs(to);
	}
}

ll getWhite(int p) {
	if (white[p] != -1) return white[p];
	white[p] = 1;
	for (int to : g[p]) {
		if (to == pred[p]) continue;
		white[p] *= (getWhite(to) + getBlack(to));
		white[p] %= MOD;
	}
	return white[p];
}

ll getBlack(int p) {
	if (black[p] != -1) return black[p];
	black[p] = 1;
	for (int to : g[p]) {
		if (to == pred[p]) continue;
		black[p] *= getWhite(to);
		black[p] %= MOD;
	}
	return black[p];
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	pred.assign(n, -1);
	black.assign(n, -1);
	white.assign(n, -1);
	g.assign(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		from--; to--;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	dfs(0);
	cout << (getBlack(0) + getWhite(0)) % MOD << endl;
	return 0;
}
