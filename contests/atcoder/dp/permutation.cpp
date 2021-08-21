#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int n;
string s;
vector<vector<ll> > dp;
vector<vector<ll> > acc;

ll getAcc(int p, int above);
ll solve(int p, int above);

ll getAcc(int p, int above) {
	if (above < 0) return 0;
	if (acc[p][above] != -1) return acc[p][above];
	return acc[p][above] = (getAcc(p, above-1) + solve(p, above)) % MOD;
}

ll solve(int p, int above) {
	if (p == n - 1) return 1;
	if (dp[p][above] != -1) return dp[p][above];
	int bellow = n - (p + 1) - above;
	if (s[p] == '>') {
		dp[p][above] = getAcc(p+1, above + bellow - 1) - getAcc(p+1, above - 1);
	} else if (s[p] == '<') {
		dp[p][above] = getAcc(p+1, above-1);
	}
	dp[p][above] += MOD;
	dp[p][above] %= MOD;
	return dp[p][above];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> s;
	dp = vector<vector<ll> >(n, vector<ll>(n, -1));
	acc = vector<vector<ll> >(n, vector<ll>(n, -1));
	cout << getAcc(0, n-1) << endl;
	return 0;
}
