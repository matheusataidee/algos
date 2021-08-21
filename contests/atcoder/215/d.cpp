#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int X = 2.1e5;

int main() {
	ios::sync_with_stdio(false);
	bitset<X> used;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll num; cin >> num;
		for (ll i = 2; i * i <= num; i++) {
			while (num % i == 0) {
				used[i] = 1;
				num /= i;
			}
		}
		if (num > 1) used[num] = 1;
	}
	vector<int> ans;
	for (int i = 1; i <= m; i++) {
		ll num = i;
		bool ok = true;
		for (ll i = 2; ok && i * i <= num; i++) {
			while (num % i == 0) {
				if (used[i]) ok = false;
				num /= i;
			}
		}
		if (num > 1 && used[num]) ok = false;
		if (ok) ans.push_back(i);
	}
	cout << ans.size() << endl;;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
