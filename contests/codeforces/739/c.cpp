#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		ll k; cin >> k;
		ll sq = sqrt(k);
		k -= sq * sq;
		if (k == 0) {
			cout << sq << " 1" << endl;
		} else if (k <= sq + 1) {
			cout << k << " " << sq + 1 << endl;
		} else {
			k -= sq + 1;
			cout << sq + 1 << " " << sq + 1 - k << endl;
		}
 	}
	return 0;
}
