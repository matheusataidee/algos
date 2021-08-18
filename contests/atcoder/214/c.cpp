#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<ll> s(n), t(n);
	for (ll& val : s) cin >> val;
	for (ll& val : t) cin >> val;
	for (int i = n - 2; i >= 0; i--) s[i] += s[i+1];
	ll tim = t[0];
	for (int i = 1; i < n; i++) {
		tim = min(tim, t[i] + s[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i) {
			tim = min(tim + s[i-1] - s[i], t[i]);
		}
		cout << tim << endl;
	}
	
	return 0;
}
