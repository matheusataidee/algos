#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll mod;
vector<ll> dp;
vector<ll> acc;
vector<ll> last;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> mod;
	dp.assign(n+1, 0);
	acc.assign(n+1, 0);
	last.assign(n+1, 0);
	dp[1] = acc[1] = 1;
	for (ll i = 2; i <= n; i++) {
		//cout << i << endl;
		ll num = i;
		vector<ll> newd;
		newd.push_back(1);
		for (ll div = 2; div * div <= num; div++) {
			if (i % div == 0) {
				newd.push_back(div);
				if (num / div != div) {
					 newd.push_back(num / div);
				 }
			}
		}
		sort(begin(newd), end(newd));
		ll sub = 0;
		for (int j = 0; j < (int)newd.size(); j++) {
			sub += dp[newd[j]] - dp[newd[j]-1];
			sub += mod;
			sub %= mod;
		}
		
		last[i] = last[i-1] + sub;
		dp[i] = last[i];
		dp[i] += acc[i-1];
		acc[i] = acc[i-1] + dp[i];
		last[i] %= mod;
		dp[i] %= mod;
		acc[i] %= mod;
	}
	cout << dp[n] << endl;
	return 0;
}
