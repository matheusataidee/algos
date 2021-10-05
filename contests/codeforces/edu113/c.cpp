#include <bits/stdc++.h>

using namespace std;

#define MAXN 200200

typedef long long ll;

const ll mod = 998244353 ;

ll fact[MAXN];

void init() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
	}
}

int main() {
	ios::sync_with_stdio(false);
	init();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> v(n);
		map<ll, ll> freq;
		ll maxi = 0;
		for (ll& val : v) {
			cin >> val;
			freq[val]++;
			
			maxi = max(maxi, val);
		}
		if (freq[maxi] > 1) {
			cout << fact[n] << endl;
		} else if (!freq.count(maxi-1)) {
			cout << "0" << endl;
		} else {
			ll b = n - 1 - freq[maxi-1];
			ll ans = 1;
			for (int i = 0; i < b; i++) {
				ans *= (n - i);
				ans %= mod;
			}
			ans *= fact[freq[maxi-1]];
			ans %= mod;
			ans *= freq[maxi-1];
			ans %= mod;
			
			cout << ans << endl;
		}
		
	}
	return 0;
}
