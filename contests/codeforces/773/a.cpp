#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		vector<pair<int, int>> v(3);
		for (int i = 0; i < 3; i++) {
			cin >> v[i].second >> v[i].first;
		}
		sort(begin(v), end(v));
		
		double ans = 0.0;
		if (v[1].first == v[2].first) {
			ans = abs(v[1].second - v[2].second);
		}
		cout << fixed << setprecision(10) << ans << endl;
	}
	return 0;
}
