#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll ans = 0;
	for (ll i = 1; i * i <= n; i++) {
		ll x = (n - i * i) / (2 * i);
		x++;
		ans += x;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
