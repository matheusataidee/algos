#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> ans(n+1, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans[x] = i + 1;
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
