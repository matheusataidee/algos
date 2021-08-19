#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<ll> > v(3, vector<ll>(n));
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[j][i];
			if (i) {
				v[j][i] += max(v[(j+1) % 3][i-1], v[(j+2) % 3][i-1]);
			}
			ans = max(ans, v[j][i]);
		}
	}
	cout << ans << endl;
	return 0;
}
