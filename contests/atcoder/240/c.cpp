#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, X;
vector<int> a, b;
vector<vector<int>> dp;

int solve(int steps_taken, int position) {
	if (steps_taken == n) {
		return position == X;
	}
	if (position > X) {
		return 0;
	}
	if (dp[steps_taken][position] != -1) return dp[steps_taken][position];
	return dp[steps_taken][position] = solve(steps_taken + 1, position + a[steps_taken]) ||
									   solve(steps_taken + 1, position + b[steps_taken]);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> X;
	a = vector<int>(n);
	b = vector<int>(n);
	dp = vector<vector<int>>(n, vector<int>(X+1, -1));
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	cout << vector<string>{"No", "Yes"}[solve(0, 0)] << endl;
	return 0;
}
