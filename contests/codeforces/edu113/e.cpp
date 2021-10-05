#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244352;

ll k, A, h;
vector<int> ans;
int gold, silver;

ll mpow(ll a, ll b) {
	if (!b) return 1;
	if (b % 2 == 0) {
		ll x = mpow(a, b / 2);
		return (x * x) % mod;
	}
	return (a * mpow(a, b - 1)) % mod;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
	if (!b) {
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

bool solve(int p, ll sum, vector<pair<int, int>>& cur, vector<int>& winners, vector<int>& losers) {
	//cout << cur.size() << endl;
	ll n = cur.size();
	if (p == n) {
		ll acc = 0;
		for (int loser : losers) {
			ans[loser] = n + 1;
			acc += mpow(A, n + 1) * loser;
			acc %= mod;
		}
		vector<pair<int, int>> nx;
		vector<int> nwin, nlos;
		for (int i = 0; i < (int)winners.size(); i+=2) {
			nx.push_back({winners[i], winners[i+1]});
		}
		if (solve(0, (sum + acc)%mod, nx, nwin, nlos)) return true;
	} else {
		bool hasGold = cur[p].first == gold || cur[p].second == gold;
		bool hasSilver = cur[p].first == silver || cur[p].second == silver;
		
		if (hasGold && hasSilver) {
			if (n > 1) return false;
		
			ll acc = (sum + mpow(A, 2) * silver) % mod;
			acc += (A * gold) % mod;
			return h == acc;
		} else if (hasGold) {
			winners.push_back(gold);
			losers.push_back(cur[p].first + cur[p].second - gold);
			if (solve(p+1, sum, cur, winners, losers)) return true;
		} else if (hasSilver) {
			winners.push_back(silver);
			losers.push_back(cur[p].first + cur[p].second - silver);
			if (solve(p+1, sum, cur, winners, losers)) return true;
		} else {
			winners.push_back(cur[p].first);
			losers.push_back(cur[p].second);
			if (solve(p+1, sum, cur, winners, losers)) return true;
			
			winners.pop_back();
			losers.pop_back();
			
			winners.push_back(cur[p].second);
			losers.push_back(cur[p].first);
			if (solve(p+1, sum, cur, winners, losers)) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> k >> A >> h;
	
	ans = vector<int>(mpow(2, k) + 1);
	
	// gold = ((h * inverse(A)) % mod) % A;
	// silver = ((h * inverse(mpow(A, 2))) % mod) % A;
	gold = 5;
	silver = 4;
	
	
	cout << gold << " " << silver << endl;
	
	ans[gold] = 1;
	ans[silver] = 2;
	
	vector<pair<int, int>> cur;
	vector<int> losers;
	vector<int> winners;
	for (int i = 1; i < mpow(2, k); i+=2) {
		cur.push_back({i, i+1});
	}
	
	
	if (!solve(0, 0, cur, winners, losers)) {
		cout << "-1" << endl;
	} else {
		for (int i = 1; i <= mpow(2, k); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	
	
	return 0;
}
