#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n+1, 1);
		for (int i = 0; i < n; i++) cin >> v[i];
		if (accumulate(begin(v), end(v), 0) == n + 1) {
			cout << n + 1 << " ";
			for (int i = 1; i <= n; i++) cout << i << " ";
			cout << endl;
			continue;
		}
		bool done = false;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << " ";
			if (!done) {
				if (v[i] == 0 && v[i+1] == 1) {
					cout << n + 1 << " ";
					done = true;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
