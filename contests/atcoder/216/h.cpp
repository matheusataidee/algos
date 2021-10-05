#include <bits/stdc++.h>

using namespace std;

#define MAXK 1010

typedef long long ll;

const ll mod = 998244353;

vector<ll> inv;
vector<ll> pots;
vector<vector<ll>> dp;
vector<ll> v;
ll n, k;

ll gcd(ll a, ll b, ll& x, ll& y) {
	if (!b) {
		x = 1;
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return d;
}

ll inverse(ll val) {
	ll x, y;
	gcd(mod, val, x, y);
	y = (y + mod) % mod;
	return y;
}

void init() {
	pots = vector<ll>(MAXK * 10);
	inv = vector<ll>(MAXK * 10);
	pots[0] = 1;
	inv[0] = inverse(pots[0]);
	for (int i = 1; i < MAXK * 10; i++) {
		pots[i] = ((ll)2 * pots[i-1]) % mod;
		inv[i] = inverse(pots[i]);
	}
}

ll solve(int dist, int steps) {
	if (dist == 0) return pots[2 * steps];
	if (dist > steps) return 0;
	if (dp[dist][steps] != -1) return dp[dist][steps];
	return dp[dist][steps] = 
	(solve(dist+1, steps-1) + solve(dist-1, steps-1) + 2 * solve(dist, steps-1)) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	init();
	
	cin >> n >> k;
	
	v = vector<ll>(n);
	dp = vector<vector<ll>>(MAXK, vector<ll>(MAXK, -1));
	
	for (ll& x : v) cin >> x;
	sort(begin(v), end(v));
	ll ans = 0;
	
	vector<pair<int, int>> adj;
	for (int i = 0; i < n - 1; i++) {
		adj.push_back({i, i+1});
	}
	
	int adjSz = adj.size();
	int mask = (1 << adjSz) - 1;
	for (int sub = mask; sub; sub=(sub-1)&mask) {
		int bitcount = __builtin_popcount(sub);
		vector<pair<int, int>> chosen;
		int last = -2;
		for (int i = 0; i < adjSz; i++) {
			if ((sub & (1 << i))) {
				if (last == i - 1) {
					chosen[(int)chosen.size() - 1].second = adj[i].second;
				} else {
					chosen.push_back(adj[i]);
				}
				last = i;
			}
		}
		ll cur = 1;
		for (auto cho : chosen) {
			cur *= solve(v[cho.second] - v[cho.first], k);
			cur %= mod;
		}
		cur *= pots[(n - 2 * (int)chosen.size()) * k];
		cur %= mod;
		
		if (bitcount % 2 == 1) {
			ans += cur;
		} else {
			ans += mod - cur;
		}
		ans %= mod;
	}
	ans = (pots[n * k] + mod - ans);
	ans %= mod;
	
	cout << ans << " / " << pots[n * k] << endl;
	cout << (ans * inv[n * k]) % mod << endl;
	return 0;
}
