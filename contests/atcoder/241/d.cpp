#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define len(x) (int)x.size()

typedef long long ll;

ll solve(multiset<ll>& has, ll type, ll x, ll k) {
	bool ok = true;
	multiset<ll>::iterator it;
	if (type == 2) {
		it = has.lower_bound(x+1);
		for (int i = 0; ok && i < k; i++) {
			if (it == has.begin()) {
				ok = false;
			} else {
				it--;
			}
		}
	} else {
		it = has.lower_bound(x);
		if (it == has.end()) ok = false;
		for (int i = 0; ok && i < k - 1; i++) {
			it++;
			if (it == has.end()) ok = false;
		}
	}
	if (ok) {
		return *it;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	multiset<ll> has;
	while (q--) {
		ll type, x, k;
		cin >> type >> x;
		if (type == 2 || type == 3) {
			cin >> k;
			cout << solve(has, type, x, k) << endl;
		} else {
			has.insert(x);
		}
	}
	return 0;
}
