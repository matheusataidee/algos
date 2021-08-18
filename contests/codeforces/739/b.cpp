#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int mini = min(a, b), maxi = max(a, b);
		int n = (maxi - mini) * 2;
		if (c > n || a > n || b > n) {
			cout << "-1" << endl;
		} else {
			cout << ((c - 1 + n / 2) % n) + 1 << endl;
		}
	}
	return 0;
}
