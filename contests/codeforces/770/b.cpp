#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll n, x, y;
		cin >> n >> x >> y;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			ll val;
			cin >> val;
			sum += val;
		}
		if ((x + sum) % 2 == y % 2) {
			cout << "Alice" << endl;
		} else {
			cout << "Bob" << endl;
		}
	}
	return 0;
}
