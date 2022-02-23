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
		set<int> diffs;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			diffs.insert(x);
		}
		for (int i = 1; i <= n; i++) {
			cout << max((int)diffs.size(), i) << " ";
		}
		cout << endl;
	}
	return 0;
}
