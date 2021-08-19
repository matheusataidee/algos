#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<int> > dp;
string s, t;

int solve(int p, int q) {
	if (p == n || q == m) return 0;
	if (dp[p][q] != -1) return dp[p][q];
	if (s[p] == t[q]) return dp[p][q] = 1 + solve(p+1, q+1);
	return dp[p][q] = max(solve(p+1, q), solve(p, q+1));
}

int main() {
	ios::sync_with_stdio(false);
	cin >> s >> t;
	n = s.size();	 m = t.size();
	dp = vector<vector<int> >(n, vector<int>(m, -1));
	solve(0, 0);
	int p = 0, q = 0;
	string ans = "";
	while (p < n && q < m) {
		if (s[p] == t[q]) {
			ans += s[p];
			p++;	q++;
		} else {
			if (solve(p+1, q) > solve(p, q+1)) {
				p++;
			} else {
				q++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
