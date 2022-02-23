#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	set<string> express;
	for (string& station : v) cin >> station;
	for (int i = 0; i < m; i++) {
		string station;
		cin >> station;
		express.insert(station);
	}
	for (int i = 0; i < n; i++) {
		if (express.count(v[i])) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
