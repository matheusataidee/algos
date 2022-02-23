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
		int mini = INT_MAX;
		int maxi = INT_MIN;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mini = min(mini, x);
			maxi = max(maxi, x);
		}
		cout << maxi - mini << endl;
	}
	return 0;
}
