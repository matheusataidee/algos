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
		map<ll, ll> freq;
		for (int i = 0; i < n; i++) {
			ll val;
			cin >> val;
			freq[val]++;
		}
		for (auto& it : freq) {
			const ll& cur = it.first;
			ll& qnt = it.second;
			ll target = x * cur;
			while (qnt && (freq.count(target) && freq[target] > 0)) {
				qnt--;
				freq[target]--;
			}
		}
		ll ans = 0;
		for (auto& it : freq) {
			ans += it.second;
		}
		cout << ans << endl;
	}
	return 0;
}
