#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n), b(n);
		for (ll& x : a) cin >> x;
		for (ll& x : b) cin >> x;
		map<pair<ll, ll>, ll> cur;
		cur[{a[0], b[0]}] = 0;
		for (int i = 1; i < n; i++) {
			map<pair<ll, ll>, ll> nxt;
			for (auto it : cur) {
				pair<ll, ll> prev = it.first;
				ll up = prev.first + a[i];
				ll down = prev.second + b[i];
				if (nxt.count({up, down})) {
					nxt[{up, down}] = max(nxt[{up, down}], 
										  cur[prev] + 2 * (a[i] * prev.first) + 2 * (b[i] * prev.second));
				} else {
					nxt[{up, down}] = cur[prev] + 2 * (a[i] * prev.first) + 2 * (b[i] * prev.second);
				}
				
				up = prev.first + b[i];
				down = prev.second + a[i];
				if (nxt.count({up, down})) {
					nxt[{up, down}] = max(nxt[{up, down}], 
										  cur[prev] + 2 * (b[i] * prev.first) + 2 * (a[i] * prev.second));
				} else {
					nxt[{up, down}] = cur[prev] + 2 * (b[i] * prev.first) + 2 * (a[i] * prev.second);
				}
			}
			cur = nxt;
		}
		ll mini = INT_MAX;
		for (auto it : cur) {
			mini = min(mini, it.second);
		}
		ll ans = mini;
		for (int i = 0; i < n; i++) {
			ans += (n - 1) * (a[i] * a[i]);
			ans += (n - 1) * (b[i] * b[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
