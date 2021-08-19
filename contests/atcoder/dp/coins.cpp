#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<double> > dp;
vector<double> prob;

double solve(int p, int q) {
	if (p < 0 || q < 0) return 0.0;
	if (dp[p][q] > -0.5) return dp[p][q];
	double pr = prob[p + q - 1];
	return dp[p][q] = pr * solve(p-1, q) + (1.0 - pr) * solve(p, q-1);
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	prob = vector<double>(n);
	dp = vector<vector<double> >(n+1, vector<double>(n+1, -1.0));
	for (double& p : prob ) cin >> p;
	dp[0][0] = 1.0;
	double ans = 0.0;
	for (int i = 1; i <= n; i++) {
		if (i > (n - i)) {
			ans += solve(i, n - i);
		}
	}
	cout << setprecision(10) << fixed << ans << endl;
	
	return 0;
}
