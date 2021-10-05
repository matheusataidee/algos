#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	int maxPot = 2048;
	for (int& x : v) {
		cin >> x;
		maxPot = __gcd(maxPot, x);
	}
	int acc = 0;
	for (int& x : v) {
		x /= maxPot;
		acc += x;
	}
	vector<int> dp(acc + 1, 0);
	dp[0] = 1;
	for (int x : v) {
		for (int i = acc-x; i >= 0; i--) {
			if (dp[i]) dp[i+x] = 1;
		}
	}
	if (acc % 2 == 0 && dp[acc / 2]) {
		cout << "1" << endl;
		for (int i = 0; i < n; i++) {
			if (v[i] % 2 == 1) {
				cout << i + 1 << endl;
				break;
			}
		}
	} else {
		cout << "0" << endl;
	}
	
	return 0;
}
