#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

int getState(char c) {
	if (c == 'O') return 1;
	if (c == 'X') return 2;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		int n;
		string s;
		cin >> n >> s;
		
		ll ans = 0;
		vector<int> v(n+1), defined(n+1), acc(n+1);
		int hand = getState(s[0]);
		for (int i = 1; i < n; i++) {
			int cur = getState(s[i]);
			v[i] = v[i-1];
			if (cur) {
				if (hand && cur != hand) v[i]++;
				hand = cur;
			}
			ans += v[i];
			ans %= mod;
			
			acc[i] = acc[i-1] + v[i];
			acc[i] %= mod;
		}
		
		defined[n] = n;
		for (int i = n - 1; i >= 0; i--) {
			int cur = getState(s[i]);
			if (cur) {
				defined[i] = i;
			} else {
				defined[i] = defined[i+1];
			}
		}
		
		for (int i = 1; i < n; i++) {
			ll num = n - defined[i];
			/*for (int j = defined[i]; j < n; j++) {
				ans += v[j] - v[defined[i]];
			}*/
			ans += acc[n-1] - acc[defined[i]-1] - num * v[defined[i]];
			ans %= mod;
			ans += mod;
			ans %= mod;
		}
		
		cout << "Case #" << z << ": " << ans << endl;
	}
	return 0;
}
