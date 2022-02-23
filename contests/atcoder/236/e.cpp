#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;

int n;

double solve(const vector<double>& v) {
	vector<double> dp[2] = {vector<double>(n), vector<double>(n)};
	
	dp[1][0] = v[0];
	dp[0][0] = 0;
	for (int i = 1; i < n; i++) {
		dp[1][i] = v[i] + max(dp[1][i-1], dp[0][i-1]);
		dp[0][i] = dp[1][i-1];
	}
	return max(dp[1][n-1], dp[0][n-1]);
}

double binsearchForAverage(const vector<ll>& v) {
	double l = 0, r = INT_MAX;
	for (int i = 0; i < 300; i++) {
		double mid = (l + r) / 2;
		vector<double> now(n);
		transform(all(v), begin(now), [&] (ll val) { return val - mid; });
		
		if (solve(now) < 0) {
			r = mid;
		} else {
			l = mid;
		}
	}
	return l;
}

ll binsearchForMedian(const vector<ll>& v) {
	ll l = 0, r = INT_MAX;
	while (l < r) {
		ll mid = (l + r) / 2;
		vector<double> now(n);
		transform(all(v), begin(now), 
		 [&] (ll val) {
			 if (val >= mid) {
				 return 1;
			 }
			 return -1;
		 });
		 
		 double ret = solve(now);
		 if (ret <= 0) {
			 r = mid;
		 } else {
			 l = mid + 1;
		 }
	}
	return l - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	vector<ll> v(n);
	for (ll& val : v) cin >> val;
	cout << fixed << setprecision(5) << binsearchForAverage(v) << endl;
	cout << binsearchForMedian(v) << endl;

	return 0;
}
