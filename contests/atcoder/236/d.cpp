#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<vector<ll>> affinity;

void solve(ll state, ll cur, ll& ans) {
	if (state == ((1 << (2 * n)) - 1)) {
		ans = max(ans, cur);
	} else {
		for (int i = 0; i < 2 * n; i++) {
			if (state & (1 << i)) continue;
			for (int j = i + 1; j < 2 * n; j++) {
				if (state & (1 << j)) continue;
				solve(state | (1 << i) | (1 << j), cur ^ affinity[i][j], ans);
			}
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	affinity.assign(2 * n, vector<ll>(2 * n));
	for (int i = 0; i < 2 * n; i++) {
		for (int j = i + 1; j < 2 * n; j++) {
			cin >> affinity[i][j];
		}
	}
	
	ll ans = 0;
	ll cur = 0;
	ll state = 0;
	solve(state, cur, ans);
	cout << ans << endl;
	
	return 0;
}
