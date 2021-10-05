#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<ll, ll>> v;

ll solve(int p, ll acc, ll pref) {
	if (p < 0) return 0;
	if (v[p].second > v[p].first) {
		return solve(p-1, acc, pref + v[p].second - v[p].first);
	}
	ll diff = v[p].first - v[p].second;
	if (diff >= pref) {
		diff -= pref;
		if (diff > acc) {
			return 1 + acc;
		} else {
			return 1 + diff + solve(p-1, acc-diff, 0);
		}
	}
	return solve(p-1, acc, pref-diff);
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	v = vector<pair<ll, ll>>(n / 2);
	for (int i = 0; i < n / 2; i++) {
		cin >> v[i].first >> v[i].second;
	}
	int trash;
	if (n % 2 == 1) cin >> trash;
	ll ans = 0;
	for (int i = 0; i < n / 2; i++) {
		ans += min(v[i].first, v[i].second);
		ll diff = v[i].second - v[i].first;
		if (diff >= 0) {
			ans += solve(i-1, diff, 0);
		}
	}
	cout << ans << endl;
	return 0;
}
