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
		int ans;
		cin >> ans;
		for (int i = 1; i < n; i++) {
			int x; cin >> x;
			ans &= x;
		}
		cout << ans << endl;
	}
	return 0;
}
