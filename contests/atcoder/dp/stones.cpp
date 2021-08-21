#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> v;
vector<int> dp;

int solve(int p) {
	if (p == 0) return 0;
	if (dp[p] != -1) return dp[p];
	dp[p] = 0;
	for (int& x : v) {
		if (p - x < 0) continue;
		if (!solve(p - x)) dp[p] = 1;
	}
	return dp[p];
}

int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	v.assign(n, 0);
	dp.assign(k+1, -1);
	for (int& x : v) cin >> x;
	int win = solve(k);
	if (win) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
	return 0;
}
