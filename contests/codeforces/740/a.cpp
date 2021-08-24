#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool ok(vector<int>& v) {
	int n = v.size();
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i-1]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int& val : v) cin >> val;
		int ans;
		for (ans = 0; ; ans++) {
			if (ok(v)) break;
			for (int i = 0; i < n - 1; i++) {
				if (ans % 2 == i % 2) {
					if (v[i+1] < v[i]) {
						swap(v[i+1], v[i]);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
