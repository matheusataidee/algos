#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		vector<ll> v(n+1), dp(n+1), acc(n+1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = max((ll)0, dp[i-1] + v[i]);
			acc[i] = v[i] + acc[i-1];
			ans = max(ans, dp[i]);
		}
		
		cout << ans << " ";
		for (int k = 1; k <= n; k++) {
			for (int i = k; i <= n; i++) {
				ans = max(ans, acc[i] - acc[i-k] + k * x + dp[i-k]);
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}
