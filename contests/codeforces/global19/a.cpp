#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool isSorted = true;
		ll last = 0;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			if (x < last) isSorted = false;
			last = x;
		}
		if (isSorted) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
