#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

int minDist(vector<int>& v, int& p, int target) {
	for (int i = 0; i < n; i++) {
		if (v[(p+i) % n] == target) {
			p = (p + i) % n;
			return i;
		}
		if (v[(p + n - i) % n] == target) {
			p = (p + n - i) % n;
			return i;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<int> v(n), target(m);
	bool vContains[2] = {false, false};
	bool tContains[2] = {false, false};
	for (int& x : v) {
		cin >> x;
		vContains[x] = true;
	}
	for (int& x : target) {
		cin >> x;
		tContains[x] = true;
	}
	if ((tContains[0] && !vContains[0]) || (tContains[1] && !vContains[1])) {
		cout << "-1" << endl;
	} else {
		int p = 0;
		int ans = 0;
		for (int i = 0; i < m; i++) {
			ans += minDist(v, p, target[i]);
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
