#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> v(n);
	for (ll& val : v) cin >> val;
	sort(begin(v), end(v));
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		ans *= (v[i] - i);
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
