#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll X = 1e5 + 1;

int main() {
	ios::sync_with_stdio(false);
	int n, W;
	cin >> n >> W;
	vector<ll> dp(X, 1e12);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		ll w, val;
		cin >> w >> val;
		for (int j = X - 1 - val; j >= 0; j--) {
			dp[j + val] = min(dp[j + val], dp[j] + w);
		}
	}
	ll ans = 0;
	for (int i = X - 1; !ans && i >= 0; i--) {
		if (dp[i] <= W) ans = i;
	}
	cout << ans << endl;
	return 0;
}
