#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod;

ll add(ll a, ll b) {
	return (a + b) % mod;
}

ll sub(ll a, ll b) {
	return (a - b + mod) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	ll n;
	cin >> n >> mod;
	vector<ll> dp(n+1);
	vector<ll> acc(n+1);
	vector<ll> diff(n+1, 1);
	acc[1] = dp[1] = 1;
	diff[1] = 0;
	for (int i = 2; i <= n; i++) {
		diff[i] = add(diff[i-1], diff[i]);
		dp[i] = add(acc[i-1], diff[i]);
		for (int j = 2 * i; j <= n; j+=i) {
			diff[j] = add(diff[j], sub(dp[i], dp[i-1]));
		}
		acc[i] = add(acc[i-1], dp[i]);
	}
	
	cout << dp[n] << endl;
	
	return 0;
}
