#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(k);
	for (int& x : v) {
		cin >> x;
		x--;
	}
	vector<bool> used(n, false);
	v.pop_back();
	for (int x : v) used[x] = true;
	vector<int> ans;
	int cur = 0;
	for (int i = 0; i < k - 1; i++) {
		ans.push_back(v[i]);
		while (cur < v[i] && used[cur]) cur++;
		if (cur < v[i]) {
			ans.push_back(cur);
			used[cur] = true;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (!used[i]) ans.push_back(i);
	}
	for (int x : ans) cout << x+1 << " ";
	cout << endl;
	return 0;
}
