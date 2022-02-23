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
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			v[i].second = i;
			cin >> v[i].first;
		}
		sort(begin(v), end(v));
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			int l = 0, r = ans.size();
			while (l < r) {
				int mid = (l + r) / 2;
				if (ans[mid] > v[i].second) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			if (l == (int)ans.size()) {
				ans.push_back(v[i].second);
			} else {
				ans[l] = ans.back();
				while ((int)ans.size() > l + 1) {
					ans.pop_back();
				}
			}
		}
		cout << ans.size() << endl;
	}
	return 0;
}
