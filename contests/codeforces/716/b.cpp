#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll mypow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		ll ret = mypow(a, b / 2);
		return (ret * ret) % mod;
	}
	return (a * mypow(a, b-1)) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		cout << mypow(n, k) << endl;
	}
	return 0;
}
