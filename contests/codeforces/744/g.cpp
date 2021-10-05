#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define LIMIT 2001

int n;
vector<int> v;
map<pair<int, pair<int, int>>, int> dp;

int solve(int a, int b, int p) {
	if (a > LIMIT || b > LIMIT) return LIMIT;
	if (p == n) {
		return a + b;
	}
	if (dp.count({a, {b, p}})) return dp[{a, {b, p}}];
		
	return dp[{a, {b, p}}] = min(solve(a + v[p], max(0, b - v[p]), p+1), 
								 solve(max(0, a - v[p]), b + v[p], p+1));
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		v.assign(n, 0);
		for (int& val : v) cin >> val;
		
		dp.clear();
		cout << solve(0, 0, 0) << endl;
	}
	
	return 0;
}
