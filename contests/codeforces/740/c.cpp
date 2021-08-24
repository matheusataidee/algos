#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(vector<pair<int, int>>& v) {
	int req = -1;
	int acc = 0;
	int n = v.size();
	for (int i = 0; i < n; i++) {
		req = max(req, v[i].first - acc);
		acc += v[i].second;
	}
	return req;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			vector<pair<int, int>> w(m);
			for (int j = 0; j < m; j++) {
				cin >> w[j].first;
				w[j].second = 1;
			}
			v[i] = {solve(w), m};
		}
		sort(begin(v), end(v));
		cout << solve(v) + 1 << endl;
	}
	
	return 0;
}
