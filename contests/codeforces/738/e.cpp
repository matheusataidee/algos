#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

typedef long long ll;

struct Interval {
	ll l, r;
};

const int X = 2.1e5;
 
bitset<X> is_prime;
vector<int> pr;
vector<int> mu(X, 0);
 
void init(){
	is_prime.flip();
	is_prime[0] = is_prime[1] = false;
	mu[1] = 1;
	for (int i = 2; i < X; i++){
		if (is_prime[i]) {
			pr.push_back(i);
			mu[i] = -1;
		}
		for (int p : pr){
			if (i * p >= X) break;
			is_prime[i * p] = false;
			if (i % p == 0){
				mu[i * p] = 0;
				break;
			} else {
				mu[i * p] = -mu[i];
			}
		}
	}
}

ll solve(vector<Interval>& v, ll m) {
	int n = (int)v.size();
	vector<ll> last(m+1, 1);
	
	for (int i = 0; i < n; i++) {
		vector<ll> dp(m+1);
		for (int j = 1; j <= m; j++) last[j] = (last[j] + last[j-1]) % MOD;
		for (int j = v[i].l; j <= m; j++) {
			dp[j] = last[j-v[i].l];
			if (j > v[i].r) dp[j] += MOD - last[j - v[i].r - 1];
			dp[j] %= MOD;
		}
		last = dp;
	}
	return last[m];
}

int main() {
	ios::sync_with_stdio(false);
	init();
	ll n, m;
	cin >> n >> m;
	vector<Interval> v(n);
	for (Interval& x : v) cin >> x.l >> x.r;
	
	ll ans = 0;
	for (int d = 1; d <= m; d++) {
		if (!mu[d]) continue;
		vector<Interval> adapted = v;
		for (Interval& x : adapted) {
			x.l = (x.l + d - 1) / d;
			x.r = x.r / d;
		}
		ans += (mu[d] * solve(adapted, m / d) + MOD);
		ans %= MOD;
	}
	
	cout << ans << endl;
	
	
	return 0;
}
