#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<bool> ok(n, true);
		vector<int> when(n, 0);
		
		queue<pair<int, int>> myq;
		for (int i = 0; i < n; i++) {
			int bit;
			cin >> bit;
			if (!bit) {
				ok[i] = false;
				myq.push({i, 0});
			}
		}
		while (!myq.empty()) {
			int p = myq.front().first;
			int h = myq.front().second;
			myq.pop();
			
			int np = (p + d) % n;
			if (ok[np]) {
				ok[np] = false;
				when[np] = h + 1;
				myq.push({np, h+1});
			}
		}
		bool cond = true;
		int maxi = 0;
		for (int i = 0; cond && i < n; i++) {
			if (ok[i]) cond = false;
			
			maxi = max(maxi, when[i]);
		}
		if (cond) {
			cout << maxi << endl;
		} else {
			cout << "-1" << endl;
		}
	}
	return 0;
}
