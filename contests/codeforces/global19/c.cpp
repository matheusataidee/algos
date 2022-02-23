#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll simple(ll oddsize, ll sum) {
	return ((oddsize + 1) / 2) + (sum / 2);
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll sum = 0;
		vector<ll> odd, even;
		bool hasExtra = false;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (i == 0 || i == n - 1) continue;
			if (x % 2 == 0) {
				even.push_back(x);
			} else {
				odd.push_back(x);
				if (x > 1) {
					hasExtra = true;
				}
			}
			sum += x;
		}
		if (even.size() > 0) {
			cout << simple(odd.size(), sum) << endl;
		} else if (!hasExtra) {
			cout << "-1" << endl;
		} else if (odd.size() > 2) {
			cout << simple(odd.size(), sum) << endl;
		} else if (odd.size() == 2) {
			cout << 2 + ((sum - 2) / 2) << endl;
		} else {
			cout << "-1" << endl;
		}
	}
	return 0;
}
