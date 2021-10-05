#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int& x : v) cin >> x;
		for (int i = 0; k && i < n - 1; i++) {
			if (v[i] <= k) {
				v[n-1] += v[i];
				k -= v[i];
				v[i] = 0;
			} else {
				v[n-1] += k;
				v[i] -= k;
				k = 0;
			}
		}
		for (int x : v) cout << x << " ";
		cout << endl;
	}
	return 0;
}
