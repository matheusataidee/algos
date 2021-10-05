#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		if (r <= 2 * l - 1) {
			cout << r % l << endl;
		} else {
			ll x = r / 2;
			x++;
			cout << r % x << endl;
		}
	}
	return 0;
}
