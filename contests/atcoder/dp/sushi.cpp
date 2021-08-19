#include <bits/stdc++.h>

using namespace std;

#define MAXN 302

typedef long long ll;

int n;
vector<vector<vector<double> > > dp(MAXN, vector<vector<double> >(MAXN, vector<double>(MAXN, -1.0)));

double solve(int a, int b, int c) {
	if (!a && !b && !c) return 0.0;
	if (a < 0 || b < 0 || b < 0) return 0.0;
	if (dp[a][b][c] > -0.5) return dp[a][b][c];
	int sum = a + b + c;
	double M = 0.0;
	M += ((double)a / (double)n) * solve(a-1, b, c);
	M += ((double)b / (double)n) * solve(a+1, b-1, c);
	M += ((double)c / (double)n) * solve(a, b+1, c-1);
	return dp[a][b][c] = ((double) n / (double)(sum)) * (1.0 + M);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> qnt(4);
	for (int i = 0; i < n; i++) {
		int x;	cin >> x;
		qnt[x]++;
	}
	cout << setprecision(10) << fixed << solve(qnt[1], qnt[2], qnt[3]) << endl;
	return 0;
}
