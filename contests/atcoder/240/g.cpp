#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

vector<ll> fact;

ll gcd(ll a, ll b, ll& x, ll& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return d;
}

ll inverse(ll val) {
	ll x, y;
	gcd(mod, val, x, y);
	y = (y + mod) % mod;
	return y;
}

int main() {
	ios::sync_with_stdio(false);
	ll n, x, y, z;
	cin >> n >> x >> y >> z;
	x = abs(x);
	y = abs(y);
	z = abs(z);
	ll sum = x + y + z;
	if (sum > n || (n - sum) % 2 != 0) {
		cout << "0" << endl;
		return 0;
	}
	fact.assign(n+1, 1);
	for (int i = 2; i <= n; i++) {
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
	}
	ll diff = (n - sum);
	ll div = 1;
	ll mul = 1;
	for (int i = 0; i < diff; i += 2) {
		div *= 2;
		div %= mod;
		
		mul *= 6;
		mul %= mod;
	}
	
	ll ans = fact[n];
	ans *= inverse(fact[x]);
	ans %= mod;
	ans *= inverse(fact[y]);
	ans %= mod;
	ans *= inverse(fact[z]);
	ans %= mod;
	ans *= inverse(fact[diff / 2]);
	ans %= mod;
	/*ans *= inverse(fact[diff / 2]);
	ans %= mod;*/
	ans *= mul;
	ans %= mod;
	
	cout << ans << endl;
	
	return 0;
}
