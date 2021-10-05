#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bestSkipK(ll num, ll k) {
	return (num * (num+1) / 2) - (k * (k+1) / 2);
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll k;
	cin >> k;
	vector<ll> v(n);
	for (ll& val : v) cin >> val;
	v.push_back(0);
	sort(begin(v), end(v));
	ll acc = 0;
	ll cur = v.back();
	ll ans = 0;
	for (int i = n; k && i >= 0; i--) {
		if (v[i] != cur) {
			if (k >= acc * (cur - v[i])) {
				ans += acc * bestSkipK(cur, v[i]);
				k -= acc * (cur - v[i]);
			} else {
				ll div = k / (acc);
				ans += acc * bestSkipK(cur, cur - div);
				k -= acc * (div);
				ans += k * (cur - div);
				k = 0;
			}
		}
		cur = v[i];
		acc++;
	}
	cout << ans << endl;
	return 0;
}
