#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

string s;
int d, n;
vector<vector<ll> > fr;
vector<vector<ll> > stc;

ll solve(int p, int rem, bool free) {
	if (p == n) {
		if (rem == 0) return 1;
		return 0;
	}
	ll& ret = free ? fr[rem][p] : stc[rem][p];
	if (ret != -1) return ret;
	int cur = s[p] - '0';
	ret = 0;
	for (int i = 0; i < 10; i++) {
		if (free || i < cur) {
			ret += solve(p+1, (rem + i) % d, true);
		} else {
			ret += solve(p+1, (rem + i) % d, false);
			break;
		}
		ret %= MOD;
	}
	ret %= MOD;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> s >> d;
	n = s.size();
	fr.assign(d, vector<ll>(n, -1));
	stc.assign(d, vector<ll>(n, -1));
	cout << (solve(0, 0, false) - 1 + MOD) % MOD << endl;
	
	return 0;
}
