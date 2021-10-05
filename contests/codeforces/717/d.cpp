#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100
#define MAXSTEPS 20

typedef long long ll;

vector<int> getPrimeDivs(int num) {
	vector<int> primes;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			primes.push_back(i);
			while (num % i == 0) num /= i;
		}
	}
	if (num > 1) primes.push_back(num);
	return primes;
}

int main() {
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	vector<int> last(MAXN, n);
	vector<vector<int>> dp(MAXSTEPS, vector<int>(n+1, n));
	for (int& x : v) cin >> x;
	for (int i = n - 1; i >= 0; i--) {
		vector<int> primeDivs = getPrimeDivs(v[i]);
		int mini = n;
		for (int div : primeDivs) {
			mini = min(mini, last[div]);
			last[div] = i;
		}
		dp[0][i] = min(mini, dp[0][i+1]);
	}
	for (int i = 1; i < MAXSTEPS; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i-1][dp[i-1][j]];
		}
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;	r--;
		int ans = 0;
		for (int j = MAXSTEPS - 1; j >= 0; j--) {
			if (dp[j][l] <= r) {
				ans += (1 << j);
				l = dp[j][l];
			}
		}
		cout << ans+1 << endl;
	}
	
	
	return 0;
}
