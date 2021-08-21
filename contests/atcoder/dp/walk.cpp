#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;


ll counter = 0;
int n, m;
vector<vector<vector<ll> > > dp;
vector<vector<vector<ll> > > tab;
vector<ll> pots;

int upper_bound(ll target) {
	int b = 0, e = m;
	while (b < e) {
		int mid = (b + e) / 2;
		if (pots[mid] > target) {
			e = mid;
		} else {
			b = mid + 1;
		}
	}
	return b-1;
}

void init() {
	pots.push_back(1);
	while (pots.back() < 1e18) {
		pots.push_back(pots.back() * (ll)2);
	}
}

ll solve(int a, int b, ll k) {
	if (k == 0) {
		if (a == b) return 1;
		return 0;
	}
	int id = upper_bound(k);
	int bit_count = __builtin_popcountll(k);
	if (tab[bit_count][a][b] != -1) return tab[bit_count][a][b];

	tab[bit_count][a][b] = 0;
	for (int i = 0; i < n; i++) {
		tab[bit_count][a][b] += dp[id][a][i] * solve(i, b, k - pots[id]);
		tab[bit_count][a][b] %= MOD;
	}
	return tab[bit_count][a][b];
}

int main() {
	ios::sync_with_stdio(false);
	init();
	ll K;
	m = pots.size();
	cin >> n >> K;
	dp = vector<vector<vector<ll> > >(m, vector<vector<ll> >(n, vector<ll>(n)));
	tab = vector<vector<vector<ll> > >(m, vector<vector<ll> >(n, vector<ll>(n, -1)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dp[0][i][j];
		}
	}
	for (int k = 1; k < m; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int mid = 0; mid < n; mid++) {
					dp[k][i][j] += dp[k-1][i][mid] * dp[k-1][mid][j];
					dp[k][i][j] %= MOD;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += solve(i, j, K);
			ans %= MOD;
		}
	}
	cout << ans << endl;
	
	return 0;
}
